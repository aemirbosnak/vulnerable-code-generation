//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERRORS 100

typedef struct {
    char *filename;
    int line_number;
    char *message;
} Error;

int num_errors = 0;
Error errors[MAX_ERRORS];

void add_error(char *filename, int line_number, char *message) {
    if (num_errors >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors, cannot add more.\n");
        return;
    }

    errors[num_errors].filename = filename;
    errors[num_errors].line_number = line_number;
    errors[num_errors].message = message;

    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Found %d errors:\n", num_errors);

    for (int i = 0; i < num_errors; i++) {
        printf("Error %d: %s:%d - %s\n", i+1, errors[i].filename, errors[i].line_number, errors[i].message);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Error: Usage: %s <filename> <error_message>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *error_message = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

        int num_errors_in_line = 0;
        char *pos = line;
        while ((pos = strstr(pos, error_message))!= NULL) {
            num_errors_in_line++;
            add_error(filename, line_number, error_message);
            pos += strlen(error_message);
        }

        if (num_errors_in_line > 0) {
            printf("Found %d errors in line %d:\n", num_errors_in_line, line_number);
        }

        line_number++;
    }

    fclose(file);

    if (num_errors > 0) {
        print_errors();
        return 1;
    } else {
        printf("No errors found.\n");
        return 0;
    }
}