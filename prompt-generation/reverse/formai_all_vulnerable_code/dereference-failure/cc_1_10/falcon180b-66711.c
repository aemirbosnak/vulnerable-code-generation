//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int (*func)(int, int);
} operation;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

operation operations[] = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide}
};

int main() {
    int num1, num2, result;
    char input[MAX_SIZE];
    char *token;
    operation *op;

    printf("Enter an expression in infix notation (e.g. 2 + 3 * 4): ");
    fgets(input, MAX_SIZE, stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        op = NULL;
        for (int i = 0; i < sizeof(operations) / sizeof(operation); i++) {
            if (strcmp(token, operations[i].name) == 0) {
                op = &operations[i];
                break;
            }
        }

        if (op == NULL) {
            printf("Invalid operator: %s\n", token);
            exit(1);
        }

        num1 = atoi(strtok(NULL, " "));
        num2 = atoi(strtok(NULL, " "));

        result = op->func(num1, num2);
        printf("%d %s %d = %d\n", num1, token, num2, result);
    }

    return 0;
}