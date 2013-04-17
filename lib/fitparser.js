var FitParser = require('../build/Release/binding.node').FitParser;
var events = require('events');
var util = require('util');

util.inherits(FitParser, events.EventEmitter);
exports.FitParser = FitParser;