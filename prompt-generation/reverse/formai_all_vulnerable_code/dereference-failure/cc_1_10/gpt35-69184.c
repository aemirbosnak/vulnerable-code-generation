//FormAI DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000
#define MAX_LENGTH 100

int main(int argc, char const *argv[]) {
	// Define variables for file input
	FILE *input_file;
	char *input_filename;
	char input_line[MAX_LENGTH];
	int line_count = 0;
	char **lines = (char**) malloc(MAX_LINES * sizeof(char*));

	// Define variables for text processing
	char *search_string;
	char *replace_string;
	int search_length;
	int replace_length;
	int i, j;

	// Handle command line arguments
	if (argc < 3) {
		printf("Usage: text_processor search_string replace_string input_file\n");
		return 1;
	}
	search_string = argv[1];
	replace_string = argv[2];
	search_length = strlen(search_string);
	replace_length = strlen(replace_string);
	input_filename = argv[3];

	// Open input file
	input_file = fopen(input_filename, "r");
	if (input_file == NULL) {
		printf("Error opening input file: %s\n", input_filename);
		return 1;
	}

	// Read input file line by line
	while (fgets(input_line, MAX_LENGTH, input_file) != NULL) {
		// Allocate memory for line and copy contents
		lines[line_count] = (char*) malloc(MAX_LENGTH * sizeof(char));
		strcpy(lines[line_count], input_line);
		line_count++;
	}

	// Close input file
	fclose(input_file);

	// Replace all occurrences of search string with replace string
	for (i = 0; i < line_count; i++) {
		for (j = 0; j < strlen(lines[i]); j++) {
			if (strncmp(lines[i] + j, search_string, search_length) == 0) {
				strncpy(lines[i] + j, replace_string, replace_length);
				j += replace_length - 1;
			}
		}
	}

	// Print processed lines to stdout
	for (i = 0; i < line_count; i++) {
		printf("%s", lines[i]);
		free(lines[i]);
	}
	free(lines);

	return 0;
}