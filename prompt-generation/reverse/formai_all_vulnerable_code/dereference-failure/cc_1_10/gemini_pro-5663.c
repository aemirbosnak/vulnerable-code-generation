//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char *expr;
    int len;
} expression;

expression *new_expression(char *expr) {
    expression *e = malloc(sizeof(expression));
    e->expr = strdup(expr);
    e->len = strlen(expr);
    return e;
}

void free_expression(expression *e) {
    free(e->expr);
    free(e);
}

int eval_expression(expression *e) {
    int result = 0;
    char *p = e->expr;

    while (*p != '\0') {
        if (*p == '+') {
            result += atoi(p + 1);
            p += strlen(p + 1) + 1;
        } else if (*p == '-') {
            result -= atoi(p + 1);
            p += strlen(p + 1) + 1;
        } else if (*p == '*') {
            result *= atoi(p + 1);
            p += strlen(p + 1) + 1;
        } else if (*p == '/') {
            result /= atoi(p + 1);
            p += strlen(p + 1) + 1;
        } else {
            result = atoi(p);
            p += strlen(p) + 1;
        }
    }

    return result;
}

int main() {
    expression *e = new_expression("1 + 2 * 3 - 4 / 5");
    int result = eval_expression(e);
    printf("The result is: %d\n", result);
    free_expression(e);
    return 0;
}