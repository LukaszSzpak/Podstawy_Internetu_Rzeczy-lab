from Employee import Employee
from SaveAndLoadData import load_data
from EntranceGateService import EntranceGateService
from threading import Thread
from CommandLineConfig import CommandLineConfig
import time

FILE_NAME = 'list.json'


def parse_JSON_to_List(employee_JSON):
    return [Employee(i['id'], i['name'], i['surname'], i['timesheet']) for i in employee_JSON] if employee_JSON != [] else []


def gate_thread(gate):
    gate.handle_data_from_gates()


def config(line_conf):
    line_conf.program_config()


class main:
    print("Starting program...")
    employ_list = parse_JSON_to_List(load_data(FILE_NAME))
    gate = EntranceGateService(employ_list, FILE_NAME)
    conf = CommandLineConfig(employ_list, FILE_NAME)

    if __name__ == "__main__":
        thread1 = Thread(target=gate_thread, args=(gate,))
        thread2 = Thread(target=config, args=(conf,))
        thread1.start()
        time.sleep(2)
        thread2.start()
        thread1.join()
        thread2.join()
