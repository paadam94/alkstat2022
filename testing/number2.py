import numpy as np
from pprint import pprint as pp

# try 40 for massive problem
# 47 for middle
problem=5

path="../../problems/number2/io/%s.in" % problem
arr_s = ''
with open(path, 'r') as f:
    arr_s = f.read().split('\n')
# you don't have to convert it to array
# arr_s.pop(0)
# arr_s.pop(0)
# arr_s.pop()
# arr = np.array([np.array([int(e) for e in row.split()], dtype=np.int32) for row in arr_s])
data = [[int(e) for e in row.split()] for row in arr_s]
# number of rows, and rowlengths
meta_data = list(data.pop(0))
meta_data.append(data.pop(0))
# delete empyt list from end
data = data[:meta_data[0]]

# create the 2d array with counts of negatives and positives in each row
# negatives have - sign
count = list()
for row in data:
    row_count = [np.double(0), np.double(0)]
    for e in row:
        if e < 0:
            row_count[0] -= 1
        if e > 0:
            row_count[1] += 1
    row_count = [e / len(row) for e in row_count]
    count.append(row_count)

count_arr = np.array(count, dtype=np.double)
pp(count_arr)
count_arr = np.ndarray((len(count_arr), 2), dtype=np.double, buffer=count_arr)
pp(count_arr)

