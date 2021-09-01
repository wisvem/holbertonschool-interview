#!/usr/bin/python3
""" A module """

from sys import stdin, stdout


def main():
    """Main function
    """
    code_list = ["200", "301", "400", "401", "403", "404", "405", "500"]
    codes = dict.fromkeys(code_list, 0)
    count = 1
    file_size = 0

    try:
        for line in stdin:
            try:
                file_size += int(line.split(' ')[-1])
            except:
                pass
            code = line.split(' ')[-2]
            if code in codes:
                codes[line.split(' ')[-2]] += 1
            if count is 10:
                print('File size: {}'.format(file_size))
                for code in code_list:
                    if codes[code] is not 0:
                        print('{}: {}'.format(code, codes[code]))
                count = 1
            else:
                count += 1
    except KeyboardInterrupt:
        print('File size: {}'.format(file_size))
        for code in code_list:
            if codes[code] is not 0:
                print('{}: {}'.format(code, codes[code]))
    if count < 10:
        print('File size: {}'.format(file_size))
        for code in code_list:
            if codes[code] is not 0:
                print('{}: {}'.format(code, codes[code]))


if __name__ == "__main__":
    main()
