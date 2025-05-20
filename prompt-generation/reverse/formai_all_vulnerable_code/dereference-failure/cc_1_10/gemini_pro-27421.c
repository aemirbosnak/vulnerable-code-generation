//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <errno.h>

#define INPUT_BUFFER_SIZE 1024
#define MAX_ALLOWED_LINES INT_MAX

int main(void) {
    char *input_buffer = NULL;
    size_t input_buffer_size = 0;
    size_t input_buffer_length = 0;
    int line_number = 0;
    char *input_line = NULL;
    size_t input_line_size = 0;
    size_t input_line_length = 0;

    // Allocate input buffer
    if (getline(&input_buffer, &input_buffer_size, stdin) == -1) {
        perror("getline");
        return EXIT_FAILURE;
    }

    // Get each input line and check if it's a valid number or empty
    while (line_number < MAX_ALLOWED_LINES && getline(&input_line, &input_line_size, stdin) != -1) {
        input_line_length = strlen(input_line);

        if (input_line_length == 0 || input_line_length == 1 && input_line[0] == '\n') {
            // Empty line, continue to the next line
            continue;
        }

        // Remove whitespace from the line
        input_line = strtok(input_line, " \t\n");
        while (input_line) {
            // Check if the line is a valid number
            errno = 0;
            long input_number = strtol(input_line, NULL, 10);

            if (errno == ERANGE) {
                // Number is out of range, print error and continue to the next line
                fprintf(stderr, "Error: Number '%s' is out of range\n", input_line);
                input_line = strtok(NULL, " \t\n");
                continue;
            } else if (errno != 0) {
                // Some other error occurred, print error and continue to the next line
                perror("strtol");
                input_line = strtok(NULL, " \t\n");
                continue;
            }

            // Number is valid, print it
            printf("%ld\n", input_number);

            // Get the next whitespace-separated token
            input_line = strtok(NULL, " \t\n");
        }

        line_number++;
    }

    // Free input buffer and line
    free(input_buffer);
    free(input_line);

    return EXIT_SUCCESS;
}