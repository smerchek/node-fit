require("mocha");
var should = require('should');
var path = require('path');
var FitParser = require('../lib/fitparser').FitParser;

describe("decode()", function() {
   describe("#Exceptions", function() {

      it("should throw an arguments error when input is undefined", function() {
         var fitParser = new FitParser();
         fitParser.on('error', function(e) {
            e.message.should.equal('Wrong number of arguments');
         });
         fitParser.on('end', shouldNotHappen);
         fitParser.decode();
      });

      it("should throw an arguments error when input is not a string", function() {
         var fitParser = new FitParser();
         fitParser.on('error', function(e) {
            e.message.should.equal('Argument must be a string.');
         });
         fitParser.on('end', shouldNotHappen);
         fitParser.decode(1);
      });

      it("should throw an error when the file does not exist", function() {
         var fitParser = new FitParser();
         fitParser.on('error', function(e) {
            e.message.should.equal('Error opening file.');
         });
         fitParser.on('end', shouldNotHappen);
         fitParser.decode("fileNotFound");
      });

      it("should throw an error when the file integrity check fails", function() {
         var fitParser = new FitParser();
         fitParser.on('error', function(e) {
            e.message.should.equal('FIT file integrity failed.');
         });
         fitParser.on('end', shouldNotHappen);
         var fileName = path.resolve('test-files/poorIntegrity.fit');
         fitParser.decode(fileName);
      });

      it("should not throw an error if a good file", function() {
         var fitParser = new FitParser();
         fitParser.on('error', shouldNotHappen);
         var fileName = path.resolve('test-files/Activity.fit');
         fitParser.decode(fileName);
      });
   });

   describe("#Messages", function() {

      it("should emit messages", function() {
         var fitParser = new FitParser();
         fitParser.on('message', function(msg) {
            msg.should.have.property('type');
            msg.should.have.property('value');
            msg.should.have.property('units');
         });
         var fileName = path.resolve('test-files/Activity.fit');
         fitParser.decode(fileName);
      });
   });
});

function shouldNotHappen() {
   false.should.be.ok;
}

function shouldHappen() {
   true.should.be.ok;
}