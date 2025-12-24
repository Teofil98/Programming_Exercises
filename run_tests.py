import sys
import os
import json
import subprocess
from colorama import Fore, Style

LANGS = ['Fortran']

def print_usage():
    print(f"python3 {sys.argv[0]} [solution|template] {{verbose}} {{stop}}")
    exit(0)

def generate_shared_libs():
    os.chdir('.libraries')
    for lang in LANGS:
        os.chdir(f'{lang}')
        subprocess.run(['make'])
        os.chdir('..')
    os.chdir('..')


def run_tests(tests, filename, verbose, stop):
    for i in range(len(tests)):
        test = tests[i]
        if os.path.exists('input.txt'):
            os.remove('input.txt')
        if os.path.exists('output.txt'):
            os.remove('output.txt')

        out_channel = subprocess.DEVNULL

        # create input file
        with open('input.txt', 'w') as f:
            f.write(test['input'])

        subprocess.run(['make', 'clean'],
                       stdout=out_channel)
        solutions = [x.split('.')[0] for x in os.listdir('.') if x.startswith(filename)]
        for solution in solutions:
            subprocess.run(['make', 'release', f'IMPL={solution}'],
                       stdout=out_channel)
            subprocess.run(['make', 'run'],
                       stdout=out_channel)
            with open('output.txt', 'r') as f:
                val = f.read().strip()
                if val == test['result']:
                    print(f"\t\tTest {i} - {solution}: {Fore.GREEN} Pass {Style.RESET_ALL}")
                else:
                    print(f"\t\tTest {i} - {solution}: {Fore.RED} Fail {Style.RESET_ALL}")
                    if verbose:
                        print('--------------------------')
                        print(f'Input: {test["input"]}')
                        print(f'Expected: {test["result"]}')
                        print(f'Got: {val}')
                        print('--------------------------')

                    if stop:
                        exit(0)


# run each solution program

# check output.txt file

def main():
    if (len(sys.argv) - 1) < 1:
        print_usage()

    if sys.argv[1] not in ["solution", "template"]:
        print_usage()

    verbose = False
    if len(sys.argv) > 2 and sys.argv[2] == 'verbose':
        verbose = True

    stop = False
    if len(sys.argv) > 3 and sys.argv[3] == 'stop':
        stop = True

    filename=sys.argv[1]

    generate_shared_libs()

    directories = [x  for x in os.listdir('.') if os.path.isdir(x) and x[0] != '.' ]

    for directory in directories:
        print(f'Running tests for {directory}')
        path = './' + directory
        problems = os.listdir(path)
        for problem in problems:
            print(f'\t{problem}:')
            path = path + '/' + problem
            os.chdir(path)
            # read inputs and expected outputs
            tests = []
            with open('tests.json') as f:
                tests = json.load(f)

            # navigate to each language
            for lang in LANGS:
                os.chdir('./src/' + lang)

                run_tests(tests, filename, verbose, stop)

                os.chdir('../..')
        os.chdir('..')



if __name__ == "__main__":
    main()
