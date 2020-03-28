from Employee import Employee
import datetime
from SaveAndLoadData import save_data
import msvcrt


class EntranceGateService(object):
    def __init__(self, emp_list, file_name):
        self.emp_list = emp_list
        self.file_name = file_name

    def add_employee_new_time(self, employee):
        employee.add_new_time(format(datetime.datetime.now()))

    def add_new_employee(self, id):
        self.emp_list.append(Employee(id, ' ', ' ', [format(datetime.datetime.now())]))

    def prepare_and_save(self):
        employ = [i.__dict__ for i in self.emp_list]
        save_data(self.file_name, employ)

    def check_id_and_add(self, id):
        for i in self.emp_list:
            if i.id == id:
                self.add_employee_new_time(i)
                break
        else:
            self.add_new_employee(id)

        self.prepare_and_save()

    def handle_data_from_gate(self):
        while True:
            if msvcrt.kbhit():
                key_stroke = str(msvcrt.getch())[2]
                if '1' <= key_stroke <= '9':
                    self.check_id_and_add(key_stroke)
