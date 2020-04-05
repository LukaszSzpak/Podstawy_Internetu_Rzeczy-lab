import msvcrt
from paho.mqtt import publish
import config


class main:
    while 1:
        if msvcrt.kbhit():
            key_stroke = str(msvcrt.getch())[2]
            if '1' <= key_stroke <= '9':
                publish.single(config.MQTT_PATH, key_stroke, hostname=config.MQTT_ADDRESS)
