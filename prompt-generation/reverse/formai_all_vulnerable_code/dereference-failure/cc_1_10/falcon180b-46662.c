//Falcon-180B DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ERRORS 100

typedef struct {
    char *message;
    int line;
    int column;
} Error;

static int error_count = 0;
static Error errors[MAX_ERRORS];

void add_error(char *message, int line, int column) {
    if (error_count >= MAX_ERRORS) {
        printf("Error: Too many errors.\n");
        exit(1);
    }

    errors[error_count].message = strdup(message);
    errors[error_count].line = line;
    errors[error_count].column = column;

    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Found %d errors:\n", error_count);

    for (int i = 0; i < error_count; i++) {
        printf("%d:%d: %s\n", errors[i].line, errors[i].column, errors[i].message);
    }
}

int main() {
    char *code = "int main() {\n"
                  "    int a = 5;\n"
                  "    printf(\"a = %d\", a);\n"
                  "    return 0;\n"
                  "}\n";

    int line = 1;
    char *token;

    while ((token = strtok(code, "\n"))!= NULL) {
        int column = 1;
        while (*token!= '\0') {
            if (*token == ';') {
                add_error("Missing semicolon", line, column);
            }

            column++;
            token++;
        }

        line++;
    }

    print_errors();

    return 0;
}