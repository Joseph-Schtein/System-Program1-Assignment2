CC=gcc
AR=ar 
OBJECT_MY_BANK=myBank.o
OBJECTS_MAIN=main.o
FLAGS = -Wall -g

all:	 mybank main

main:	 $(OBJECTS_MAIN) mybank
	 $(CC) $(FLAGS) -o main $(OBJECTS_MAIN) libmyBank.a 

mybank: libmyBank.a
libmyBank.a: $(OBJECT_MY_BANK)
	 $(AR) -rcs libmyBank.a $(OBJECT_MY_BANK) 

myBank.o: myBank.c myBank.h
	 $(CC) $(FLAGS) -c -fPIC myBank.c
main.o:	 main.c myBank.h
	 $(CC) $(FLAGS) -c main.c
.PHONY: 
	all clean mybank
clean: 
	 rm -rf *.o *.a main 
