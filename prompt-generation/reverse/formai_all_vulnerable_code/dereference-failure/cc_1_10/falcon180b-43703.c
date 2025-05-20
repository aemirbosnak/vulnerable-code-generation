//Falcon-180B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to print an error message and exit the program
void error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to read a file into memory
char *read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("Error opening file");
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        error("Error allocating memory");
    }

    if (fread(buffer, file_size, 1, file)!= 1) {
        error("Error reading file");
    }

    fclose(file);
    buffer[file_size] = '\0';

    return buffer;
}

// Function to count the number of words in a string
int count_words(char *string) {
    int count = 0;
    char *token = strtok(string, " ");

    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to print the longest line in a string
void print_longest_line(char *string) {
    int max_line_length = 0;
    int current_line_length = 0;
    char *current_line = strtok(string, "\n");

    while (current_line!= NULL) {
        current_line_length = strlen(current_line);

        if (current_line_length > max_line_length) {
            max_line_length = current_line_length;
        }

        current_line = strtok(NULL, "\n");
    }

    printf("Longest line: %d characters\n", max_line_length);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        error("Usage:./program filename");
    }

    char *filename = argv[1];
    char *file_contents = read_file(filename);

    int num_words = count_words(file_contents);
    printf("Number of words: %d\n", num_words);

    print_longest_line(file_contents);

    free(file_contents);
    return 0;
}