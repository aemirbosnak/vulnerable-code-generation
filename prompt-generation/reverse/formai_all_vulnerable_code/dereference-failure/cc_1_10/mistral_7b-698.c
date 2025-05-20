//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int num1;
    int num2;
    char operator;
} Calculation;

bool is_valid_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

Calculation parse_calculation(char* expression, int* index) {
    Calculation calc;
    int i;

    // Skip whitespaces
    while (isspace(*expression++)) {}

    // Read number 1
    calc.num1 = 0;
    for (i = 0; isdigit(*expression); i++) {
        calc.num1 = calc.num1 * 10 + (*expression++ - '0');
    }

    calc.operator = *expression++;

    if (!is_valid_operator(calc.operator)) {
        printf("Error: Invalid operator %c\n", calc.operator);
        exit(EXIT_FAILURE);
    }

    // Read number 2
    calc.num2 = 0;
    for (i = 0; isdigit(*expression); i++) {
        calc.num2 = calc.num2 * 10 + (*expression++ - '0');
    }

    // Skip whitespaces and operator
    while (isspace(*expression) || is_valid_operator(*expression)) {}

    *index += strlen(expression);

    return calc;
}

int calculate(Calculation calc) {
    switch (calc.operator) {
        case '+':
            return calc.num1 + calc.num2;
        case '-':
            return calc.num1 - calc.num2;
        case '*':
            return calc.num1 * calc.num2;
        case '/':
            return calc.num1 / calc.num2;
        default:
            break;
    }

    printf("Error: Unreachable code\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    char expression[100];
    int index = 0;
    int result;
    Calculation calc;

    if (argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(expression, argv[1]);

    while (!feof(stdin) && index < strlen(expression)) {
        calc = parse_calculation(expression, &index);
        result = calculate(calc);
        printf("%d\n", result);
    }

    return EXIT_SUCCESS;
}