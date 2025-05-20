//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

typedef struct {
    char *name;
    int (*func)(int, int);
} operation;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int power(int a, int b);
int square_root(int a);
int factorial(int a);

operation operations[] = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide},
    {"^", power},
    {"sqrt", square_root},
    {"!", factorial}
};

int main() {
    int num1, num2, result, choice;
    char operation_symbol;
    char input[MAX_SIZE];

    printf("Enter two numbers separated by an operator:\n");
    scanf("%s", input);

    num1 = atoi(strtok(input, " "));
    operation_symbol = strtok(NULL, " ");
    num2 = atoi(strtok(NULL, " "));

    printf("Enter the operation number:\n");
    for (int i = 0; i < sizeof(operations)/sizeof(operation); i++) {
        printf("%d. %s\n", i+1, operations[i].name);
    }

    scanf("%d", &choice);

    result = operations[choice-1].func(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}

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
        return 0;
    }
    return a / b;
}

int power(int a, int b) {
    return pow(a, b);
}

int square_root(int a) {
    return sqrt(a);
}

int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    return result;
}