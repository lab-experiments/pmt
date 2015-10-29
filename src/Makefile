## Version 1.0 ##
############################# Makefile ##########################
CC=g++
CFLAGS=-W -Wall -ansi -pedantic
EXEC=pmt
SRC=$(wildcard *.cpp) # equivale a main.c search_file.c exact_matching.c approximate_matching.c
OBJ=$(SRC:.cpp=.o) # equivale a main.o search_file.o exact_matching.o approximate_matching.o
HEADERS=$(wildcard *.h) #equivale a search_file.h exact_matching.h exact_matching.h

all: pmt
pmt: $(OBJ)
# $@ = pmt:
# $^ = main.o search_file.o exact_matching.o approximate_matching.o
	$(CC) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CC) -o $@ -c $< $(CFLAGS)
.PHONY: clean mrproper
clean:
	rm -rf *.o pmt *~
mrproper: clean
	rm -rf EXEC

#tar:
#	tar cvjf pmt.tar.bz2 $(SRC) $(HEADERS)

#Os comandos no console são:
#    make
#    make install
#    make clean
#    make mrproper .Para apagar os binarios.
