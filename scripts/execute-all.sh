cd ../src/
make all
for i in 10 100 1000 10000 100000 1000000; do
    make run SIZE="$i" ALG="MergeSort"
    make run SIZE="$i" ALG="RadixSort"
    # make run SIZE="$i" ALG="InsertionSort"
done