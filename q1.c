/*
 * Question1.c
 * Author: Karan Singh, Adrian Alting-Mees
 * ID: 190938920, 190743560
 * Email: sing3892@mylaurier.ca, alti3560@mylaurier.ca
 * Repo: https://github.com/AdrianAltingMees/Operating-Systems-Assignment-4
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <semaphore.h>
#include <stdbool.h>



void* thread_run() { //thread run function
	char sequence[100];
	int resources[n_col];
	printf("Safe Sequence is: ");
	fgets(sequence, 100, stdin);
	printf("\n");
	char *token = strtok(sequence, " ");
	int args[5];
	int j = 0;
	while (token != NULL) {
		args[j] = atoi(token);
		token = strtok(NULL, " ");
		j += 1;
	}

	for (int i = 0; i < j; i++) { //looping through threads
    //a whole bunch of print statements
		printf("--> Customer/Thread %d\n", args[i]);
		printf("\tAllocated resources: ");
		for (int k = 0; k < n_col; k++) {
			printf("%d ", allocation_ptr[args[i] * n_col + k]);
			resources[k] = allocation_ptr[args[i] * n_col + k];
		}
		printf("\n\tNeeded: ");
		for (int k = 0; k < n_col; k++) {
			printf("%d ", need_ptr[args[i] * n_col + k]);
		}
		printf("\n\tAvailable: ");
		for (int k = 0; k < n_col; k++) {
			printf("%d ", available_ptr[k]);
		}
		printf("\n");
		printf("\tThread has started\n");
		printf("\tThread has finished\n");
		printf("\tThread is releasing resources\n");
		for (int w = 0; w < n_col; w++) {
			available_ptr[w] += resources[w];
			*((allocation_ptr + args[w] * n_col) + w) -= resources[w];
			*((need_ptr + args[w] * n_col) + w) += resources[w];
		}
		printf("\tNew Available: ");
		for (int z = 0; z < n_col; z++) {
			printf("%d ", available_ptr[z]);
		}
		printf("\n");
	}
	return NULL;
}

bool safety(int *available, int *allocated, int *need) {
	int work[n_col];
	for (int x = 0; x < n_col; x++) {
		work[x] = *(available + x);
	}
	printf("\n");
	bool finish[n_col];
	for (int x = 0; x < n_col; x++) {
		finish[x] = false;
	}
	int safe_seq[n_rows];
	int loopval = 0;
	while (loopval < n_rows) {
		bool found = false;
		for (int x = 0; x < n_rows; x++) {
			if (finish[x] == false) {
				int y = 0;
				for (y = 0; y < n_col; y++) {
					if (*((need + x * n_col) + y) > work[y]) {
						break;
					}
				}
				if (y == n_col) {
					for (int z = 0; z < n_col; z++) {
						work[z] += *((allocated + x * n_col) + z);
					}
					finish[x] = true;

					found = true;
					safe_seq[loopval++] = x;
				}
			}
		}
		if (found == false) {
			printf("System is not in safe state\n");
			return false;
		}
	}
	printf("State is safe, and request is satisfied:\n");
	printf("The SAFE sequence is: ");
	printf("TEST >>> %d\n", safe_seq[4]);
	for (int x = 0; x < n_rows - 1; x++) {
		printf(" P%d ->", safe_seq[x]);
	}
	printf(" P%d\n", safe_seq[n_rows - 1]);
	printf("\n");
	return true;
}

void status(int *available, int *max, int *allocation, int *need) {
	printf("Currently Available resources: ");
	for (int x = 0; x < n_col; x++) {
		printf("%d ", available[x]);
	}
	printf("\n");
	printf("Maximum Resources:\n");
	for (int x = 0; x < n_rows; x++) {
		for (int y = 0; y < n_col; y++) {
			printf("%d ", *((max + x * n_col) + y));
		}
		printf("\n");
	}
	printf("Allocated Resources:\n");
	for (int x = 0; x < n_rows; x++) {
		for (int y = 0; y < n_col; y++) {
			printf("%d ", *((allocation + x * n_col) + y));
		}
		printf("\n");
	}
	printf("Need Resources:\n");
	for (int x = 0; x < n_rows; x++) {
		for (int y = 0; y < n_col; y++) {
			printf("%d ", *((need + x * n_col) + y));
		}
		printf("\n");
	}
}

int sum_arr(int arr[], int n) {
	if (n > 0) {
		int sum = 0;
		for (int x = 0; x < n; x++) {
			sum += arr[x];
		}
		return sum;
	}
	return -1;
}

void get_n_col(char *filename) {
	FILE *in = fopen("sample4_in.txt", "r");
	if (!in) {
		printf("Error in opening input file...exiting with error code -1\n");
		exit(-1);
	}

	char *token;
	if (!feof(in)) {
		char line[100];
		if (fgets(line, 100, in) != NULL) {
			token = strtok(line, ",");
			n_col = 0;
			while (token != NULL) {
				n_col += 1;
				token = strtok(NULL, ",");
			}
		}
	}
	fclose(in);

}

void run_cmd() {
	char command[100];
	bool stillrunning = true;
	while (stillrunning) {
		printf("Enter Command: ");
		fgets(command, 100, stdin);
		char *token = strtok(command, " ");
		int args[n_col + 1];
		token = strtok(NULL, " ");
		int y = 0;
		while (token != NULL) {
			args[y] = atoi(token);
			token = strtok(NULL, " ");
			y += 1;
		}

		for (char *lowercase_cmd = command; *lowercase_cmd; lowercase_cmd++)
			*lowercase_cmd = tolower(*lowercase_cmd);

    //more print statements
		if (strstr(command, "rq") != NULL) {
			printf(
					"\nThe Safe Sequence has started, the algorithm will now verify your requested resources (rq)...\n");
			if (request_resource(args) == false) {
				printf("\nSystem is not in safe state\n\n");
			}
		} else if (strstr(command, "rl") != NULL) {
			printf(
					"The Safe Sequence has started, the algorithm will now verify your released resources (rl)...\n\n");
			release_resource(args);
		} else if (strstr(command, "status") != NULL) {
			status(available_ptr, max_ptr, allocation_ptr, need_ptr);
		} else if (strstr(command, "run") != NULL) {
			printf("run\n");
			thread_run();
		} else if (strstr(command, "quit") != NULL) {
			printf("Exiting...Bye have a nice day! :D\n");
			stillrunning = false;
		} else {
			printf(
					"Invalid Command. Retry and type the following {RQ, RL, Run, Status, Quit} (Lower case for the commands also works)\n");
		}
	}
}
