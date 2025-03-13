import time
import pyvjoy

# Initialiser le périphérique vJoy (le périphérique 1 est utilisé ici)
joystick = pyvjoy.VJoyDevice(1)

# Fonction pour envoyer une commande de rotation en continu
def tourner_volant():
    try:
        while True:
            print('test')
            joystick.set_axis(1, 100, )  # True pour appuyer
            time.sleep(0.1)  # Simuler un appui continu
            # Relâcher le bouton A
            #joystick.set_button(4, False)  # False pour relâcher
            time.sleep(0.1)  # Relâcher le bouton
    except KeyboardInterrupt:
        print("Arrêt du programme.")

# Exécuter la fonction pour faire tourner le volant
tourner_volant()
