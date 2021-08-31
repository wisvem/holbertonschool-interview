#!/usr/bin/python3
""" A module """

from re import search
from sys import stdin, stdout


def main():
    """Main function
    """
    code_list = [200, 301, 400, 401, 403, 404, 405, 500]
    codes = dict.fromkeys(code_list, 0)
    count = 1
    file_size = 0
    regex = (r'\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}'
             r'(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b - '
             r'\[[0-9]{4}-[0-1]{1}[0-9]-{1}[0-9]{2} '
             r'[0-9]{2}:[0-9]{2}:[0-9]{2}\.[0-9]{6}\] '
             r'"GET \/projects\/260 HTTP\/1.1" [0-9]{3} [0-9]{1,4}$'
             )
    try:
        for line in stdin:
            if search(regex, line):
                file_size += int(line.split(' ')[-1])
                code = int(line.split(' ')[-2])
                if code in codes:
                    codes[int(line.split(' ')[-2])] += 1
            if count is 10:
                print('File size: {}'.format(file_size))
                for code in code_list:
                    if codes[code] is not 0:
                        print('{}: {}'.format(code, codes[code]))
                count = 1
                file_size = 0
            else:
                count += 1
    except KeyboardInterrupt:
        print('File size: {}'.format(file_size))
        for code in code_list:
            if codes[code] is not 0:
                print('{}: {}'.format(code, codes[code]))


if __name__ == "__main__":
    main()
