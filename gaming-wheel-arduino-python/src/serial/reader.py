from threading import Thread
import serial
import json

def serial_listening(port):
    buffer = ''

    def read_data():
        nonlocal buffer
        while True:
            data = port.read(port.in_waiting or 1)
            buffer += data.decode('utf-8')

            if '\n' in buffer:
                lines = buffer.split('\n')
                while len(lines) > 1:
                    message = lines.pop(0)
                    try:
                        sensor_data = json.loads(message)
                        print('Données reçues:', sensor_data['volant'])
                    except json.JSONDecodeError:
                        pass
                buffer = lines[0]  # Keep the last incomplete line

    thread = Thread(target=read_data)
    thread.start()

def open_serial_port(port_name, baud_rate):
    port = serial.Serial(port_name, baud_rate)
    print('Port série ouvert')
    return port

# Exporter la fonction
# This file is intentionally left blank.