//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100
#define MAX_INPUT_SIZE 100

typedef struct {
    double value;
    char *string;
} stack_item;

typedef struct {
    stack_item *items;
    int top;
} stack;

stack *stack_init() {
    stack *s = malloc(sizeof(stack));
    s->items = malloc(MAX_STACK_SIZE * sizeof(stack_item));
    s->top = -1;
    return s;
}

void stack_push(stack *s, double value, char *string) {
    if (s->top == MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Error: stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top].value = value;
    s->items[s->top].string = strdup(string);
}

double stack_pop(stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--].value;
}

double stack_peek(stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top].value;
}

char *stack_peek_string(stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top].string;
}

void stack_free(stack *s) {
    int i;
    for (i = 0; i <= s->top; i++) {
        free(s->items[i].string);
    }
    free(s->items);
    free(s);
}

int is_operator(char *s) {
    return strlen(s) == 1 && strchr("+-*/^", s[0]);
}

int is_function(char *s) {
    return strlen(s) > 1 && strchr("sincosinhtancotlog", s[0]);
}

int main() {
    stack *s = stack_init();
    char input[MAX_INPUT_SIZE];
    double value;
    char *string;
    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        if (strlen(input) == 1 && input[0] == '\n') {
            break;
        }
        if (is_operator(input)) {
            double b = stack_pop(s);
            double a = stack_pop(s);
            switch (input[0]) {
                case '+':
                    value = a + b;
                    break;
                case '-':
                    value = a - b;
                    break;
                case '*':
                    value = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        fprintf(stderr, "Error: division by zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    value = a / b;
                    break;
                case '^':
                    value = pow(a, b);
                    break;
            }
            string = malloc(20);
            sprintf(string, "%.15g", value);
            stack_push(s, value, string);
        } else if (is_function(input)) {
            value = stack_pop(s);
            switch (input[0]) {
                case 's':
                    if (strchr("in", input[1])) {
                        value = sin(value);
                    } else if (strchr("in", input[2])) {
                        value = sinh(value);
                    } else {
                        value = sqrt(value);
                    }
                    break;
                case 'c':
                    if (strchr("in", input[1])) {
                        value = cos(value);
                    } else {
                        value = ceil(value);
                    }
                    break;
                case 't':
                    value = tan(value);
                    break;
                case 'a':
                    value = acos(value);
                    break;
                case 'l':
                    value = log(value);
                    break;
            }
            string = malloc(20);
            sprintf(string, "%.15g", value);
            stack_push(s, value, string);
        } else {
            value = atof(input);
            string = malloc(20);
            sprintf(string, "%.15g", value);
            stack_push(s, value, string);
        }
        printf("%s\n", stack_peek_string(s));
    }
    stack_free(s);
    return 0;
}