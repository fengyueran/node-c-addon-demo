# c-addon-demo

这个项目的作用是实现 JS 调用 C++代码的 demo，有两种方式：

## 通过 [node-addon-api](https://github.com/nodejs/node-addon-api)

node-addon-api 是官方维护的，可简化通过 Node-API 实现 addon 插件的流程且支持 c++。
测试步骤：

- 项目根目录执行 yarn(没有则执行 npm i yarn -g)

- 根目录执行 yarn build:addon-math-node

  这会将 src/node-addon-api/source/math.cc 文件编译为一个.node 文件(external/math.node)。

- 根目录执行 yarn test:addon

  执行该命令会执行 src/node-addon-api/index.js 文件，它依赖于上一步编译出的.node 文件。
  执行成功会输出：'add: 333 + 333 = 666'

## 通过 [ffi-napi](https://github.com/node-ffi-napi/node-ffi-napi)

ffi-napi 可以使用纯 JavaScript 加载和调用动态库，而无需编写任何 C++ 代码。

测试步骤：

- 项目根目录执行 yarn

- 根目录执行 yarn build:ffi-math-lib

  这会将 src/ffi/source/math.cpp 文件编译为一个.dylib 文件(external/math.dylib)。

- 根目录执行 yarn test:ffi

  执行该命令会执行 src/ffi/index.js 文件，它依赖于上一步编译出的动态链接库(math.dylib，mac 版本)。
  执行成功会输出：'add: 333 + 333 = 666'

ffi-napi 最大的优势在于，我们不需要太关心 c++源码，不需要编译。其本质上还是一个编译后的 Node addon(node_modules/ffi/build/Release/ffi_bindings.node)，ffi_bindings.node 就是一个 addon 它充当了 nodejs 和 dll 之间的桥梁。
