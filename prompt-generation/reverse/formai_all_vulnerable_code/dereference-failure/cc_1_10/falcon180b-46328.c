//Falcon-180B DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MSG_LEN 100

typedef struct {
    char msg[ERROR_MSG_LEN];
    int line;
    int col;
} Error;

int errorCount = 0;
Error errors[MAX_ERRORS];

void addError(char* msg, int line, int col) {
    if (errorCount >= MAX_ERRORS) {
        printf("Error: Too many errors\n");
        exit(1);
    }
    strcpy(errors[errorCount].msg, msg);
    errors[errorCount].line = line;
    errors[errorCount].col = col;
    errorCount++;
}

int main() {
    char* input = "int main() {\n\tprintf(\"Hello, world!\\n\");\n\treturn 0;\n}";
    char* token;
    int line = 1;
    int col = 0;
    while ((token = strtok(input, " \n\t\r"))!= NULL) {
        if (strcmp(token, "printf") == 0) {
            if (col == 7 && strncmp(input + col, "(\"Hello", 7)!= 0) {
                addError("Invalid printf format", line, col);
            }
        } else if (strcmp(token, "return") == 0) {
            if (col == 7 && strncmp(input + col, "0;", 3)!= 0) {
                addError("Invalid return value", line, col);
            }
        }
        col += strlen(token) + 1;
    }
    if (errorCount > 0) {
        printf("Errors:\n");
        for (int i = 0; i < errorCount; i++) {
            printf("%d:%d: %s\n", errors[i].line, errors[i].col, errors[i].msg);
        }
        return 1;
    } else {
        printf("No errors found\n");
        return 0;
    }
}