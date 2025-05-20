//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int history_pos;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->history_pos = 0;
    return calc;
}

void calculator_add(Calculator* calc, char number) {
    calc->buffer[calc->pos++] = number;
}

void calculator_clear(Calculator* calc) {
    calc->pos = 0;
}

void calculator_backspace(Calculator* calc) {
    if (calc->pos > 0) {
        calc->pos--;
    }
}

void calculator_equals(Calculator* calc) {
    int result = 0;
    char* expression = calc->buffer;
    for (int i = 0; expression[i] != '\0'; i++) {
        result *= 10;
        result += expression[i] - '0';
    }
    calc->history[calc->history_pos++] = result;
    printf("%d\n", result);
    calculator_clear(calc);
}

int main() {
    Calculator* calc = calculator_init();
    char input;

    printf("Enter an expression: ");

    while ((input = getchar()) != '\n') {
        switch (input) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                calculator_add(calc, input);
                break;
            case 'C':
                calculator_clear(calc);
                break;
            case '<':
                calculator_backspace(calc);
                break;
            case '=':
                calculator_equals(calc);
                break;
            default:
                break;
        }
    }

    return 0;
}