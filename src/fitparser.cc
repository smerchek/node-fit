#include <string>
#include <string.h>
#include <node.h>
#include <v8.h>

#include <fstream>
#include <iostream>

#include "fitparser.h"
#include "listener.h"
#include "../libfit/fit_decode.hpp"
#include "../libfit/fit_mesg_broadcaster.hpp"

using namespace std;
using namespace v8;
using namespace node;

FitParser::FitParser() {};
FitParser::~FitParser() {};

void FitParser::Init(Handle<Object> target) {
   // Prepare constructor template
   Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
   tpl->SetClassName(String::NewSymbol("FitParser"));
   tpl->InstanceTemplate()->SetInternalFieldCount(1);
   // Prototype
   tpl->PrototypeTemplate()->Set(String::NewSymbol("decode"),
      FunctionTemplate::New(Decode)->GetFunction());

   Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
   target->Set(String::NewSymbol("FitParser"), constructor);
}

Handle<Value> FitParser::New(const Arguments& args) {
   HandleScope scope;

   assert(args.IsConstructCall());
   FitParser* self = new FitParser();
   self->Wrap(args.This());

   return args.This();
}

Handle<Value> FitParser::Decode(const Arguments& args) {
   HandleScope scope;
   fit::Decode decode;
   fit::MesgBroadcaster mesgBroadcaster;
   Listener* listener = new Listener(args);
   std::fstream file;

   if (args.Length() < 1) {
      Handle<Value> argv[2] = {
       String::New("error"), // event name
       Exception::TypeError(String::New("Wrong number of arguments"))  // argument
      };

      MakeCallback(args.This(), "emit", 2, argv);
      return scope.Close(Undefined());
   }

   if (!args[0]->IsString()) {
      Handle<Value> argv[2] = {
       String::New("error"), // event name
       Exception::TypeError(String::New("Argument must be a string."))  // argument
      };

      MakeCallback(args.This(), "emit", 2, argv);
      return scope.Close(Undefined());
   }

   String::Utf8Value fileName(args[0]->ToString());
   
   file.open(strdup(*fileName), std::ios::in | std::ios::binary);

   if (!file.is_open())
   {
      Handle<Value> argv[2] = {
       String::New("error"), // event name
       Exception::TypeError(String::New("Error opening file."))  // argument
      };

      MakeCallback(args.This(), "emit", 2, argv);
      return scope.Close(Undefined());
   }

   if (!decode.CheckIntegrity(file))
   {
      Handle<Value> argv[2] = {
       String::New("error"), // event name
       Exception::TypeError(String::New("FIT file integrity failed."))  // argument
      };

      MakeCallback(args.This(), "emit", 2, argv);
      return scope.Close(Undefined());
   }

   mesgBroadcaster.AddListener((fit::MesgListener &)*listener);

   try
   {
      mesgBroadcaster.Run(file);
   }
   catch (const fit::RuntimeException& e)
   {
      Handle<Value> argv[2] = {
       String::New("error"), // event name
       Exception::TypeError(String::New("Exception while decoding file."))  // argument
      };

      MakeCallback(args.This(), "emit", 2, argv);
      return scope.Close(Undefined());
   }

   Handle<Value> argv[2] = {
    String::New("end"), // event name
    args[0]->ToString()  // argument
   };

   MakeCallback(args.This(), "emit", 2, argv);

   return Undefined();
}
