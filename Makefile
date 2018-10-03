#Compiler used
CC = gcc

#The target that will be compiled
TARGET = ep1

#Compiler flags
CFLAGS = -g -Wall

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET).o
	./$(TARGET).o

clean:
	$(RM) $(TARGET)
