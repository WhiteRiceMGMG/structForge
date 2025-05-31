CC = gcc
TARGET = maim.out
OBJS = main.o database.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm

main.o: main.c database.h
	$(CC) -c main.c -o main.o

database.o: database.c database.h
	$(CC) -c database.c -o database.o

clean:
	rm -f $(TARGET) $(OBJS)
