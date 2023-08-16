const ffi = require("ffi-napi");
const path = require("path");

const libPath = path.join(__dirname, "../../external/math.dylib");

const mathLib = ffi.Library(libPath, {
  Add: ["double", ["double", "double"]],
});

console.log("add: 333 + 333 =", mathLib.Add(333, 333));
