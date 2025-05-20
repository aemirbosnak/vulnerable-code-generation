//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct fraction {
    int numerator;
    int denominator;
};

struct fraction *fraction_new(int numerator, int denominator) {
    struct fraction *f = malloc(sizeof(struct fraction));
    f->numerator = numerator;
    f->denominator = denominator;
    return f;
}

void fraction_free(struct fraction *f) {
    free(f);
}

struct fraction *fraction_add(struct fraction *a, struct fraction *b) {
    int new_numerator = a->numerator * b->denominator + a->denominator * b->numerator;
    int new_denominator = a->denominator * b->denominator;
    return fraction_new(new_numerator, new_denominator);
}

struct fraction *fraction_multiply(struct fraction *a, struct fraction *b) {
    int new_numerator = a->numerator * b->numerator;
    int new_denominator = a->denominator * b->denominator;
    return fraction_new(new_numerator, new_denominator);
}

void fraction_print(struct fraction *f) {
    printf("%d/%d\n", f->numerator, f->denominator);
}

int main() {
    struct fraction *a = fraction_new(1, 2);
    struct fraction *b = fraction_new(3, 4);
    struct fraction *c = fraction_add(a, b);
    struct fraction *d = fraction_multiply(a, b);
    fraction_print(c);
    fraction_print(d);
    fraction_free(a);
    fraction_free(b);
    fraction_free(c);
    fraction_free(d);
    return 0;
}