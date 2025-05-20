//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int (*func)(int a, int b);
} Function;

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
        return -1;
    }
    return a / b;
}

Function functions[] = {
    {"+", add},
    {"-", subtract},
    {"*", multiply},
    {"/", divide}
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char *op = argv[2];

    Function *func = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(functions[i].name, op) == 0) {
            func = &functions[i];
            break;
        }
    }

    if (func == NULL) {
        printf("Invalid operator\n");
        return 1;
    }

    int result = func->func(num1, num2);
    printf("Result: %d\n", result);

    return 0;
}