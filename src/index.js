const { telemetryEmitter} = require('./udp/parser.js');
const { serialListening } = require('./Serial/reader.js');

const { SerialPort } = require('serialport');

const port = new SerialPort({
  path: 'COM6', // Change this to your serial port path (e.g., COM3 on Windows)
  baudRate: 2000000, // Adjust according to your device's baud rate
});


telemetryEmitter.on('telemetryData', (data) => {
    //console.log(data);
});

serialListening(port)