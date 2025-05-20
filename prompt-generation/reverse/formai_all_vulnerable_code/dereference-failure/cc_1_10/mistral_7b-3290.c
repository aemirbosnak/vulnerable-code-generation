//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 1024
#define WHITESPACE " \t\r\n\v\f"

void sanitize_input(char *input) {
    int i = 0, j = 0;

    while (input[i] != '\0') {
        if (isalnum(input[i]) || strchr(WHITESPACE, input[i]) != NULL) {
            input[j++] = input[i];
        }
        i++;
    }

    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    size_t n = 0;
    char *line = NULL;

    printf("Enter your input: ");

    while (getline(&line, &n, stdin) > 0) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        sanitize_input(line);

        printf("Sanitized Input: %s\n", line);

        free(line);
        line = NULL;

        printf("Do you want to enter another input? (y/n): ");
        fgets(input, sizeof(input), stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "n") == 0) {
            break;
        }
    }

    return 0;
}