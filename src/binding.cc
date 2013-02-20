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

class Listener : public fit::FileIdMesgListener, public fit::UserProfileMesgListener, public fit::ActivityMesgListener
{
   public :
      void OnMesg(fit::FileIdMesg& mesg)
      {
         printf("File ID:\n");
         if (mesg.GetType() != FIT_FILE_INVALID)
            printf("   Type: %d\n", mesg.GetType());
         if (mesg.GetManufacturer() != FIT_MANUFACTURER_INVALID)
            printf("   Manufacturer: %d\n", mesg.GetManufacturer());
         if (mesg.GetProduct() != FIT_UINT16_INVALID)
            printf("   Product: %d\n", mesg.GetProduct());
         if (mesg.GetSerialNumber() != FIT_UINT32Z_INVALID)
            printf("   Serial Number: %d\n", mesg.GetSerialNumber());
         if (mesg.GetNumber() != FIT_UINT16_INVALID)
            printf("   Number: %d\n", mesg.GetNumber());
      }

      void OnMesg(fit::UserProfileMesg& mesg)
      {
         printf("UserProfileMesg:\n");
         if (mesg.GetFriendlyName() != FIT_WSTRING_INVALID)
            std::wcout << L"   Friendly Name: " << mesg.GetFriendlyName().c_str() << L"\n";
         if (mesg.GetGender() == FIT_GENDER_MALE)
            printf("   Gender: Male\n");
         if (mesg.GetGender() == FIT_GENDER_FEMALE)
            printf("   Gender: Female\n");
         if (mesg.GetAge() != FIT_UINT8_INVALID)
            printf("   Age [years]: %d\n", mesg.GetAge());
         if (mesg.GetWeight() != FIT_FLOAT32_INVALID)
            printf("   Weight [kg]: %0.2f\n", mesg.GetWeight());
      }

      void OnMesg(fit::ActivityMesg& mesg)
      {
         printf("Activity:\n");
         if (mesg.GetEvent() != FIT_EVENT_INVALID)
            printf("   Event: %d\n", mesg.GetEvent());
         if (mesg.GetTotalTimerTime() != FIT_FLOAT32_INVALID)
            printf("   Total Timer Time: %f\n");
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

   mesgBroadcaster.AddListener((fit::FileIdMesgListener &)listener);
   mesgBroadcaster.AddListener((fit::UserProfileMesgListener &)listener);
   mesgBroadcaster.AddListener((fit::ActivityMesgListener &)listener);

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