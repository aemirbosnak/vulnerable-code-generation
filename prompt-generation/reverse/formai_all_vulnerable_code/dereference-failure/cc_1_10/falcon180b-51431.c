//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_ERROR_LENGTH 100

typedef struct {
    char message[MAX_ERROR_LENGTH];
    int line_number;
} Error;

Error* create_error(const char* message, int line_number) {
    Error* error = (Error*) malloc(sizeof(Error));
    if (error == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    strncpy(error->message, message, MAX_ERROR_LENGTH - 1);
    error->message[MAX_ERROR_LENGTH - 1] = '\0';
    error->line_number = line_number;
    return error;
}

void free_error(Error* error) {
    free(error);
}

void print_error(const Error* error) {
    printf("Error %d: %s\n", error->line_number, error->message);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        Error* error = create_error("Could not open input file", __LINE__);
        print_error(error);
        free_error(error);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        int length = strlen(line);
        if (line[length - 1]!= '\n') {
            Error* error = create_error("Line too long", __LINE__);
            print_error(error);
            free_error(error);
            return 1;
        }
        line[--length] = '\0'; // Remove newline character

        if (line[0] == '#') {
            // Comment line, skip
        } else if (sscanf(line, "%s %s", "NAME", "Sherlock Holmes")!= 2) {
            Error* error = create_error("Invalid NAME field", __LINE__);
            print_error(error);
            free_error(error);
            return 1;
        } else {
            // Valid line, do something with it
        }
        line_number++;
    }

    fclose(input_file);
    return 0;
}