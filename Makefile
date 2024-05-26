##########################################################################
# File:        Makefile
# Description: Makefile for compiling the maze project.
# Author:      edwrad sila
# Date:        26/05/2024
##########################################################################
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -Wno-maybe-uninitialized -Iinclude
LDFLAGS = -lSDL2
SRC = src/main.c src/raycasting.c src/raycasting_helpers.c
OBJ = $(SRC:.c=.o)
TARGET = maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
