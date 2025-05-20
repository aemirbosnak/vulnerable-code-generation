//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKEN_LENGTH 50

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    char token[MAX_TOKEN_LENGTH];
    int number;
    char *endptr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        die("Could not open file");
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        char *token_ptr = strtok(line, " \t,\n");
        while (token_ptr != NULL) {
            if (sscanf(token_ptr, "%d%n", &number, &endptr) != 1) {
                fprintf(stderr, "Invalid number format: %s\n", token_ptr);
                exit(EXIT_FAILURE);
            }
            printf("Processed number: %d\n", number);
            token_ptr = strtok(NULL, " \t,\n");
        }
    }

    if (feof(input_file)) {
        printf("End of file reached\n");
    } else {
        die("Unexpected end of file");
    }

    fclose(input_file);
    return EXIT_SUCCESS;
}