//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100
#define MAX_COEFFS 1000
#define MAX_CONST 100

typedef struct {
    int num_vars;
    int num_coeffs;
    int *vars;
    int *coeffs;
    int constant;
} Equation;

int compare_equations(const void *a, const void *b) {
    Equation *eq1 = (Equation *)a;
    Equation *eq2 = (Equation *)b;

    if (eq1->constant < eq2->constant) {
        return -1;
    } else if (eq1->constant > eq2->constant) {
        return 1;
    } else {
        return 0;
    }
}

void print_equation(Equation *eq) {
    printf("y = ");
    for (int i = 0; i < eq->num_vars; i++) {
        printf("%d ", eq->vars[i]);
    }
    printf(" + %d\n", eq->constant);
}

void generate_random_equation(Equation *eq) {
    eq->num_vars = rand() % MAX_VARS + 1;
    eq->num_coeffs = rand() % MAX_COEFFS + 1;
    eq->vars = malloc(eq->num_vars * sizeof(int));
    eq->coeffs = malloc(eq->num_coeffs * sizeof(int));
    for (int i = 0; i < eq->num_vars; i++) {
        eq->vars[i] = rand() % MAX_CONST;
    }
    for (int i = 0; i < eq->num_coeffs; i++) {
        eq->coeffs[i] = rand() % MAX_CONST;
    }
    eq->constant = rand() % MAX_CONST;
}

int main() {
    int num_equations;
    printf("Enter the number of equations: ");
    scanf("%d", &num_equations);

    Equation *equations = malloc(num_equations * sizeof(Equation));

    for (int i = 0; i < num_equations; i++) {
        generate_random_equation(&equations[i]);
    }

    qsort(equations, num_equations, sizeof(Equation), compare_equations);

    for (int i = 0; i < num_equations; i++) {
        print_equation(&equations[i]);
    }

    return 0;
}