#include <v8.h>
#include <node.h>
#include <unistd.h>
#include <limits.h>

using namespace v8;
using namespace node;

static Handle<Value> Getcpids(const Arguments& args) {
  HandleScope scope;
  int i, ppid, index;
  if (args[0]->IsInt32()) {
    ppid = args[0]->Int32Value();
    index = 0;
    Local<Array> result = Array::New();
    for(i = 0; i < SHRT_MAX; i++) {
      if(i != ppid && getpgid(i) == ppid) {
        result->Set(index++, Integer::New(i));
      }
    }
    return scope.Close(result);
  } else {
    return ThrowException(Exception::Error(String::New("Not an integer.")));
  }
}

extern "C" void init(Handle<Object> target) {
  HandleScope scope;
  NODE_SET_METHOD(target, "getcpids", Getcpids);
}

NODE_MODULE(getcpids, init)
