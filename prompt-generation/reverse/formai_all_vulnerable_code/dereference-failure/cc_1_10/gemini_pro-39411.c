//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUF 1024
#define MAX_DEPTH 100

typedef struct {
    double val;
    char *str;
} token_t;

typedef struct {
    int top;
    token_t stack[MAX_DEPTH];
} stack_t;

void push(stack_t *s, double val, char *str) {
    s->stack[++s->top] = (token_t){val, str};
}

token_t pop(stack_t *s) {
    return s->stack[s->top--];
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double evaluate(stack_t *s, char *op) {
    token_t op1 = pop(s);
    token_t op2 = pop(s);
    double res;
    switch (*op) {
        case '+': res = op2.val + op1.val; break;
        case '-': res = op2.val - op1.val; break;
        case '*': res = op2.val * op1.val; break;
        case '/': res = op2.val / op1.val; break;
        case '^': res = pow(op2.val, op1.val); break;
    }
    push(s, res, op);
    return res;
}

int main() {
    char buf[MAX_BUF];
    stack_t s = {0};
    while (fgets(buf, sizeof buf, stdin)) {
        char *p = buf;
        while (*p) {
            if (isspace(*p)) {
                p++;
            } else if (isdigit(*p) || *p == '.') {
                double val = strtod(p, &p);
                push(&s, val, "num");
            } else if (is_operator(*p)) {
                evaluate(&s, p++);
            } else {
                fprintf(stderr, "invalid character: %c\n", *p);
                return 1;
            }
        }
        if (s.top != 0) {
            printf("%f\n", s.stack[s.top].val);
            s.top = 0;
        }
    }
    return 0;
}