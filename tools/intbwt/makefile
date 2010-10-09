OBJS = intbwt.o qsufsort.o
CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: intbwt

intbwt: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o intbwt

clean:
	rm -rf $(OBJS) intbwt