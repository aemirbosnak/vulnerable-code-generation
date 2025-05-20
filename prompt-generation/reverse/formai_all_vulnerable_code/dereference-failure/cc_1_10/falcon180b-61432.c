//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TOKEN_SIZE 256
#define MAX_VARIABLES 100

char *tokens[MAX_VARIABLES];
int num_tokens;

int is_operator(char *token) {
    if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
        return 1;
    return 0;
}

int is_number(char *token) {
    int i;
    for (i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i]))
            return 0;
    }
    return 1;
}

int precedence(char *op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 1;
    else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
        return 2;
    return -1;
}

void tokenize(char *input) {
    char *token;
    int i = 0;
    num_tokens = 0;

    while ((token = strtok(input, " "))!= NULL) {
        if (num_tokens >= MAX_VARIABLES) {
            printf("Error: Too many variables\n");
            exit(1);
        }
        tokens[num_tokens++] = strdup(token);
    }
}

int evaluate_expression(int index) {
    char *op;
    int left, right, result;

    if (index >= num_tokens)
        return atoi(tokens[index]);

    op = tokens[index];
    left = evaluate_expression(index + 1);
    right = evaluate_expression(index + 2);

    if (is_operator(op)) {
        switch (precedence(op)) {
            case 1:
                result = left + right;
                break;
            case 2:
                result = left * right;
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(1);
        }
    } else {
        result = atoi(op);
    }

    return result;
}

int main(int argc, char *argv[]) {
    char input[TOKEN_SIZE];

    printf("Enter an arithmetic expression: ");
    fgets(input, TOKEN_SIZE, stdin);

    tokenize(input);

    printf("Result: %d\n", evaluate_expression(0));

    return 0;
}