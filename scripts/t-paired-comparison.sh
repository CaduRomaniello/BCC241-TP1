echo "Generating Paired T Test..."
cd ../statistics

for i in 10 100 1000 10000 100000 1000000; do
    mkdir -p n$i
    julia t-paired-comparison.jl $i InsertionSort MergeSort > n$i/InsertionSort-x-MergeSort.out 
    julia t-paired-comparison.jl $i InsertionSort RadixSort > n$i/InsertionSort-x-RadixSort.out 
    julia t-paired-comparison.jl $i MergeSort RadixSort > n$i/MergeSort-x-RadixSort.out 
done