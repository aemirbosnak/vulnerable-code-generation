//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBER_OF_VARIABLES 5

typedef struct {
    int value;
    char name[20];
} variable_t;

variable_t variables[MAX_NUMBER_OF_VARIABLES];
int current_variable = 0;

void add_variable(char *name, int value) {
    variables[current_variable].value = value;
    strcpy(variables[current_variable].name, name);
    current_variable++;
}

void perform_operation(char *operation) {
    int first_variable, second_variable;
    char *temp;

    temp = strtok(operation, " ");
    first_variable = atoi(temp);

    temp = strtok(NULL, " ");
    second_variable = atoi(temp);

    switch (operation[0]) {
        case '+':
            variables[first_variable].value += second_variable;
            break;
        case '-':
            variables[first_variable].value -= second_variable;
            break;
        case '*':
            variables[first_variable].value *= second_variable;
            break;
        case '/':
            if (second_variable == 0) {
                variables[first_variable].value = 0;
            } else {
                variables[first_variable].value /= second_variable;
            }
            break;
        default:
            printf("Invalid operation\n");
            return;
    }

    printf("Result: %d\n", variables[first_variable].value);
}

int main() {
    srand(time(NULL));

    add_variable("x", rand() % 100);
    add_variable("y", rand() % 100);

    while (1) {
        char operation[50];
        printf("Enter an operation (+, -, *, /): ");
        fgets(operation, 50, stdin);

        perform_operation(operation);
    }

    return 0;
}