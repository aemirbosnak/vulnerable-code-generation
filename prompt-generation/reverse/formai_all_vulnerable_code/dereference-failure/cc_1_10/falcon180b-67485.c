//Falcon-180B DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Function to print an error message and exit the program */
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    FILE* input_file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    /* Check if the correct number of arguments were provided */
    if (argc!= 2) {
        error("Incorrect number of arguments. Please provide a filename as the only argument.");
    }

    /* Open the input file */
    input_file = fopen(argv[1], "r");

    /* Check if the file was successfully opened */
    if (input_file == NULL) {
        error("Error opening file. Please check the filename and try again.");
    }

    /* Read each line from the input file */
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        /* Check if the line is empty or contains only whitespace */
        if (strlen(line) == 0 || strspn(line, " \t\n") == strlen(line)) {
            continue;
        }

        /* Print the line number and the line of text */
        printf("%d: %s", line_number, line);

        /* Check if the line contains a specific keyword */
        if (strstr(line, "error")!= NULL) {
            error("An error was detected in the input file. Please check the file and try again.");
        }

        /* Increment the line number */
        line_number++;
    }

    /* Close the input file */
    fclose(input_file);

    return 0;
}