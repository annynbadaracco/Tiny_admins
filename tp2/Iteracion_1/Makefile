# Makefile

# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -shared

# Target name
TARGET = conversion.so

# Source file
SRC = conversion.c

# Default rule
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean rule
clean: 
	rm -f $(TARGET)