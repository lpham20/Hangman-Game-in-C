CFLAGS=-std=c99 -Wall
CC=gcc

random_sequence: hangman.o main.o
	$(CC) $(CFLAGS) hangman.o main.o -o hangman

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

hangman.o: hangman.h hangman.c
	$(CC) $(CFLAGS) -c hangman.c

clean:
	rm -f random_sequence *.o
