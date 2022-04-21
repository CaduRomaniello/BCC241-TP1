run:
	../bin/main $(ARGS)

clean:
	rm -f ../bin/*

create-input:
	julia ./InputGenerator/input.jl $(ARGS)

all: 
	gcc main.c ./insertionSort/insertionSort.c ./mergeSort/mergeSort.c ./radixSort/radixSort.c -o ../bin/main -Wall