import msvcrt
import datetime
from Employee import Employee
from SaveAndLoadData import prepare_and_save, save_csv


class CommandLineConfig(object):
    def __init__(self, emp_list, file_name):
        self.emp_list = emp_list
        self.file_name = file_name

    def program_config(self):
        print("Press c to config")
        while True:
            if msvcrt.kbhit() and str(msvcrt.getch())[2] is 'c':
                self.ask_what_to_do()

    def ask_what_to_do(self):
        print("\ta - add new / edit employee\n" +
              "\ts - show exists employ list\n" +
              "\tr - save report to file\n" +
              "\td - delete employ\n" +
              "\te - exit")
        input_get = str(input())[0]

        if input_get == 'a':
            self.add_new_employee()
        elif input_get == 's':
            self.show_employ_list()
        elif input_get == 'd':
            self.delete_employee()
        elif input_get == "e":
            self.program_config()
        elif input_get == "r":
            self.make_report()
        else:
            self.ask_what_to_do()

    def add_new_employee(self):
        print("Write new employee data: (id, name, surname) - if id exist you'll overide its data")
        new_data = input().split(', ')

        self.check_id_and_add_or_edit(new_data[0], new_data[1], new_data[2])
        print('You add: ' + new_data[0] + ' ' + new_data[1] + ' ' + new_data[2])

        prepare_and_save(self.emp_list, self.file_name)
        self.ask_what_to_do()

    def show_employ_list(self):
        print("Employ list:")
        for i in self.emp_list:
            print(i.to_string())

        self.ask_what_to_do()

    def check_id_and_add_or_edit(self, id, name, surname):
        for i in self.emp_list:
            if i.id == id:
                i.name = name
                i.surname = surname
                break
        else:
            self.emp_list.append(Employee(id, name, surname, []))

    def delete_employee(self):
        print("Delete employee with id: ")
        input_get = str(input())

        self.check_and_delete(input_get)

    def check_and_delete(self, id):
        for i in self.emp_list:
            if i.id == id:
                self.emp_list.remove(i)
                break;
        else:
            print("Not found !")

        self.ask_what_to_do()

    def make_report(self):
        save_csv('report_' + str(datetime.datetime.now().date()) + '.csv', self.emp_list)
        print("Saved !")

        self.ask_what_to_do()
