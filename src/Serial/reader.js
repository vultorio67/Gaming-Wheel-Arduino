const { mapControllerData } = require("../joy/controllerManager");



function serialListening(port)
{
    //on acculume les données
    let buffer = '';  

    port.on('data', (data) => {
      buffer += data.toString();  // Ajouter les données reçues au buffer
  
      // Si nous avons trouvé un retour à la ligne (indicateur de fin de message)
      if (buffer.includes('\n')) {
        const lines = buffer.split('\n');  // Diviser le buffer en lignes
  
        // Traiter toutes les lignes complètes
        while (lines.length > 1) {
          const message = lines.shift();  
  
          try {
            // Parser le message JSON
            const sensorData = JSON.parse(message);
            //console.log(sensorData);
            mapControllerData(sensorData) // Appeler la fonction de mappage des données
          } catch (error) {
            //console.error('Erreur de parsing JSON:', error);
          }
        }
  
        // Réassigner le reste du buffer (le cas où il y aurait une ligne incomplète)
        buffer = lines.join('\n');
      }
    });

    port.on('open', () => {
        console.log('Port série ouvert');
    });

    port.on('error', (err) => {
        console.error('Erreur du port série:', err);
       // callback(err); // Passer l'erreur vers le callback
    });}

  
  // Exporter la fonction
  module.exports = { serialListening };