CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2

.PHONY: all test clean
all: rle

rle: src/rle.c
	$(CC) $(CFLAGS) $< -o $@

test: rle
	bash tests/test.sh

clean:
	rm -f rle
