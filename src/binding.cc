#include <node.h>
#include <v8.h>
#include "fitparser.h"

using namespace v8;


extern "C" void init(Handle<Object> target) {
  FitParser::Init(target);
}

NODE_MODULE(binding, init);