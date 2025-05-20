//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a complex number.
typedef struct {
    double real;
    double imaginary;
} complex;

// Define a function to add two complex numbers.
complex add_complex(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

// Define a function to subtract two complex numbers.
complex subtract_complex(complex a, complex b) {
    complex result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

// Define a function to multiply two complex numbers.
complex multiply_complex(complex a, complex b) {
    complex result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

// Define a function to divide two complex numbers.
complex divide_complex(complex a, complex b) {
    complex result;
    double denominator = b.real * b.real + b.imaginary * b.imaginary;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    result.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return result;
}

// Define a function to convert a string to a complex number.
complex string_to_complex(char *s) {
    complex result;
    char *p = s;
    int sign = 1;
    if (*p == '-') {
        sign = -1;
        p++;
    }
    result.real = strtod(p, &p);
    if (*p == '+') {
        p++;
    } else if (*p == '-') {
        sign = -1;
        p++;
    }
    result.imaginary = sign * strtod(p, &p);
    return result;
}

// Define a function to convert a complex number to a string.
char *complex_to_string(complex a) {
    char *result = malloc(32);
    sprintf(result, "%f+%fi", a.real, a.imaginary);
    return result;
}

// Define a function to test the complex number operations.
void test_complex() {
    complex a = {1.0, 2.0};
    complex b = {3.0, 4.0};
    complex c;
    c = add_complex(a, b);
    printf("a + b = %s\n", complex_to_string(c));
    c = subtract_complex(a, b);
    printf("a - b = %s\n", complex_to_string(c));
    c = multiply_complex(a, b);
    printf("a * b = %s\n", complex_to_string(c));
    c = divide_complex(a, b);
    printf("a / b = %s\n", complex_to_string(c));
}

// Define a function to test the string conversion functions.
void test_string() {
    char *s = "1.0+2.0i";
    complex a = string_to_complex(s);
    printf("String to complex: %s -> %s\n", s, complex_to_string(a));
    s = complex_to_string(a);
    printf("Complex to string: %s -> %s\n", complex_to_string(a), s);
}

// Define a function to test the complex number operations using strings.
void test_string_complex() {
    char *s1 = "1.0+2.0i";
    char *s2 = "3.0+4.0i";
    complex a = string_to_complex(s1);
    complex b = string_to_complex(s2);
    complex c;
    c = add_complex(a, b);
    printf("a + b = %s\n", complex_to_string(c));
    c = subtract_complex(a, b);
    printf("a - b = %s\n", complex_to_string(c));
    c = multiply_complex(a, b);
    printf("a * b = %s\n", complex_to_string(c));
    c = divide_complex(a, b);
    printf("a / b = %s\n", complex_to_string(c));
}

int main() {
    test_complex();
    test_string();
    test_string_complex();
    return 0;
}