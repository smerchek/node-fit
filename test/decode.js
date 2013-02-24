require("mocha");
var should = require('should');
var sinon = require('sinon');
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
         var onMessage = sinon.spy();
         fitParser.on('message', function(msg) {
            msg.should.have.property('type');
            msg.should.have.property('value');
            msg.should.have.property('units');
            onMessage();
         });
         var fileName = path.resolve('test-files/Activity.fit');
         fitParser.decode(fileName);
         onMessage.callCount.should.be.above(0);
      });

      it("should emit record messages", function() {
         var fitParser = new FitParser();
         var onRecord = sinon.spy();
         fitParser.on('record', function(msg) {
            msg.should.have.property('timestamp');
            msg.should.have.property('position_lat');
            msg.should.have.property('position_long');
            msg.should.have.property('altitude');
            msg.should.have.property('distance');
            msg.should.have.property('speed');
            msg.should.not.have.property('heart_rate');
            onRecord();
         });
         var fileName = path.resolve('test-files/Activity.fit');
         fitParser.decode(fileName);
         //onRecord.callCount.should.equal(14);
      });
   });
});

function shouldNotHappen() {
   false.should.be.ok;
}

function shouldHappen() {
   true.should.be.ok;
}