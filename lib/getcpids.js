var binding = require('../build/Release/getcpids');

module.exports = function getcpids(pid) {
  return binding.getcpids(pid);
};
