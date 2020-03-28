import json


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
