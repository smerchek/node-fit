var assert = require('assert');
var path = require('path');
var binding = require('../src/fitparser');

var fitParser = new binding.FitParser();

var fileName = path.resolve('test-files/Settings.fit');
console.log("Decoding file: " + fileName);

fitParser.on("message", function(msg) {
   console.log("Recieved message: ");
   console.log(msg);
});
fitParser.on("end", function(msg) {
   console.log("Done decoding: " + msg);
});
fitParser.decode(fileName);

fileName = path.resolve('test-files/Activity.fit');
console.log("Decoding file: " + fileName);
fitParser.decode(fileName);

// fileName = path.resolve('test-files/swim.fit');
// console.log("Decoding file: " + fileName);
// assert.equal(fileName, binding.decode(fileName));