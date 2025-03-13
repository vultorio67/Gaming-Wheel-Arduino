const { F1TelemetryClient } = require("@racehub-io/f1-telemetry-client");
const EventEmitter = require('events');

// Créer un objet EventEmitter pour émettre des événements
const telemetryEmitter = new EventEmitter();

const PORT = 20777;
const client = new F1TelemetryClient({ port: PORT });

// Créer un objet pour stocker toutes les données de télémétrie
let telemetryData = {};
let motionData = {}

// Écouter les données de télémétrie de la voiture
client.on("carTelemetry", (data) => {
  const carIndex = data.m_header.m_playerCarIndex; // Récupère la voiture du joueur
  const carTelemetry = data.m_carTelemetryData[carIndex];

  // Stocker les données de télémétrie
  telemetryData = {
    speed: carTelemetry.m_speed, // Vitesse de la voiture (km/h)
    gear: carTelemetry.m_gear, // Boîte de vitesses (rapport de vitesse actuel)
    throttle: carTelemetry.m_throttle, // Position de l'accélérateur (0-1)
    brake: carTelemetry.m_brake, // Position du frein (0-1)
    steering: carTelemetry.m_steer, // Position du volant (angle)
    tyreSurfaceTemperature: carTelemetry.m_tyresSurfaceTemperature, // Température des pneus
    engineRPM: carTelemetry.m_engineRPM, // Régime moteur (RPM)
  };
});

// Écouter les données de mouvement de la voiture
client.on("motion", (data) => {
  const carIndex = data.m_header.m_playerCarIndex; // Récupère la voiture du joueur
  const motionDataE = data.m_carMotionData[carIndex];

  motionData = {
    GLateral: motionDataE.m_gForceLateral,
    GLongitudinal: motionDataE.m_gForceLongitudinal,
    GVertical:  motionDataE.m_gForceVertical
  }

});

// Démarrer la connexion du client F1Telemetry
client.start();

// Fonction pour émettre les données toutes les 20ms
setInterval(() => {
  // Émettre les données à chaque intervalle
  telemetryEmitter.emit('telemetryData', [telemetryData, motionData]);

}, 20); // toutes les 20ms (20000 microsecondes)

module.exports = { telemetryEmitter, telemetryData, client };
