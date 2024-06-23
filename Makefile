CC = gcc
CFLAGS = -g -Wall
TARGET = p

all: $(TARGET)

$(TARGET): proiect.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) proiect.o main.o

proiect.o: proiect.c proiect.h
	$(CC) $(CFLAGS) -c proiect.c

main.o: main.c proiect.h
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) $(TARGET) *.o
