
all:	BitonicSort.cc Item.o Bmp.o RainbowItem.o
	g++ -o bitonic_sort BitonicSort.cc Item.o Bmp.o RainbowItem.o

Item.o:	Item.hh Item.cc
	g++ -c Item.cc

RainbowItem.o:	RainbowItem.hh RainbowItem.cc Item.o
	g++ -c RainbowItem.cc

Bmp.o:	Bmp.hh Bmp.cc
	g++ -c Bmp.cc

