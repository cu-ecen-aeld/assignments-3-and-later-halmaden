#  Author: Haluk Madencioglu
# For ECEA5305 assignment


CC=gcc
CFLAGS=-g 

#initially the CROSS_COMPILE string is empty
CROSS_COMPILE=""

#if there is any parameter passed with that name, prepend it to CC value
CC := $(CROSS_COMPILE)$(CC)

SOURCES=writer.c
OBJECTS=$(SOURCES:.c=.o)
TARGET = writer

all : $(TARGET)


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	 
	
		

clean: 
	-rm -f *.o  $(TARGET)


