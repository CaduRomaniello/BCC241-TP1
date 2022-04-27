echo "Generating Paired T Test..."
cd ../statistics

for i in 10 100 1000 10000 100000 1000000; do
    mkdir -p n$i
    julia t-paired-algorithm.jl $i InsertionSort > n$i/InsertionSort.out 
    julia t-paired-algorithm.jl $i MergeSort > n$i/MergeSort.out 
    julia t-paired-algorithm.jl $i RadixSort > n$i/RadixSort.out 
done