//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    float result;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->result = 0.0f;
    return calc;
}

void calculator_add(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result += num;
}

void calculator_sub(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result -= num;
}

void calculator_mul(Calculator* calc, float num) {
    calc->buffer[calc->pos++] = num;
    calc->result *= num;
}

void calculator_div(Calculator* calc, float num) {
    if (num == 0.0f) {
        printf("Error: division by zero is not allowed.\n");
        return;
    }
    calc->buffer[calc->pos++] = num;
    calc->result /= num;
}

void calculator_equals(Calculator* calc) {
    calc->buffer[calc->pos] = '\0';
    printf("Result: %.2f\n", calc->result);
}

int main() {
    Calculator* calc = calculator_init();
    char cmd;
    float num;

    printf("Enter command (add/sub/mul/div/equals): ");
    scanf(" %c", &cmd);

    switch (cmd) {
        case 'a':
            printf("Enter number: ");
            scanf(" %f", &num);
            calculator_add(calc, num);
            break;
        case 's':
            printf("Enter number: ");
            scanf(" %f", &num);
            calculator_sub(calc, num);
            break;
        case 'm':
            printf("Enter number: ");
            scanf(" %f", &num);
            calculator_mul(calc, num);
            break;
        case 'd':
            printf("Enter number: ");
            scanf(" %f", &num);
            calculator_div(calc, num);
            break;
        case 'e':
            calculator_equals(calc);
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    return 0;
}