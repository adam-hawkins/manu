CC = gcc
CFLAGS = -std=c99 -O3 -g -Wall -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -lncurses
CFLAGS += -I lib/
SRC = src/main.c lib/c/c.c lib/go/go.c lib/kotlin/kotlin.c lib/python/python.c 
BIN = bin
NAME = manu

.PHONY: all clean

all: build

run: all
	$(BIN)/$(NAME)

build:
	$(CC) -o $(BIN)/$(NAME) $(SRC) $(CFLAGS)

clean:
	rm -rf $(BIN)/*
