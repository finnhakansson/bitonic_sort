
all:	BitonicSort.cc Item.o Bmp.o
	g++ -o bitonic_sort BitonicSort.cc Item.o Bmp.o

Item.o:	Item.hh Item.cc
	g++ -c Item.cc

Bmp.o:	Bmp.hh Bmp.cc
	g++ -c Bmp.cc

