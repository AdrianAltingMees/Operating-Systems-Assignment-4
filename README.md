# Operating-Systems-Assignment-4

# Make File
```
CC = gcc <br>
CFLAGS = -Wall -g -std=gnu99 <br>
LDFLAGS = -lrt -lpthread <br>
TARGET = Question1 <br>
OBJFILES = Question1.o <br>
all: $(TARGET) <br>

Question1: Question1.c <br>
	$(CC) $(CFLAGS) -o Question1 Question1.c $(LDFLAGS) <br>

runq1: Question1 <br>
	./Question1 10 5 7 8 <br>

clean: <br>
	rm -f $(OBJFILES) $(TARGET) *~ <br>\
```
