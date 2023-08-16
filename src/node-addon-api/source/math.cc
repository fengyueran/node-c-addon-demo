#include <napi.h>
#include<iostream>
#include<string>
#include <unistd.h>

using namespace Napi;
//直接返回c++的数值类型数据到js
Value getNumber(const CallbackInfo& info) {
  Env env = info.Env();
  int num = 2;
  std::cout << "c++-log=>" << num << std::endl;
  Number result = Number::New(env, num);

  return result;
}
// 接收js传来的两个数值，转化为C++可用的数值后，相加并将结果返回。没有做参数的类型检测，传入字符串或不传，会报错
Value addNumber(const CallbackInfo& info){
  Env env = info.Env();
  double arg0 = info[0].As<Number>().DoubleValue();
  double arg1 = info[1].As<Number>().DoubleValue();
  double num = arg0+arg1;
  Number result = Number::New(env, num);
  usleep(3000000); //3s
  return result;
}

Object Init(Env env, Object exports) {
  exports.Set(String::New(env, "getNumber"), Function::New(env, getNumber));
  exports.Set(String::New(env, "addNumber"), Function::New(env, addNumber));
  return exports;
}

NODE_API_MODULE(addon, Init)
