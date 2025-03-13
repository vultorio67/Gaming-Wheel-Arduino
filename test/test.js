const { F1TelemetryClient, constants } = require("@racehub-io/f1-telemetry-client");

const PORT = 20777;
const client = new F1TelemetryClient({ port: PORT });

// Créer un objet pour stocker toutes les données de télémétrie
let telemetryData = {};

client.on("carTelemetry", (data) => {
  const carIndex = data.m_header.m_playerCarIndex; // Récupère la voiture du joueur
  const carTelemetry = data.m_carTelemetryData[carIndex];

  // Stocker les données de vitesse, boîte de vitesses, température des pneus, et plus
  telemetryData = {
    speed: carTelemetry.m_speed, // Vitesse de la voiture (km/h)
    gear: carTelemetry.m_gear, // Boîte de vitesses (rapport de vitesse actuel)
    throttle: carTelemetry.m_throttle, // Position de l'accélérateur (0-1)
    brake: carTelemetry.m_brake, // Position du frein (0-1)
    steering: carTelemetry.m_steer, // Position du volant (angle)
    tyreSurfaceTemperature: carTelemetry.m_tyresSurfaceTemperature, // Température des pneus (4 pneus)
    tyreWear: carTelemetry.m_tyresWear, // Usure des pneus (4 pneus)
    tyreSlip: carTelemetry.m_wheelSlip, // Glissement des roues (4 roues)
    engineRPM: carTelemetry.m_engineRPM, // Régime moteur (RPM)
  };

  // Affichage des données dans la console pour débogage
  console.log("📊 Données de télémétrie de la voiture :");
  console.log(`➡️ Vitesse: ${telemetryData.speed} km/h`);
  console.log(`⚙️ Boîte de vitesses: ${telemetryData.gear}`);
  console.log(`🚗 Accélérateur: ${telemetryData.throttle}`);
  console.log(`🛑 Frein: ${telemetryData.brake}`);
  console.log(`🛠️ Position du volant: ${telemetryData.steering}`);
  console.log(`🔥 Température des pneus: ${telemetryData.tyreSurfaceTemperature}`);
  console.log(`⚠️ Usure des pneus: ${telemetryData.tyreWear}`);
  console.log(`💨 Glissement des roues: ${telemetryData.tyreSlip}`);
  console.log(`🔧 Régime moteur: ${telemetryData.engineRPM} RPM`);
  console.log("=======================================");
});

client.on("motion", (data) => {
  const carIndex = data.m_header.m_playerCarIndex; // Récupère la voiture du joueur
  const motionData = data.m_carMotionData[carIndex];

  // Stocker les données de mouvement dans l'objet telemetryData
  telemetryData.gForceLateral = motionData.m_gForceLateral; // Accélération latérale
  telemetryData.gForceLongitudinal = motionData.m_gForceLongitudinal; // Accélération longitudinale
  telemetryData.gForceVertical = motionData.m_gForceVertical; // Accélération verticale

  // Affichage des données de mouvement
  console.log("📊 Accélération en G:");
  console.log(`➡️ Latérale: ${telemetryData.gForceLateral} G`);
  console.log(`⬆️ Verticale: ${telemetryData.gForceVertical} G`);
  console.log(`⬅️ Longitudinale: ${telemetryData.gForceLongitudinal} G`);
  console.log("=======================================");
});

// Démarrer l’écoute
client.start();
console.log("🟢 Lecture des données de télémétrie...");
