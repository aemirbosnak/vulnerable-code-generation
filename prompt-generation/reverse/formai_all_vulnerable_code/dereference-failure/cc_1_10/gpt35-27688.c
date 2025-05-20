//FormAI DATASET v1.0 Category: Funny ; Style: mathematical
#include <stdio.h>

// Let's create a polynomial structure
typedef struct polynomial {
    int degree;
    double *coefficients;
} Polynomial;

// Function to add two polynomials
Polynomial add(Polynomial a, Polynomial b) {
    Polynomial result;

    if (a.degree > b.degree) {
        result.degree = a.degree;
    } else {
        result.degree = b.degree;
    }

    result.coefficients = malloc(sizeof(double) * (result.degree + 1));

    for (int i = 0; i <= result.degree; i++) {
        result.coefficients[i] = 0.0;

        if (i <= a.degree) {
            result.coefficients[i] += a.coefficients[i];
        }
        if (i <= b.degree) {
            result.coefficients[i] += b.coefficients[i];
        }
    }

    return result;
}

int main() {
    int n = 5; // Degree of polynomials

    Polynomial poly1, poly2, poly3;

    // Initialize coefficients for polynomial 1
    poly1.degree = n;
    poly1.coefficients = malloc(sizeof(double) * (n + 1));

    poly1.coefficients[0] = 2.0;
    poly1.coefficients[1] = -3.0;
    poly1.coefficients[2] = 0.0;
    poly1.coefficients[3] = 1.0;
    poly1.coefficients[4] = 5.0;
    poly1.coefficients[5] = -2.0;

    // Initialize coefficients for polynomial 2
    poly2.degree = n;
    poly2.coefficients = malloc(sizeof(double) * (n + 1));

    poly2.coefficients[0] = 1.0;
    poly2.coefficients[1] = 4.0;
    poly2.coefficients[2] = 2.0;
    poly2.coefficients[3] = -5.0;
    poly2.coefficients[4] = 3.0;
    poly2.coefficients[5] = 0.0;

    // Add two polynomials together
    poly3 = add(poly1, poly2);

    // Print out the resulting polynomial
    printf("Polynomial 1: ");
    for (int i = poly1.degree; i >= 0; i--) {
        printf("%.1f*x^%d + ", poly1.coefficients[i], i);
    }
    printf("0\n");

    printf("Polynomial 2: ");
    for (int i = poly2.degree; i >= 0; i--) {
        printf("%.1f*x^%d + ", poly2.coefficients[i], i);
    }
    printf("0\n");

    printf("Polynomial 3: ");
    for (int i = poly3.degree; i >= 0; i--) {
        printf("%.1f*x^%d + ", poly3.coefficients[i], i);
    }
    printf("0\n");

    return 0;
}