//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool is_valid_input(char *input);
char *sanitize_input(char *input);

int main() {
    char input[MAX_LENGTH];
    char *sanitized_input;

    printf("Enter a string to sanitize: ");
    fgets(input, MAX_LENGTH, stdin);

    sanitized_input = sanitize_input(input);
    if (sanitized_input!= NULL) {
        printf("Sanitized input: %s\n", sanitized_input);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}

bool is_valid_input(char *input) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        if (!isprint(input[i])) {
            return false;
        }
    }
    return true;
}

char *sanitize_input(char *input) {
    int i, j;
    char *sanitized_input;
    sanitized_input = malloc(MAX_LENGTH * sizeof(char));
    if (sanitized_input == NULL) {
        return NULL;
    }
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isprint(input[i])) {
            sanitized_input[j] = input[i];
            j++;
        }
    }
    sanitized_input[j] = '\0';
    return sanitized_input;
}