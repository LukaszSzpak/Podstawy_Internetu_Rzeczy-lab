import msvcrt
import paho.mqtt.client as mqtt
import time
from config import MQTT_PATH, MQTT_ADDRESS, MQQT_PORT, MQQT_TLS_CERT, LOGIN, PASSW

client = mqtt.Client()


def start_client():
    conn_to_server()
    while 1:
        if msvcrt.kbhit():
            key_stroke = str(msvcrt.getch())[2]
            if '1' <= key_stroke <= '9':
                client.publish(MQTT_PATH, key_stroke,)


def conn_to_server():
    try:
        client.tls_set(MQQT_TLS_CERT)
        client.username_pw_set(username=LOGIN, password=PASSW)
        client.connect(MQTT_ADDRESS, MQQT_PORT)
        print("Connected !\n")
    except:
        print("cannot connect !")
        time.sleep(2)
        conn_to_server()


if __name__ == "__main__":
    start_client()
