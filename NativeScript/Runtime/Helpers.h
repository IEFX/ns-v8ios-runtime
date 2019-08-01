#ifndef Helpers_h
#define Helpers_h

#include <functional>
#include <string>
#include "Common.h"
#include "DataWrapper.h"

namespace tns {

v8::Local<v8::String> ToV8String(v8::Isolate* isolate, std::string value);
std::string ToString(v8::Isolate* isolate, const v8::Local<v8::Value>& value);
double ToNumber(const v8::Local<v8::Value>& value);
bool ToBool(const v8::Local<v8::Value>& value);

std::string ReadText(const std::string& file);

void SetPrivateValue(const v8::Local<v8::Object>& obj, const v8::Local<v8::String>& propName, const v8::Local<v8::Value>& value);
v8::Local<v8::Value> GetPrivateValue(const v8::Local<v8::Object>& obj, const v8::Local<v8::String>& propName);

void SetValue(v8::Isolate* isolate, const v8::Local<v8::Object>& obj, BaseDataWrapper* value);
BaseDataWrapper* GetValue(v8::Isolate* isolate, const v8::Local<v8::Value>& val);
std::vector<v8::Local<v8::Value>> ArgsToVector(const v8::FunctionCallbackInfo<v8::Value>& info);
void ThrowError(v8::Isolate* isolate, std::string message);

bool IsString(v8::Local<v8::Value> value);
bool IsNumber(v8::Local<v8::Value> value);
bool IsBool(v8::Local<v8::Value> value);

void ExecuteOnMainThread(std::function<void ()> func, bool async = true);

}

#endif /* Helpers_h */
