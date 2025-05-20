//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A plugin that calculates the derivative of a polynomial.

typedef struct {
    int degree;
    double *coefficients;
} polynomial;

polynomial *polynomial_create(int degree) {
    polynomial *p = malloc(sizeof(polynomial));
    p->degree = degree;
    p->coefficients = malloc(sizeof(double) * (degree + 1));
    return p;
}

void polynomial_destroy(polynomial *p) {
    free(p->coefficients);
    free(p);
}

void polynomial_set_coefficient(polynomial *p, int index, double value) {
    p->coefficients[index] = value;
}

double polynomial_evaluate(polynomial *p, double x) {
    double result = 0;
    for (int i = 0; i <= p->degree; i++) {
        result += p->coefficients[i] * pow(x, i);
    }
    return result;
}

polynomial *polynomial_derivative(polynomial *p) {
    polynomial *dp = malloc(sizeof(polynomial));
    dp->degree = p->degree - 1;
    dp->coefficients = malloc(sizeof(double) * (dp->degree + 1));
    for (int i = 0; i <= dp->degree; i++) {
        dp->coefficients[i] = p->coefficients[i] * (p->degree - i);
    }
    return dp;
}

void polynomial_print(polynomial *p) {
    printf("f(x) = ");
    for (int i = p->degree; i >= 0; i--) {
        if (i != p->degree) {
            printf(" + ");
        }
        printf("%fx^%d", p->coefficients[i], i);
    }
    printf("\n");
}

int main() {
    // Create a polynomial.
    polynomial *p = polynomial_create(3);
    polynomial_set_coefficient(p, 0, 1);
    polynomial_set_coefficient(p, 1, 2);
    polynomial_set_coefficient(p, 2, 3);
    polynomial_set_coefficient(p, 3, 4);

    // Print the polynomial.
    polynomial_print(p);

    // Calculate the derivative of the polynomial.
    polynomial *dp = polynomial_derivative(p);

    // Print the derivative of the polynomial.
    polynomial_print(dp);

    // Destroy the polynomials.
    polynomial_destroy(p);
    polynomial_destroy(dp);

    return 0;
}