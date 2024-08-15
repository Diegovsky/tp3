#!/usr/bin/env python
from math import floor
from random import randint
import argparse
import os

parser = argparse.ArgumentParser()
parser.add_argument('--file', default=None)
parser.add_argument('-k', '--haystack-len', type=int, required=True)
parser.add_argument('-n', '--needle-len', type=int, required=True)
parser.add_argument('--query-count', type=int, default=1)
parser.add_argument('-w', '--worst-case', action='store_true', default=False)

args = parser.parse_args()

file = args.file
needle_len = args.needle_len
haystack_len = args.haystack_len
qsize = args.query_count

os.makedirs("inputs", exist_ok=True)
if file is None:
    file = f'entrada-{haystack_len}.txt'

file = f'inputs/{file}'


with open(file, 'w') as f:
    needle = 'y'*needle_len
    if args.worst_case:
        if haystack_len == needle_len:
            raise ValueError("Haystack length needs to be greater than needle len")
        n = needle[:-1] + 'x'
        n_len = len(n)
        cutoff = haystack_len-needle_len-1
        count = 0
        for _ in range(haystack_len//needle_len):
            d = (count + n_len) - cutoff
            if d >= 0:
                f.write(n[:d])
                break

            count += f.write(n)

        haystack = ''.join(['|', needle, '\n'])
        f.write(haystack)

    else:
        chunk_size = 4096

        total = haystack_len-needle_len
        chunk_count = floor(total/chunk_size)
        scrap = total%chunk_size

        for _ in range(chunk_count):
            f.write('x'*chunk_size)

        f.write('x'*scrap)
        f.write(needle)
        f.write('\n')

    f.write(f"{needle}\n")
    f.write(f"{qsize}\n")
    f.write(f"1 {haystack_len}\n")
    for _ in range(qsize):
        end = randint(0, haystack_len)
        start = randint(0, end)
        f.write(f"{start} {end}\n")

