//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define custom error codes */
#define ERROR_FILE_NOT_FOUND 1
#define ERROR_OUT_OF_MEMORY 2

/* define a function to handle errors */
void handle_error(int error_code) {
	switch (error_code) {
		case ERROR_FILE_NOT_FOUND:
			printf("Error: File not found\n");
			break;
		case ERROR_OUT_OF_MEMORY:
			printf("Error: Out of memory\n");
			break;
		default:
			printf("Unknown error\n");
			break;
	}
	exit(error_code);
}

int main() {
	FILE *fp;
	char *data;
	int data_size, read_size;

	/* Open the input file */
	fp = fopen("input.txt", "r");
	if (fp == NULL) {
		handle_error(ERROR_FILE_NOT_FOUND);
	}

	/* Allocate memory for input data */
	data_size = 1024;
	data = malloc(data_size);
	if (data == NULL) {
		handle_error(ERROR_OUT_OF_MEMORY);
	}

	/* Load the input data */
	read_size = fread(data, 1, data_size - 1, fp);
	if (read_size == 0) {
		/* Handle read error */
		printf("Error while reading data\n");
		exit(EXIT_FAILURE);
	}

	/* Null-terminate the data */
	data[read_size] = '\0';

	/* Display the input data */
	printf("Input data: %s\n", data);

	/* Free the allocated memory */
	free(data);

	/* Close the input file */
	fclose(fp);

	return 0;
}