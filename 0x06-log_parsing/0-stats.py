#!/usr/bin/python3
""" A module """

from re import search
from sys import stdin, stdout


def main():
    """Main function
    """
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
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
                print(f'File size: {file_size}')
                for k, v in codes.items():
                    if v is not 0:
                        print(f'{k}: {v}')
                count = 1
                file_size = 0
            else:
                count += 1
    except KeyboardInterrupt:
        print(f'File size: {file_size}')
        for k, v in codes.items():
            if v is not 0:
                print(f'{k}: {v}')


if __name__ == "__main__":
    main()
