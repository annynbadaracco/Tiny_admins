# Makefile

# Compiler
CC = gcc
AS = as

# Flags
CFLAGS = -Wall -g -O0 -fPIC
ASFLAGS = --64 -g

# Target name
TARGET = conversion.so
OBJS = conversion.o suma.o

# Default rule
all: $(TARGET)

# Assemble suma.s
suma.o: suma.s
	$(AS) $(ASFLAGS) -o $@ $<

# Compile conversion.c
conversion.o: conversion.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Build rule
$(TARGET): $(OBJS)
	$(CC) -shared -o $@ $(OBJS)

# Clean rule
clean: 
	rm -f $(OBJS) $(TARGET)