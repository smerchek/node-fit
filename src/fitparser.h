#ifndef FITPARSER_H
#define FITPARSER_H

#include <node.h>

class FitParser : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  FitParser();
  ~FitParser();

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> Decode(const v8::Arguments& args);
};

#endif