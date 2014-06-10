
all:	BitonicSort.cc Item.o Bmp.o RainbowItem.o Makefile
	g++ -std=c++11 -Wall -o bitonic_sort BitonicSort.cc Item.o Bmp.o RainbowItem.o

Item.o:	Item.hh Item.cc Makefile
	g++ -std=c++11 -Wall -c Item.cc

RainbowItem.o:	RainbowItem.hh RainbowItem.cc Item.o Makefile
	g++ -std=c++11 -Wall -c RainbowItem.cc

Bmp.o:	Bmp.hh Bmp.cc Makefile
	g++ -std=c++11 -Wall -c Bmp.cc

