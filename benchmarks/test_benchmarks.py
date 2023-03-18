import os

# Compile the benchmarks using makefile
os.system('make all')

# Execute the benchmarks and check for errors
benchmarks = ['build/' + filename[:-4] for filename in os.listdir('./') if filename.endswith('.cpp')]
for benchmark in benchmarks:
    print('Running', benchmark)
    return_code = os.system(benchmark)
    if return_code != 0:
        print('Error: Benchmark', benchmark, 'returned a non-zero exit code:', return_code)

# Clean up build artifacts
os.system('make clean')