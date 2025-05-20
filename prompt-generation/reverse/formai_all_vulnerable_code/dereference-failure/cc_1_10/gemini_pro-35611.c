//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string tokenizer function
char **tokenize(char *str, char *delim) {
    char **tokens = malloc(sizeof(char *) * 100);
    char *token;
    int i = 0;
    token = strtok(str, delim);
    while (token != NULL) {
        tokens[i++] = token;
        token = strtok(NULL, delim);
    }
    tokens[i] = NULL;
    return tokens;
}

// Custom function to check if a string is a number
int is_number(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Custom function to sanitize user input
char *sanitize(char *str) {
    char **tokens = tokenize(str, " ");
    int i;
    for (i = 0; tokens[i] != NULL; i++) {
        if (!is_number(tokens[i])) {
            tokens[i] = "INVALID";
        }
    }
    char *sanitized = malloc(sizeof(char) * 100);
    strcpy(sanitized, "");
    for (i = 0; tokens[i] != NULL; i++) {
        strcat(sanitized, tokens[i]);
        strcat(sanitized, " ");
    }
    free(tokens);
    return sanitized;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    char *sanitized = sanitize(input);
    printf("Sanitized string: %s\n", sanitized);
    free(sanitized);
    return 0;
}