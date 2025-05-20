//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Calculator {
    int buffer[MAX_BUFFER_SIZE];
    int head;
    int tail;
} Calculator;

Calculator* calculator_init() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->head = 0;
    calc->tail = -1;
    return calc;
}

void calculator_push(Calculator* calc, int num) {
    if (calc->tail - calc->head + 1 >= MAX_BUFFER_SIZE) {
        printf("Error: Calculator overflow!\n");
        return;
    }

    calc->buffer[++calc->tail] = num;
}

int calculator_pop(Calculator* calc) {
    if (calc->head == calc->tail) {
        printf("Error: Calculator underflow!\n");
        return -1;
    }

    return calc->buffer[calc->head++];
}

int main() {
    Calculator* calc = calculator_init();

    // Push numbers onto the calculator
    calculator_push(calc, 5);
    calculator_push(calc, 10);
    calculator_push(calc, 15);

    // Pop numbers from the calculator
    int popped_num = calculator_pop(calc);
    printf("Popped number: %d\n", popped_num);

    popped_num = calculator_pop(calc);
    printf("Popped number: %d\n", popped_num);

    popped_num = calculator_pop(calc);
    printf("Popped number: %d\n", popped_num);

    // Check if the calculator is empty
    if (calculator_pop(calc) == -1) {
        printf("Calculator is empty!\n");
    }

    // Free the calculator
    free(calc);

    return 0;
}