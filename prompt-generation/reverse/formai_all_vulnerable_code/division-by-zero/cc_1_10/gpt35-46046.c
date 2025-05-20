//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: irregular
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 100

int compute(char *input);

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Irregular Calculator\n");
    printf("Enter an expression to compute or type 'quit' to exit:\n\n");

    while (1) {
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strcmp(input, "quit\n") == 0)
            break;

        int result = compute(input);

        printf("\nResult: %d\n\n", result);
    }

    return 0;
}

int compute(char *input) {
    char *token;
    char *tokens[MAX_INPUT_SIZE/2];
    int num_tokens = 0;

    token = strtok(input, " ");

    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    int i = 0, result = 0, previous_operation = 0;

    while (i < num_tokens) {
        if (strcmp(tokens[i], "+") == 0) {
            previous_operation = 1;
            i++;
        } else if (strcmp(tokens[i], "-") == 0) {
            previous_operation = 2;
            i++;
        } else if (strcmp(tokens[i], "*") == 0) {
            previous_operation = 3;
            i++;
        } else if (strcmp(tokens[i], "/") == 0) {
            previous_operation = 4;
            i++;
        } else {
            int term = atoi(tokens[i]);

            if (previous_operation == 0) {
                result = term;
            } else if (previous_operation == 1) {
                result += term;
            } else if (previous_operation == 2) {
                result -= term;
            } else if (previous_operation == 3) {
                result *= term;
            } else if (previous_operation == 4) {
                result /= term;
            }

            previous_operation = 0;
            i++;
        }
    }

    return result;
}