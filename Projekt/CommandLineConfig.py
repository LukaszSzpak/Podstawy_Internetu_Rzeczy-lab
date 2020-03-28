import msvcrt


class CommandLineConfig(object):
    def __init__(self, emp_list):
        self.emp_list = emp_list

    def program_config(self):
        print("Press c to config")
        while True:
            if msvcrt.kbhit() and str(msvcrt.getch())[2] is 'c':
                print("\tPress a to add new employee")
                while True:
                    if msvcrt.kbhit() and str(msvcrt.getch())[2] is 'a':
                        self.add_new_employee()

    def add_new_employee(self):
        print("dziala")
