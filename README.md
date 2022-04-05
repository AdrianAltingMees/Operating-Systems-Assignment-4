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
	rm -f $(OBJFILES) $(TARGET) *~ <br>
```

# Screenshots


![cp386_1](https://user-images.githubusercontent.com/84096995/161671949-d013670d-8b55-41ac-aaa6-830d085a6026.png)<br>
![cp386_2](https://user-images.githubusercontent.com/84096995/161671952-a07ace36-f2d9-42c5-bc6f-22c83341fc8a.png)<br>
![cp386_3](https://user-images.githubusercontent.com/84096995/161671957-c51772f1-9f17-4deb-b157-9916407c4233.png)<br>
![cp386_4](https://user-images.githubusercontent.com/84096995/161671960-f5642b8c-e22a-4cf7-86af-32f4aa5fa916.png)<br>
![cp386_5](https://user-images.githubusercontent.com/84096995/161671968-c4d239a2-0104-4b23-9ce0-2a21e4d68a9d.png)<br>
![cp386_6](https://user-images.githubusercontent.com/84096995/161671974-5bf4f83f-22fe-40c5-a221-ae7c4ae32a70.png)<br>

# Individual Contribution

All functions were completed together, but here:
 
```int readFileCustomers(char *fileName);``` - Adrian, Karan

```void readFileSequences(char *fileName, int max[n_rows][n_col]);``` - Adrian, Karan

```bool safety(int *available, int *allocated, int *need);``` - Adrian, Karan

```int sum_arr(int arr[], int n);``` - Adrian, Karan

```void get_n_col(char *filename);``` - Adrian, Karan

```int bankersalgo();``` - Adrian, Karan 

```void run_cmd();``` - Adrian, Karan 

```int request_resource(int args[]);``` - Adrian, Karan 

```int release_resource(int args[]);``` - Adrian, Karan 

```void status(int *available, int *max, int *allocation, int *need);``` - Adrian, Karan

# Features

Commands / Call for command

Request Resource / RQ

Release Resource / RL

Status / States

Run / Run

Exit / Exit

# Tests

Please See Screenshots.

# About the Developers

Adrian and Karan are both Varisity Atheletes in the Computer Science (BSc) program at Wilfrid Laurier University.

The sole reason, motivation and drive to do this project was because it was part of a mandatory course at Laurier, and was worth marks.

Links to both Githubs are on the repo.

# Lisence

```
MIT License

Copyright (c) 2022 Adrian Alting-Mees. Karan Singh

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.```
