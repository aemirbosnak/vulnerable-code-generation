//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int historyPos;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->historyPos = 0;
    return calc;
}

void calculator_add(Calculator* calc, char num) {
    calc->buffer[calc->pos++] = num;
}

void calculator_clear(Calculator* calc) {
    calc->pos = 0;
}

void calculator_backspace(Calculator* calc) {
    if (calc->pos > 0) {
        calc->pos--;
    }
}

void calculator_enter(Calculator* calc) {
    calc->history[calc->historyPos++] = calculator_evaluate(calc->buffer);
    calculator_clear(calc);
}

int calculator_evaluate(char* buffer) {
    int i = 0;
    int result = 0;
    char operator = '\0';

    for (i = 0; buffer[i] != '\0'; i++) {
        if (isdigit(buffer[i])) {
            int num = buffer[i] - '0';
            switch (operator) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    result /= num;
                    break;
                default:
                    result = num;
                    break;
            }
        } else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/') {
            operator = buffer[i];
        }
    }

    return result;
}

int main() {
    Calculator* calc = calculator_init();

    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
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
                calculator_add(calc, input[i]);
                break;
            case ' ':
                calculator_enter(calc);
                break;
            case '\b':
                calculator_backspace(calc);
                break;
            default:
                break;
        }
    }

    printf("History:\n");
    for (int i = 0; i < calc->historyPos; i++) {
        printf("%d ", calc->history[i]);
    }

    return 0;
}