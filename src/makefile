run:
	../bin/main $(SIZE) $(ALG) > ../data/output/n$(SIZE)/$(ALG).out

clean:
	rm -f ../bin/main

create-input:
	julia ./InputGenerator/input.jl $(ARGS)

test: clean all
	../bin/main $(SIZE) $(ALG)

all: 
	gcc ./main.c ./insertionSort/insertionSort.c ./mergeSort/mergeSort.c ./radixSort/radixSort.c -o ../bin/main -Wall