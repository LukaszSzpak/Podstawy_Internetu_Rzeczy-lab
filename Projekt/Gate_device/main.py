import msvcrt
from paho.mqtt import publish

MQTT_PATH = "my_channel"
MQTT_ADDRESS = 'localhost'


class main:
    while 1:
        if msvcrt.kbhit():
            key_stroke = str(msvcrt.getch())[2]
            if '1' <= key_stroke <= '9':
                publish.single(MQTT_PATH, key_stroke, hostname=MQTT_ADDRESS)
