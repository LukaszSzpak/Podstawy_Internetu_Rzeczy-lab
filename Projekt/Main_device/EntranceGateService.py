from Employee import Employee
import datetime
from SaveAndLoadData import prepare_and_save
import paho.mqtt.client as mqtt
import sys
from config import MQTT_PATH, MQTT_ADDRESS, MQQT_PORT, MQQT_TLS_CERT, LOGIN, PASSW


class EntranceGateService(object):
    def __init__(self, emp_list, file_name):
        self.emp_list = emp_list
        self.file_name = file_name

    def add_employee_new_time(self, employee):
        employee.add_new_time(format(datetime.datetime.now()))

    def add_new_employee(self, id):
        self.emp_list.append(Employee(id, ' ', ' ', [format(datetime.datetime.now())]))

    def check_id_and_add(self, id):
        for i in self.emp_list:
            if i.id == id:
                self.add_employee_new_time(i)
                break
        else:
            self.add_new_employee(id)

        prepare_and_save(self.emp_list, self.file_name)

    def on_connect(self, client, userdata, flags, rc):
        print("Connected with result code " + str(rc))
        client.subscribe(MQTT_PATH)

    def on_message(self, client, userdata, msg):
        my_msg = str(msg.payload)[2:-1]
        self.check_id_and_add(my_msg)

    def connect_gate(self):
        try:
            client = mqtt.Client()
            client.tls_set(MQQT_TLS_CERT)
            client.username_pw_set(username=LOGIN, password=PASSW)
            client.connect(MQTT_ADDRESS, MQQT_PORT)
            client.on_connect = self.on_connect
            client.on_message = self.on_message
            client.loop_forever()
        except:
            print("Cannot connect !")
            self.connect_gate()

    def handle_data_from_gates(self):
        self.connect_gate()
