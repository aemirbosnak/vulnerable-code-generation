//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure to represent a fraction
typedef struct {
    int numerator;
    int denominator;
} Fraction;

// A function to create a new fraction
Fraction* create_fraction(int numerator, int denominator) {
    Fraction* fraction = malloc(sizeof(Fraction));
    fraction->numerator = numerator;
    fraction->denominator = denominator;
    return fraction;
}

// A function to print a fraction
void print_fraction(Fraction* fraction) {
    printf("%d/%d", fraction->numerator, fraction->denominator);
}

// A function to add two fractions
Fraction* add_fractions(Fraction* fraction1, Fraction* fraction2) {
    int new_numerator = fraction1->numerator * fraction2->denominator + fraction2->numerator * fraction1->denominator;
    int new_denominator = fraction1->denominator * fraction2->denominator;
    return create_fraction(new_numerator, new_denominator);
}

// A function to subtract two fractions
Fraction* subtract_fractions(Fraction* fraction1, Fraction* fraction2) {
    int new_numerator = fraction1->numerator * fraction2->denominator - fraction2->numerator * fraction1->denominator;
    int new_denominator = fraction1->denominator * fraction2->denominator;
    return create_fraction(new_numerator, new_denominator);
}

// A function to multiply two fractions
Fraction* multiply_fractions(Fraction* fraction1, Fraction* fraction2) {
    int new_numerator = fraction1->numerator * fraction2->numerator;
    int new_denominator = fraction1->denominator * fraction2->denominator;
    return create_fraction(new_numerator, new_denominator);
}

// A function to divide two fractions
Fraction* divide_fractions(Fraction* fraction1, Fraction* fraction2) {
    int new_numerator = fraction1->numerator * fraction2->denominator;
    int new_denominator = fraction1->denominator * fraction2->numerator;
    return create_fraction(new_numerator, new_denominator);
}

// A function to simplify a fraction
Fraction* simplify_fraction(Fraction* fraction) {
    int gcd = 1;
    for (int i = 1; i <= fraction->numerator && i <= fraction->denominator; i++) {
        if (fraction->numerator % i == 0 && fraction->denominator % i == 0) {
            gcd = i;
        }
    }
    return create_fraction(fraction->numerator / gcd, fraction->denominator / gcd);
}

// A function to generate a random fraction
Fraction* generate_random_fraction() {
    int numerator = rand() % 100;
    int denominator = rand() % 100 + 1;
    return create_fraction(numerator, denominator);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create two random fractions
    Fraction* fraction1 = generate_random_fraction();
    Fraction* fraction2 = generate_random_fraction();

    // Print the original fractions
    printf("Fraction 1: ");
    print_fraction(fraction1);
    printf("\n");
    printf("Fraction 2: ");
    print_fraction(fraction2);
    printf("\n");

    // Add the fractions
    Fraction* sum = add_fractions(fraction1, fraction2);
    printf("Sum: ");
    print_fraction(sum);
    printf("\n");

    // Subtract the fractions
    Fraction* difference = subtract_fractions(fraction1, fraction2);
    printf("Difference: ");
    print_fraction(difference);
    printf("\n");

    // Multiply the fractions
    Fraction* product = multiply_fractions(fraction1, fraction2);
    printf("Product: ");
    print_fraction(product);
    printf("\n");

    // Divide the fractions
    Fraction* quotient = divide_fractions(fraction1, fraction2);
    printf("Quotient: ");
    print_fraction(quotient);
    printf("\n");

    // Simplify the fractions
    Fraction* simplified_fraction1 = simplify_fraction(fraction1);
    Fraction* simplified_fraction2 = simplify_fraction(fraction2);
    printf("Simplified Fraction 1: ");
    print_fraction(simplified_fraction1);
    printf("\n");
    printf("Simplified Fraction 2: ");
    print_fraction(simplified_fraction2);
    printf("\n");

    // Free the allocated memory
    free(fraction1);
    free(fraction2);
    free(sum);
    free(difference);
    free(product);
    free(quotient);
    free(simplified_fraction1);
    free(simplified_fraction2);

    return 0;
}