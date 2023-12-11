import csv
import re

# Function to extract values from the result string
def extract_values(result):
    values = {}
    match = re.search(r'm = (\d+), n = (\d+), p = (\d+)', result)
    if match:
        values['m'] = int(match.group(1))
        values['n'] = int(match.group(2))
        values['p'] = int(match.group(3))

    match = re.search(r'Execution Time \(Standard Sequential\): (\d+\.\d+) seconds', result)
    if match:
        values['Standard Sequential'] = float(match.group(1))

    match = re.search(r'Execution Time \(Standard Parallel\): (\d+\.\d+) seconds', result)
    if match:
        values['Standard Parallel'] = float(match.group(1))

    match = re.search(r'Execution Time \(Transposed Sequential\): (\d+\.\d+) seconds', result)
    if match:
        values['Transposed Sequential'] = float(match.group(1))

    match = re.search(r'Execution Time \(Transposed Parallel\): (\d+\.\d+) seconds', result)
    if match:
        values['Transposed Parallel'] = float(match.group(1))

    return values

# Read the input file
with open('matrix_multiplication_results.txt', 'r') as file:
    lines = file.readlines()

# Parse the results and write to CSV
with open('output.csv', 'w', newline='') as csv_file:
    fieldnames = ['m', 'n', 'p', 'Standard Sequential', 'Standard Parallel', 'Transposed Sequential', 'Transposed Parallel']
    writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
    writer.writeheader()

    result = ""
    for line in lines:
        if line.startswith("Standard Sequential Result:") and result:
            values = extract_values(result)
            writer.writerow(values)
            result = ""
        result += line

    # Write the last result
    if result:
        values = extract_values(result)
        writer.writerow(values)