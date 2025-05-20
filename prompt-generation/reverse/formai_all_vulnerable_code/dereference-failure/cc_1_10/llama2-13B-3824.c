//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define MAX_LINES 100

// Function to read a line from the input file
static char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    size_t alloc_len = 0;

    while (1) {
        char c = fgetc(file);
        if (c == '\n') {
            break;
        }
        if (c == '\0') {
            break;
        }
        len++;
        alloc_len++;
        line = realloc(line, alloc_len);
        if (line == NULL) {
            break;
        }
        line[len-1] = c;
    }
    line[len] = '\0';
    return line;
}

// Function to parse the input file and extract the relevant information
static void parse_file(FILE *file) {
    char *line;
    size_t len;
    size_t alloc_len = 0;

    // Read the first line of the file
    line = read_line(file);
    if (line == NULL) {
        fprintf(stderr, "Error reading first line of file\n");
        exit(EXIT_FAILURE);
    }

    // Extract the file name and line number from the first line
    char *filename = strtok(line, " ");
    char *lineno = strtok(NULL, " ");

    // Read the remaining lines of the file
    while ((line = read_line(file)) != NULL) {
        // Extract the text from the line
        char *text = strtok(line, " ");

        // Check if the line contains the keyword
        if (strstr(text, "keyword") != NULL) {
            // Print the line number and text
            printf("Line %d: %s\n", lineno, text);
        }

        // Increment the line number
        lineno++;
    }

    // Free the memory allocated for the line buffer
    free(line);
}

int main(void) {
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file
    char *line = read_line(file);
    if (line == NULL) {
        fprintf(stderr, "Error reading first line of file\n");
        exit(EXIT_FAILURE);
    }

    // Parse the input file
    parse_file(file);

    // Close the input file
    fclose(file);

    return EXIT_SUCCESS;
}