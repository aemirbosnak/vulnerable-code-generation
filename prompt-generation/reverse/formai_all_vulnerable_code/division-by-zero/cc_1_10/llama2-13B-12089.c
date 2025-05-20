//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 100
#define MAX_NUMBERS 20

typedef struct {
    int num;
    char op;
} operation;

operation operations[MAX_OPERATIONS];
int num_operations = 0;

void parse_expression(const char *expression);
void evaluate_expression(void);

int main() {
    srand(time(NULL));

    printf("Welcome to the Arithmetic Labyrinth!\n");

    while (1) {
        printf("Enter an expression (e.g. 2 + 3 * 4): ");
        char expression[100];
        fgets(expression, sizeof(expression), stdin);

        parse_expression(expression);

        evaluate_expression();

        printf("You have %d operations left\n", num_operations);

        if (num_operations == 0) {
            break;
        }
    }

    return 0;
}

void parse_expression(const char *expression) {
    char *token = strtok(expression, " ");
    while (token != NULL && num_operations < MAX_OPERATIONS) {
        if (strcmp(token, "+") == 0) {
            operations[num_operations].op = '+';
        } else if (strcmp(token, "-") == 0) {
            operations[num_operations].op = '-';
        } else if (strcmp(token, "*") == 0) {
            operations[num_operations].op = '*';
        } else if (strcmp(token, "/") == 0) {
            operations[num_operations].op = '/';
        } else if (strcmp(token, "%") == 0) {
            operations[num_operations].op = '%';
        } else {
            // ignore invalid tokens
            continue;
        }

        operations[num_operations].num = atoi(token);

        num_operations++;
        token = strtok(NULL, " ");
    }
}

void evaluate_expression(void) {
    int result = 0;

    for (int i = 0; i < num_operations; i++) {
        switch (operations[i].op) {
            case '+':
                result += operations[i].num;
                break;
            case '-':
                result -= operations[i].num;
                break;
            case '*':
                result *= operations[i].num;
                break;
            case '/':
                result /= operations[i].num;
                break;
            case '%':
                result %= operations[i].num;
                break;
        }
    }

    printf("Result: %d\n", result);
}