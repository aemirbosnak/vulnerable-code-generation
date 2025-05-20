//FormAI DATASET v1.0 Category: Syntax parsing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_syntax(char *input_str);

int main() {

    char input[100];
    printf("Enter a C syntax statement: ");
    fgets(input, 100, stdin);

    if (check_syntax(input)) {
        printf("The syntax is correct. Congrats!\n");
    } else {
        printf("Uh oh, the syntax is incorrect. Try again.\n");
    }

    return 0;
}

bool check_syntax(char *input_str) {
    int len = strlen(input_str);
    if (input_str[len-1] != '\n') {
        return false;
    }

    char *tokens[10];
    int tok_count = 0;

    char *token = strtok(input_str, " ");
    while (token != NULL && tok_count < 10) {
        tokens[tok_count++] = token;
        token = strtok(NULL, " ");
    }

    if (strcmp(tokens[0], "int") != 0) {
        return false;
    }

    if (tokens[1][strlen(tokens[1])-1] != ';') {
        return false;
    }

    for (int i = 0; i < strlen(tokens[1]); i++) {
        if (tokens[1][i] == '=') {
            return true;
        }
    }

    return false;
}