
all:	BitonicSort.cc Item.o Bmp.o RainbowItem.o
	g++ -std=c++11 -o bitonic_sort BitonicSort.cc Item.o Bmp.o RainbowItem.o

Item.o:	Item.hh Item.cc
	g++ -std=c++11 -c Item.cc

RainbowItem.o:	RainbowItem.hh RainbowItem.cc Item.o
	g++ -std=c++11 -c RainbowItem.cc

Bmp.o:	Bmp.hh Bmp.cc
	g++ -std=c++11 -c Bmp.cc

