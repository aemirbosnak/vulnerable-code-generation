//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HISTORY_SIZE 100

typedef struct {
    double value;
    char *expression;
} history_entry;

history_entry history[MAX_HISTORY_SIZE];
int history_index = 0;

void push_history(double value, char *expression) {
    history[history_index].value = value;
    history[history_index].expression = expression;
    history_index++;
}

double calculate(char *expression) {
    double value;
    char *ptr;

    value = strtod(expression, &ptr);
    if (*ptr != '\0') {
        switch (*ptr) {
            case '+':
                value += calculate(ptr + 1);
                break;
            case '-':
                value -= calculate(ptr + 1);
                break;
            case '*':
                value *= calculate(ptr + 1);
                break;
            case '/':
                value /= calculate(ptr + 1);
                break;
            case '^':
                value = pow(value, calculate(ptr + 1));
                break;
            default:
                fprintf(stderr, "Invalid expression: %s\n", expression);
                exit(1);
        }
    }

    return value;
}

void print_history() {
    int i;

    printf("History:\n");
    for (i = 0; i < history_index; i++) {
        printf("%s = %f\n", history[i].expression, history[i].value);
    }
}

int main(int argc, char *argv[]) {
    double value;
    char expression[1024];

    printf("Welcome to the Scientific Calculator!\n");

    while (1) {
        printf("> ");
        fgets(expression, sizeof(expression), stdin);

        if (strcmp(expression, "exit\n") == 0) {
            break;
        } else if (strcmp(expression, "history\n") == 0) {
            print_history();
        } else {
            value = calculate(expression);
            printf("%f\n", value);
            push_history(value, expression);
        }
    }

    return 0;
}