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

// Convert a wide string to a V8 string.
static v8::Handle<v8::String> GetV8String(const std::wstring& str)
{
  return v8::String::New(
      reinterpret_cast<const uint16_t*>(str.c_str()), str.length());
}

// Convert a string to a V8 string.
static v8::Handle<v8::String> GetV8String(const std::string& str)
{
  return v8::String::New(
      reinterpret_cast<const uint16_t*>(str.c_str()), str.length());
}

// Convert a FIT DATE TIME to a V8 Date.
// FIT date time is seconds since UTC 00:00 Dec 31 1989
// v8 date time is milliseconds since UTC 00:00 Jan 1 1970
static double GetMillisecondsSinceEpoch(const uint32_t seconds)
{
   const uint32_t secondsSinceEpoch = 631065600;
   return (static_cast<double>(seconds) + secondsSinceEpoch)*1000;
}

Listener::Listener (const Arguments& args) {
   self = args.This();
}


void Listener::OnMesg(fit::RecordMesg& mesg)
{
   Local<Object> obj = Object::New();
   if (mesg.GetHeartRate() != FIT_DATE_TIME_INVALID)
      obj->Set(String::NewSymbol("timestamp"), Date::New(GetMillisecondsSinceEpoch(mesg.GetTimestamp()))); 
   if (mesg.GetPositionLat() != FIT_SINT32_INVALID)
      obj->Set(String::NewSymbol("position_lat"), Int32::New(mesg.GetPositionLat()));
   if (mesg.GetPositionLong() != FIT_SINT32_INVALID)
      obj->Set(String::NewSymbol("position_long"), Int32::New(mesg.GetPositionLong()));
   if (mesg.GetAltitude() != FIT_FLOAT32_INVALID)
      obj->Set(String::NewSymbol("altitude"),  NumberObject::New(mesg.GetAltitude()));
   if (mesg.GetHeartRate() != FIT_UINT8_INVALID)
      obj->Set(String::NewSymbol("heart_rate"), Int32::New(mesg.GetHeartRate()));
   // obj->Set(String::NewSymbol("cadence"), mesg.GetCadence());
   if (mesg.GetDistance() != FIT_FLOAT32_INVALID)
      obj->Set(String::NewSymbol("distance"), NumberObject::New(mesg.GetDistance()));
   if (mesg.GetSpeed() != FIT_FLOAT32_INVALID)
      obj->Set(String::NewSymbol("speed"), NumberObject::New(mesg.GetSpeed()));
   // obj->Set(String::NewSymbol("power"), mesg.GetPower());
   // obj->Set(String::NewSymbol("compressed_speed_distance"), mesg.GetNumCompressedSpeedDistance());
   // obj->Set(String::NewSymbol("grade"), mesg.GetGrade());
   // obj->Set(String::NewSymbol("resistance"), mesg.GetResistance());
   // obj->Set(String::NewSymbol("time_from_course"), mesg.GetTimeFromCourse());
   // obj->Set(String::NewSymbol("cycle_length"), mesg.GetCycleLength());
   // obj->Set(String::NewSymbol("temperature"), mesg.GetTemperature());
   // obj->Set(String::NewSymbol("speed_1s"), mesg.GetNumSpeed1s());
   // obj->Set(String::NewSymbol("cycles"), mesg.GetCycles());
   // obj->Set(String::NewSymbol("total_cycles"), mesg.GetTotalCycles());
   // obj->Set(String::NewSymbol("compressed_accumulated_power"), mesg.GetCompressedAccumulatedPower());
   // obj->Set(String::NewSymbol("accumulated_power"), mesg.GetAccumulatedPower());
   // obj->Set(String::NewSymbol("left_right_balance"), mesg.GetLeftRightBalance());
   // obj->Set(String::NewSymbol("gps_accuracy"), mesg.GetGpsAccuracy());
   // obj->Set(String::NewSymbol("vertical_speed"), mesg.GetVerticalSpeed());
   // obj->Set(String::NewSymbol("calories"), mesg.GetCalories());
   Handle<Value> argv[2] = {
      String::New("record"), // event name
      obj  // argument
   };

   MakeCallback(self, "emit", 2, argv);
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
      std::string units = (*field).GetUnits(subFieldIndex);
      Local<Object> obj = Object::New();
      obj->Set(String::NewSymbol("type"), String::New(mesg.GetName().c_str()));
      obj->Set(String::NewSymbol("value"), GetV8String(value));
      obj->Set(String::NewSymbol("units"), String::New(units.c_str()));
      Handle<Value> argv[2] = {
         String::New("message"), // event name
         obj  // argument
      };

      MakeCallback(self, "emit", 2, argv);
   }
}
