# Operating-Systems-Assignment-4

<h1>Make File</h1>

<div>
    <div>CC = gcc</div>
<div>CFLAGS = -Wall -g -std=gnu99</div>
<div>LDFLAGS = -lrt -lpthread</div>
<div>TARGET = Question1  </div>
<div>OBJFILES = Question1.o</div>
<div>all: $(TARGET)</div>

<div>Question1: Question1.c</div>
	<div>$(CC) $(CFLAGS) -o Question1 Question1.c $(LDFLAGS)</div>
	
<div>runq1: Question1</div>
	<div>./Question1 10 5 7 8</div>
	
<div>clean:</div>
	<div>rm -f $(OBJFILES) $(TARGET) *~ </div>

