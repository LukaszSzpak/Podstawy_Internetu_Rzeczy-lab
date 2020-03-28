class Employee(object):
    def __init__(self, id, name, surname, timesheet):
        self.id = id
        self.name = name
        self.surname = surname
        self.timesheet = timesheet

    def add_new_time(self, new_date):
        self.timesheet.append(new_date)

    def to_string(self):
        return str(self.id) + ' ' + self.name + ' ' + self.surname
