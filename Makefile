CC = gcc
CFLAGS = -g -Wall -Wextra
CSTANDARD = -std=c11
RM = rm -f


default: all
all: Lab3

lab3: Lab3.c
$(CC) $(CFLAGS) $(CSTANDARD) -o Lab3 Lab3.c 