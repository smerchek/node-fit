var assert = require('assert');
var path = require('path');
var binding = require('../build/Release/binding.node');
var fileName = path.resolve('test-files/Settings.fit');
console.log("Decoding file: " + fileName);
assert.equal(fileName, binding.decode(fileName));

fileName = path.resolve('test-files/Activity.fit');
console.log("Decoding file: " + fileName);
assert.equal(fileName, binding.decode(fileName));

fileName = path.resolve('test-files/swim.fit');
console.log("Decoding file: " + fileName);
assert.equal(fileName, binding.decode(fileName));