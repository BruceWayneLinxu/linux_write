#!/usr/bin/python2.7
# -*- coding: utf-8 -*-


import re


class ConfigData(object):
    """docstring for ConfigData"""
    def __init__(self, read_file_path, write_file_path):
        super(ConfigData, self).__init__()
        self.read_file_path = read_file_path
        self.write_file_path = write_file_path
        self.config_data = {}
        self.file = None

    def get_citycode_name(self):
        try:
            self.file = open(self.read_file_path, 'r')
            for each_line in self.file:
                try:
                    each_line = each_line.strip()
                    match_code = re.match(r'\d{6}', each_line)
                    if match_code:
                        citycode = match_code.group()
                    match_name = re.match(r'[u4e00-u9fa5]+', each_line)
                    if match_name:
                        cityname = match_name.group()
                    if match_code and match_name:
                        self.config_data[citycode] = cityname
                        print('%s\t%s' % (citycode, cityname))
                except ValueError:
                    pass
            self.file.close()
        except IOError:
            print('The %s is missing!' % self.read_file_path)

    def output_data_info(self):
        try:
            self.file = open(self.write_file_path, 'wb')
            for k, v in self.config_data.items():
                self.file.write('%s\t%s\n' % (k, v))
            self.file.close()
        except IOError:
            print('The %s is missing!' % self.write_file_path)


def test():
    data_read_path = 'rawdata.txt'
    data_write_path = 'result.txt'
    citycode_file = ConfigData(data_read_path, data_write_path)
    citycode_file.get_citycode_name()
    citycode_file.output_data_info()


if __name__ == '__main__':
    test()
