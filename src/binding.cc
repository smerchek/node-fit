#include <string>
#include <string.h>
#include <node.h>
#include <v8.h>

#include <fstream>
#include <iostream>

#include "../libfit/fit_decode.hpp"
#include "../libfit/fit_mesg_broadcaster.hpp"

using namespace std;
using namespace v8;

class Listener : public fit::MesgListener
{
   public :
      void OnMesg(fit::Mesg& mesg)
      {
         printf("Message [%s]:\n", mesg.GetName());
         for (int i = 0; i < mesg.GetNumFields(); i++) {
            fit::Field* field = mesg.GetFieldByIndex(i);
            int subFieldIndex = mesg.GetActiveSubFieldIndex((*field).GetNum());
            std::cout << "   Name : " << (*field).GetName(subFieldIndex) << std::endl;
            std::wstring value = (*field).GetSTRINGValue(0, subFieldIndex);

            for (int fieldElement = 1; fieldElement < (*field).GetNumValues(); fieldElement++) {
               value += L"|";

               std::wstring nextValue = (*field).GetSTRINGValue(fieldElement, subFieldIndex);
               value += nextValue;
            }

            std::wcout << "   Value : " << value << std::endl;
            std::cout << "   Units : " << (*field).GetUnits(subFieldIndex) << std::endl;
         }
      }
};

Handle<Value> Decode(const Arguments& args) {
   HandleScope scope;
   fit::Decode decode;
   fit::MesgBroadcaster mesgBroadcaster;
   Listener listener;
   std::fstream file;
   if (args.Length() < 1) {
      ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
      return scope.Close(Undefined());
   }

   if (!args[0]->IsString()) {
      ThrowException(Exception::TypeError(String::New("Wrong arguments")));
      return scope.Close(Undefined());
   }

   String::Utf8Value fileName(args[0]->ToString());
   
   file.open(strdup(*fileName), std::ios::in | std::ios::binary);

   if (!file.is_open())
   {
      ThrowException(Exception::TypeError(String::New("Error opening file.")));
      return scope.Close(Undefined());
   }

   if (!decode.CheckIntegrity(file))
   {
      ThrowException(Exception::TypeError(String::New("FIT file integrity failed.")));
      return scope.Close(Undefined());
   }

   mesgBroadcaster.AddListener((fit::MesgListener &)listener);

   try
   {
      mesgBroadcaster.Run(file);
   }
   catch (const fit::RuntimeException& e)
   {
      ThrowException(Exception::TypeError(String::New("Exception while decoding file.")));
      return scope.Close(Undefined());
   }

   return scope.Close(String::New(*fileName));
}

void init(Handle<Object> target) {
   NODE_SET_METHOD(target, "decode", Decode);
}

NODE_MODULE(binding, init);