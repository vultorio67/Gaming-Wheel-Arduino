from threading import Thread
from f1_telemetry_client import F1TelemetryClient
import time

class TelemetryReceiver:
    def __init__(self, port):
        self.port = port
        self.client = F1TelemetryClient(port=self.port)
        self.telemetry_data = {}
        self.motion_data = {}

    def start(self):
        self.client.start()
        Thread(target=self.receive_telemetry).start()
        Thread(target=self.receive_motion).start()

    def receive_telemetry(self):
        while True:
            data = self.client.get_car_telemetry()
            if data:
                car_index = data['m_header']['m_playerCarIndex']
                car_telemetry = data['m_carTelemetryData'][car_index]
                self.telemetry_data = {
                    'speed': car_telemetry['m_speed'],
                    'gear': car_telemetry['m_gear'],
                    'throttle': car_telemetry['m_throttle'],
                    'brake': car_telemetry['m_brake'],
                    'steering': car_telemetry['m_steer'],
                    'tyreSurfaceTemperature': car_telemetry['m_tyresSurfaceTemperature'],
                    'engineRPM': car_telemetry['m_engineRPM'],
                }
            time.sleep(0.02)  # 20ms interval

    def receive_motion(self):
        while True:
            data = self.client.get_car_motion()
            if data:
                car_index = data['m_header']['m_playerCarIndex']
                motion_data = data['m_carMotionData'][car_index]
                self.motion_data = {
                    'gForceLateral': motion_data['m_gForceLateral'],
                    'gForceLongitudinal': motion_data['m_gForceLongitudinal'],
                    'gForceVertical': motion_data['m_gForceVertical'],
                }
            time.sleep(0.02)  # 20ms interval

# Example usage:
# telemetry_receiver = TelemetryReceiver(port=20777)
# telemetry_receiver.start()