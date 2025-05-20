//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1000

struct Complex {
    int real;
    int imag;
};

void add(struct Complex a, struct Complex b, struct Complex res) {
    res.real = a.real + b.real;
    res.imag = a.imag + b.imag;
}

void subtract(struct Complex a, struct Complex b, struct Complex res) {
    res.real = a.real - b.real;
    res.imag = a.imag - b.imag;
}

void multiply(struct Complex a, struct Complex b, struct Complex res) {
    int real = a.real * b.real - a.imag * b.imag;
    int imag = 2 * a.real * b.imag + a.imag * b.real;
    res.real = real;
    res.imag = imag;
}

void divide(struct Complex a, struct Complex b, struct Complex res) {
    int real = a.real * b.real + a.imag * b.imag;
    int imag = 2 * a.real * b.imag - a.imag * b.real;
    res.real = real / b.real;
    res.imag = imag / b.imag;
}

int main() {
    struct Complex a, b, c, d;

    // Initialize a and b with random values
    a.real = rand() % 100;
    a.imag = rand() % 100;
    b.real = rand() % 100;
    b.imag = rand() % 100;

    // Perform operations
    add(a, b, c);
    subtract(a, b, d);
    multiply(a, b, c);
    divide(a, b, d);

    // Print results
    printf("a + b = %d + %di\n", c.real, c.imag);
    printf("a - b = %d + %d i\n", d.real, d.imag);
    printf("a * b = %d + %d i\n", c.real, c.imag);
    printf("a / b = %d + %d i\n", d.real, d.imag);

    return 0;
}