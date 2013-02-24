#ifndef LISTENER_H
#define LISTENER_H

#include "../libfit/fit_decode.hpp"
#include "../libfit/fit_mesg_broadcaster.hpp"
#include <node.h>
#include <v8.h>

using namespace v8;
using namespace node;

class Listener : 
	public fit::MesgListener, 
	public fit::RecordMesgListener {
   public:
      Listener (const Arguments& args);
      void OnMesg(fit::Mesg& mesg);
      void OnMesg(fit::RecordMesg& mesg);

   private:
      Local<Object> self;
};

#endif