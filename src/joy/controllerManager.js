const ViGEmClient = require('vigemclient');

let client = new ViGEmClient();

client.connect(); // establish connection to the ViGEmBus driver

let controller = client.createX360Controller();

controller.connect(); // plug in the virtual controller

function mapSteering(value) {
    let normalized = (value / 1023) * 2 - 1; // Convertit en plage [-1, 1]
    let curved = Math.sign(normalized) * Math.pow(Math.abs(normalized), 0.55); // Réagit fort au centre
    return curved;
}

function mapAccel(a, b, value) {
    return (value/900)/(b-a);
}

function mapBrake(a, b, value) {
    return (value/1023)/(b-a);
}

function mapControllerData(arduinoData) {

    //console.log(arduinoData);
    console.log(mapBrake(0,1,arduinoData.accel));
    controller.axis.leftX.setValue(mapSteering(arduinoData.volant));
    controller.axis.rightTrigger.setValue(mapAccel(0,1,arduinoData.accel));
    controller.axis.leftTrigger.setValue(mapBrake(0,1,arduinoData.brake));
    //controller.axis.leftX.setValue(data.steeringWheel);
}

module.exports = { mapControllerData };


