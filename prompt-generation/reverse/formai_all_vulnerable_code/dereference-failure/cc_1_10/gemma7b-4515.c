//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    double result;
} calculator;

calculator* calculator_init() {
    calculator* calc = malloc(sizeof(calculator));
    calc->pos = 0;
    calc->result = 0.0;
    return calc;
}

void calculator_add(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '+';
    calc->buffer[calc->pos++] = num + '0' + 0x20;
    calc->result += num;
}

void calculator_sub(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '-';
    calc->buffer[calc->pos++] = num + '0' + 0x20;
    calc->result -= num;
}

void calculator_mul(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '*';
    calc->buffer[calc->pos++] = num + '0' + 0x20;
    calc->result *= num;
}

void calculator_div(calculator* calc, double num) {
    calc->buffer[calc->pos++] = '/';
    calc->buffer[calc->pos++] = num + '0' + 0x20;
    calc->result /= num;
}

void calculator_equal(calculator* calc) {
    calc->buffer[calc->pos++] = '=';
    calc->buffer[calc->pos] = '\0';
    printf("%s = %f\n", calc->buffer, calc->result);
}

int main() {
    calculator* calc = calculator_init();
    char cmd;
    double num;

    printf("Welcome to the Retro Calculator!\n");
    printf("Enter a command (add, sub, mul, div, equal): ");

    scanf(" %c", &cmd);

    switch (cmd) {
        case 'a':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_add(calc, num);
            break;
        case 's':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_sub(calc, num);
            break;
        case 'm':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_mul(calc, num);
            break;
        case 'd':
            printf("Enter a number: ");
            scanf(" %lf", &num);
            calculator_div(calc, num);
            break;
        case '=':
            calculator_equal(calc);
            break;
        default:
            printf("Invalid command.\n");
    }

    free(calc);

    return 0;
}