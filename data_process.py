# 2018 David DiPaola
# licensed under CC0 (public domain, see https://creativecommons.org/publicdomain/zero/1.0/)

import csv

file = open('data.txt')
file_reader = csv.reader(file, delimiter='\t')
file_data = {}
first = True
for row in file_reader:
    if first:
        first = False
        continue
    row_year  = row[1].strip()
    row_month = row[2].strip()
    row_value = float(row[3].strip())
    if row_year not in file_data:
        file_data[row_year] = {}
    file_data[row_year][row_month] = row_value

data = {}
for year in file_data.keys():
    sum   = 0.0
    count = 0
    for month in file_data[year].keys():
        sum   += file_data[year][month]
        count += 1
    data[year] = sum/count

data_years = sorted(data.keys())
print('const int DATA_STARTYEAR = %s;' % data_years[0])
print('const int DATA_ENDYEAR   = %d;' % (int(data_years[0]) + len(data_years) - 1))
print('')
print('const float DATA[] = {')
for year in data_years:
    print('\t' + '%ff,' % data[year])
print('};')

