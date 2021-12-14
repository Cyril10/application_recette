.PHONY: test clean mrcleaner
.DEFAULT_GOAL: data_mgnt

CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=data_mgnt
SRC= tree.c main.c
all: $(EXEC)

data_mgnt: tree.o main.o
	@echo "Compilation :"
	$(CC) -o data_mgnt tree.o main.o $(LDFLAGS)

data_mgnt.o: data_mgnt.c
	$(CC) -o tree.o -c tree.c $(CFLAGS)

main.o: main.c tree.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	@rm -rf *.o

mrscleaner: clean
	@rm -rf $(EXEC)

## lance les tests unitaires
test:
	@echo "EXECUTION :"
	@./data_mgnt
