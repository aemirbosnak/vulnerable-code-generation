//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_RESULT_SIZE 100
#define MAX_OPERATORS 100

typedef struct {
    char input[MAX_INPUT_SIZE];
    char result[MAX_RESULT_SIZE];
    int operator_count;
    char operators[MAX_OPERATORS][10];
} Calculator;

void init_calculator(Calculator *calc) {
    calc->input[0] = '\0';
    calc->result[0] = '\0';
    calc->operator_count = 0;
}

void clear_calculator(Calculator *calc) {
    init_calculator(calc);
}

void add_operator(Calculator *calc, char op) {
    if (calc->operator_count >= MAX_OPERATORS) {
        printf("Error: Too many operators.\n");
        return;
    }
    strcpy(calc->operators[calc->operator_count], op);
    calc->operator_count++;
}

int evaluate_expression(Calculator *calc) {
    char *endptr;
    double num1, num2, result = 0;
    int i;

    if (calc->input[0] == '\0') {
        printf("Error: Empty expression.\n");
        return 0;
    }

    for (i = 0; i < calc->operator_count; i++) {
        strcat(calc->input, calc->operators[i]);
        strcat(calc->input, " ");
    }

    if (sscanf(calc->input, "%lf %lf %*c", &num1, &num2)!= 2) {
        printf("Error: Invalid expression.\n");
        return 0;
    }

    result = num1 + num2;
    sprintf(calc->result, "%.2lf", result);

    return 1;
}

int main() {
    Calculator calc;
    char input[MAX_INPUT_SIZE];
    int choice;

    init_calculator(&calc);

    while (1) {
        printf("Enter an expression or choose an option:\n");
        printf("1. Add operator\n");
        printf("2. Clear calculator\n");
        printf("3. Evaluate expression\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter operator: ");
            scanf(" %s", input);
            add_operator(&calc, input[0]);
            break;
        case 2:
            clear_calculator(&calc);
            break;
        case 3:
            if (evaluate_expression(&calc)) {
                printf("Result: %s\n", calc.result);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}