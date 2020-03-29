import json
import csv


def save_data(filename, data):
    """
    :param filename: name of file to save data
    :param data: data to save to file
    :return: nothing
    """
    with open(filename, 'w') as outfile:
        json.dump(data, outfile)


def load_data(filename):
    """
    :param filename: name of json file
    :return: data from json file
    """
    with open(filename) as json_file:
        data = json.load(json_file)

    return data


def prepare_and_save(emp_list, file_name):
    employ = [i.__dict__ for i in emp_list]
    save_data(file_name, employ)


def save_csv(filename, emp_list):
    fieldnames = ['id', 'name', 'surname', 'last_enter']
    with open(filename, 'w') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for i in emp_list:
            writer.writerow({'id': i.id,
                             'name': i.name,
                             'surname': i.surname,
                             'last_enter': i.timesheet[-1] if i.timesheet != [] else ''})
