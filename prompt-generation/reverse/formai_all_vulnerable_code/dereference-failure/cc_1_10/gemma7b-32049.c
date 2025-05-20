//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    char buffer[MAX_BUFFER_SIZE];
    int pos;
    int history[10];
    int hist_pos;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->pos = 0;
    calc->hist_pos = 0;
    return calc;
}

void calculator_add(Calculator* calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->history[calc->hist_pos++] = num;
}

void calculator_subtract(Calculator* calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->history[calc->hist_pos++] = num;
}

void calculator_multiply(Calculator* calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->history[calc->hist_pos++] = num;
}

void calculator_divide(Calculator* calc, int num) {
    calc->buffer[calc->pos++] = num + '0';
    calc->history[calc->hist_pos++] = num;
}

void calculator_equals(Calculator* calc) {
    int result = 0;
    for (int i = 0; calc->buffer[i] != '\0'; i++) {
        result = result * 10 + calc->buffer[i] - '0';
    }
    printf("%d\n", result);
    calc->pos = 0;
    calc->hist_pos = 0;
}

int main() {
    Calculator* calc = calculator_init();
    char input[MAX_BUFFER_SIZE];

    printf("Enter an expression: ");
    scanf("%s", input);

    for (int i = 0; input[i] != '\0'; i++) {
        switch (input[i]) {
            case '+':
                calculator_add(calc, input[i + 1] - '0');
                break;
            case '-':
                calculator_subtract(calc, input[i + 1] - '0');
                break;
            case '*':
                calculator_multiply(calc, input[i + 1] - '0');
                break;
            case '/':
                calculator_divide(calc, input[i + 1] - '0');
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