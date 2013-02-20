////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2013 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 6.0Release
// Tag = $Name: AKW6_000 $
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_RECORD_MESG_HPP)
#define FIT_RECORD_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class RecordMesg : public Mesg
{
   public:
      RecordMesg(void) : Mesg(Profile::MESG_RECORD)
      {
      }

      RecordMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      FIT_DATE_TIME GetTimestamp(void) const
      {
         return GetFieldUINT32Value(253, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      void SetTimestamp(FIT_DATE_TIME timestamp)
      {
         SetFieldUINT32Value(253, timestamp, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetPositionLat(void) const
      {
         return GetFieldSINT32Value(0, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetPositionLat(FIT_SINT32 positionLat)
      {
         SetFieldSINT32Value(0, positionLat, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetPositionLong(void) const
      {
         return GetFieldSINT32Value(1, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetPositionLong(FIT_SINT32 positionLong)
      {
         SetFieldSINT32Value(1, positionLong, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns altitude field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetAltitude(void) const
      {
         return GetFieldFLOAT32Value(2, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set altitude field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetAltitude(FIT_FLOAT32 altitude)
      {
         SetFieldFLOAT32Value(2, altitude, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetHeartRate(void) const
      {
         return GetFieldUINT8Value(3, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      void SetHeartRate(FIT_UINT8 heartRate)
      {
         SetFieldUINT8Value(3, heartRate, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetCadence(void) const
      {
         return GetFieldUINT8Value(4, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      void SetCadence(FIT_UINT8 cadence)
      {
         SetFieldUINT8Value(4, cadence, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetDistance(void) const
      {
         return GetFieldFLOAT32Value(5, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetDistance(FIT_FLOAT32 distance)
      {
         SetFieldFLOAT32Value(5, distance, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetSpeed(void) const
      {
         return GetFieldFLOAT32Value(6, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      void SetSpeed(FIT_FLOAT32 speed)
      {
         SetFieldFLOAT32Value(6, speed, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetPower(void) const
      {
         return GetFieldUINT16Value(7, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      void SetPower(FIT_UINT16 power)
      {
         SetFieldUINT16Value(7, power, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns number of compressed_speed_distance
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetNumCompressedSpeedDistance(void) const
      {
         return GetFieldNumValues(8, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns compressed_speed_distance field
      ///////////////////////////////////////////////////////////////////////
      FIT_BYTE GetCompressedSpeedDistance(FIT_UINT8 index) const
      {
         return GetFieldBYTEValue(8, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set compressed_speed_distance field
      ///////////////////////////////////////////////////////////////////////
      void SetCompressedSpeedDistance(FIT_UINT8 index, FIT_BYTE compressedSpeedDistance)
      {
         SetFieldBYTEValue(8, compressedSpeedDistance, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns grade field
      // Units: %
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetGrade(void) const
      {
         return GetFieldFLOAT32Value(9, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set grade field
      // Units: %
      ///////////////////////////////////////////////////////////////////////
      void SetGrade(FIT_FLOAT32 grade)
      {
         SetFieldFLOAT32Value(9, grade, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns resistance field
      // Comment: Relative. 0 is none  254 is Max.
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetResistance(void) const
      {
         return GetFieldUINT8Value(10, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set resistance field
      // Comment: Relative. 0 is none  254 is Max.
      ///////////////////////////////////////////////////////////////////////
      void SetResistance(FIT_UINT8 resistance)
      {
         SetFieldUINT8Value(10, resistance, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns time_from_course field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetTimeFromCourse(void) const
      {
         return GetFieldFLOAT32Value(11, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set time_from_course field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      void SetTimeFromCourse(FIT_FLOAT32 timeFromCourse)
      {
         SetFieldFLOAT32Value(11, timeFromCourse, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cycle_length field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetCycleLength(void) const
      {
         return GetFieldFLOAT32Value(12, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cycle_length field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetCycleLength(FIT_FLOAT32 cycleLength)
      {
         SetFieldFLOAT32Value(12, cycleLength, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns temperature field
      // Units: C
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT8 GetTemperature(void) const
      {
         return GetFieldSINT8Value(13, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set temperature field
      // Units: C
      ///////////////////////////////////////////////////////////////////////
      void SetTemperature(FIT_SINT8 temperature)
      {
         SetFieldSINT8Value(13, temperature, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns number of speed_1s
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetNumSpeed1s(void) const
      {
         return GetFieldNumValues(17, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns speed_1s field
      // Units: m/s
      // Comment: Speed at 1s intervals.  Timestamp field indicates time of last array element.
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetSpeed1s(FIT_UINT8 index) const
      {
         return GetFieldFLOAT32Value(17, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set speed_1s field
      // Units: m/s
      // Comment: Speed at 1s intervals.  Timestamp field indicates time of last array element.
      ///////////////////////////////////////////////////////////////////////
      void SetSpeed1s(FIT_UINT8 index, FIT_FLOAT32 speed1s)
      {
         SetFieldFLOAT32Value(17, speed1s, index, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cycles field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetCycles(void) const
      {
         return GetFieldUINT8Value(18, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cycles field
      ///////////////////////////////////////////////////////////////////////
      void SetCycles(FIT_UINT8 cycles)
      {
         SetFieldUINT8Value(18, cycles, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns total_cycles field
      // Units: cycles
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetTotalCycles(void) const
      {
         return GetFieldUINT32Value(19, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set total_cycles field
      // Units: cycles
      ///////////////////////////////////////////////////////////////////////
      void SetTotalCycles(FIT_UINT32 totalCycles)
      {
         SetFieldUINT32Value(19, totalCycles, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns compressed_accumulated_power field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetCompressedAccumulatedPower(void) const
      {
         return GetFieldUINT16Value(28, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set compressed_accumulated_power field
      ///////////////////////////////////////////////////////////////////////
      void SetCompressedAccumulatedPower(FIT_UINT16 compressedAccumulatedPower)
      {
         SetFieldUINT16Value(28, compressedAccumulatedPower, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns accumulated_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetAccumulatedPower(void) const
      {
         return GetFieldUINT32Value(29, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set accumulated_power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      void SetAccumulatedPower(FIT_UINT32 accumulatedPower)
      {
         SetFieldUINT32Value(29, accumulatedPower, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns left_right_balance field
      ///////////////////////////////////////////////////////////////////////
      FIT_LEFT_RIGHT_BALANCE GetLeftRightBalance(void) const
      {
         return GetFieldUINT8Value(30, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set left_right_balance field
      ///////////////////////////////////////////////////////////////////////
      void SetLeftRightBalance(FIT_LEFT_RIGHT_BALANCE leftRightBalance)
      {
         SetFieldUINT8Value(30, leftRightBalance, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns gps_accuracy field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetGpsAccuracy(void) const
      {
         return GetFieldUINT8Value(31, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set gps_accuracy field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetGpsAccuracy(FIT_UINT8 gpsAccuracy)
      {
         SetFieldUINT8Value(31, gpsAccuracy, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns vertical_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetVerticalSpeed(void) const
      {
         return GetFieldFLOAT32Value(32, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set vertical_speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      void SetVerticalSpeed(FIT_FLOAT32 verticalSpeed)
      {
         SetFieldFLOAT32Value(32, verticalSpeed, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns calories field
      // Units: kcal
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetCalories(void) const
      {
         return GetFieldUINT16Value(33, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set calories field
      // Units: kcal
      ///////////////////////////////////////////////////////////////////////
      void SetCalories(FIT_UINT16 calories)
      {
         SetFieldUINT16Value(33, calories, 0, FIT_SUBFIELD_INDEX_MAIN_FIELD);
      }

};

} // namespace fit

#endif // !defined(FIT_RECORD_MESG_HPP)
