##I AM NOT THIS GOOD, THIS MAKEFILE WAS HEAVILY INFLUENCED BY THIS
#TUTORIAL https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC = gcc
CFLAGS = -Wall -Wextra -g

# Source files and object files
SRCS = main.c directives.c opcodes.c symbols.c
OBJS = $(SRCS:.c=.o)

# Header files
HEADERS = headers.h directives.h errors.h opcodes.h symbols.h

# Executable name
TARGET = Project2

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean