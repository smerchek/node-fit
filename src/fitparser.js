var FitParser = require('../build/Release/binding.node').FitParser;
var events = require('events');

inherits(FitParser, events.EventEmitter);
exports.FitParser = FitParser;

// extend prototype
function inherits(target, source) {
  for (var k in source.prototype)
    target.prototype[k] = source.prototype[k];
}
