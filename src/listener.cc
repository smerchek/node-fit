#include <string>
#include <string.h>
#include <node.h>
#include <v8.h>

#include <fstream>
#include <iostream>
#include "listener.h"
#include "../libfit/fit_decode.hpp"
#include "../libfit/fit_mesg_broadcaster.hpp"

using namespace std;

Listener::Listener (const Arguments& args) {
   self = args.This();
}

void Listener::OnMesg(fit::Mesg& mesg) {
   //printf("Message [%s]:\n", mesg.GetName());
   for (int i = 0; i < mesg.GetNumFields(); i++) {
      fit::Field* field = mesg.GetFieldByIndex(i);
      int subFieldIndex = mesg.GetActiveSubFieldIndex((*field).GetNum());
      //std::cout << "   Name : " << (*field).GetName(subFieldIndex) << std::endl;
      std::wstring value = (*field).GetSTRINGValue(0, subFieldIndex);

      for (int fieldElement = 1; fieldElement < (*field).GetNumValues(); fieldElement++) {
         value += L"|";

         std::wstring nextValue = (*field).GetSTRINGValue(fieldElement, subFieldIndex);
         value += nextValue;
      }

      //std::wcout << "   Value : " << value << std::endl;
      //std::cout << "   Units : " << (*field).GetUnits(subFieldIndex) << std::endl;

      Handle<Value> argv[2] = {
         String::New("message"), // event name
         String::New(mesg.GetName().c_str())  // argument
      };

      MakeCallback(self, "emit", 2, argv);
   }
}
