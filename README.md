# Operating-Systems-Assignment-4

# Make File

<p>
CC = gcc</div>
CFLAGS = -Wall -g -std=gnu99</div>
LDFLAGS = -lrt -lpthread</div>
TARGET = Question1  </div>
OBJFILES = Question1.o</div>
all: $(TARGET)</div>

Question1: Question1.c</div>
	$(CC) $(CFLAGS) -o Question1 Question1.c $(LDFLAGS)</div>
	
runq1: Question1
	./Question1 10 5 7 8
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~ 
</p>
