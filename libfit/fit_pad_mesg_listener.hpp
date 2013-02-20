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


#if !defined(FIT_PAD_MESG_LISTENER_HPP)
#define FIT_PAD_MESG_LISTENER_HPP

#include "fit_pad_mesg.hpp"

namespace fit
{

class PadMesgListener
{
   public:
      virtual ~PadMesgListener() {}
      virtual void OnMesg(PadMesg& mesg) = 0;
};

} // namespace fit

#endif // !defined(FIT_PAD_MESG_LISTENER_HPP)
