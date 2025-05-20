//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_OPERATORS 100
#define MAX_VARIABLES 100

typedef struct {
    char *name;
    double value;
} Variable;

typedef struct {
    char *name;
    int (*func)(double, double);
} Function;

typedef struct {
    char *expr;
    int precedence;
    int (*func)(double, double);
} Operator;

Variable *createVariable(char *name, double value) {
    Variable *var = malloc(sizeof(Variable));
    var->name = strdup(name);
    var->value = value;
    return var;
}

Function *createFunction(char *name, int (*func)(double, double)) {
    Function *fun = malloc(sizeof(Function));
    fun->name = strdup(name);
    fun->func = func;
    return fun;
}

Operator *createOperator(char *expr, int precedence, int (*func)(double, double)) {
    Operator *op = malloc(sizeof(Operator));
    op->expr = strdup(expr);
    op->precedence = precedence;
    op->func = func;
    return op;
}

double applyOperator(Operator *op, double a, double b) {
    return op->func(a, b);
}

double applyFunction(Function *fun, double a, double b) {
    return fun->func(a, b);
}

int main() {
    Variable *var1 = createVariable("x", 2.0);
    Variable *var2 = createVariable("y", 3.0);
    Function *fun1 = createFunction("+", &applyFunction);
    Function *fun2 = createFunction("*", &applyFunction);
    Operator *op1 = createOperator("+", 1, &applyOperator);
    Operator *op2 = createOperator("*", 2, &applyOperator);

    double result = applyOperator(op1, applyFunction(fun1, var1->value, var2->value), 5.0);
    printf("Result: %f\n", result);

    return 0;
}