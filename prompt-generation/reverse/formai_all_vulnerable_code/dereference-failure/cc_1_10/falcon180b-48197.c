//Falcon-180B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MSG_LEN 100

typedef struct {
    char *msg;
    int line;
} Error;

Error errors[MAX_ERRORS];
int num_errors = 0;

void add_error(char *msg, int line) {
    if (num_errors >= MAX_ERRORS) {
        printf("Too many errors! Exiting program...\n");
        exit(1);
    }

    errors[num_errors].msg = strdup(msg);
    errors[num_errors].line = line;
    num_errors++;
}

void print_errors() {
    printf("Found %d errors:\n", num_errors);

    for (int i = 0; i < num_errors; i++) {
        printf("Line %d: %s\n", errors[i].line, errors[i].msg);
    }
}

int main() {
    char *input = "This is a test. \n It has multiple lines.\n";

    int line_num = 1;
    char *line = strtok(input, "\n");

    while (line!= NULL) {
        if (strstr(line, "error")!= NULL) {
            add_error("Found the word 'error' in the input", line_num);
        }

        line_num++;
        line = strtok(NULL, "\n");
    }

    print_errors();

    return 0;
}