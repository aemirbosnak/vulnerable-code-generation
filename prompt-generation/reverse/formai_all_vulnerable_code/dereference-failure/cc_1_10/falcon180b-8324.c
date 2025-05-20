//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_ERROR_MSG_SIZE 256

typedef struct {
    int line_number;
    char *message;
} error_t;

void add_error(error_t *errors, int line_number, const char *message) {
    if (line_number < 1 || line_number > MAX_LINE_SIZE) {
        fprintf(stderr, "Invalid line number: %d\n", line_number);
        exit(1);
    }

    if (strlen(message) > MAX_ERROR_MSG_SIZE) {
        fprintf(stderr, "Error message too long\n");
        exit(1);
    }

    errors[line_number - 1] = (error_t) {
       .line_number = line_number,
       .message = strdup(message)
    };
}

void print_errors(error_t *errors) {
    for (int i = 0; i < MAX_LINE_SIZE; i++) {
        if (errors[i].message!= NULL) {
            fprintf(stderr, "Line %d: %s\n", errors[i].line_number, errors[i].message);
        }
    }
}

int main() {
    error_t errors[MAX_LINE_SIZE];
    memset(errors, 0, sizeof(errors));

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    int line_number = 1;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strcmp(token, "error") == 0) {
                add_error(errors, line_number, "Found error token");
            }
            token = strtok(NULL, " ");
        }
        line_number++;
    }

    fclose(file);

    print_errors(errors);

    return 0;
}