//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef enum { C, F, K } temp_scale;

struct temp {
    double value;
    temp_scale scale;
};

struct temp *new_temp(double value, temp_scale scale) {
    struct temp *t = malloc(sizeof(struct temp));
    t->value = value;
    t->scale = scale;
    return t;
}

void print_temp(struct temp *t) {
    if (t->scale == C) {
        printf("%.2f degrees Celsius\n", t->value);
    } else if (t->scale == F) {
        printf("%.2f degrees Fahrenheit\n", t->value);
    } else if (t->scale == K) {
        printf("%.2f degrees Kelvin\n", t->value);
    } else {
        printf("Invalid temperature scale\n");
    }
}

struct temp *c_to_f(struct temp *t) {
    if (t->scale != C) {
        fprintf(stderr, "Error: Cannot convert from %s to Fahrenheit\n", t->scale == F ? "Fahrenheit" : "Kelvin");
        return NULL;
    }
    return new_temp(t->value * 9 / 5 + 32, F);
}

struct temp *f_to_c(struct temp *t) {
    if (t->scale != F) {
        fprintf(stderr, "Error: Cannot convert from %s to Celsius\n", t->scale == C ? "Celsius" : "Kelvin");
        return NULL;
    }
    return new_temp((t->value - 32) * 5 / 9, C);
}

struct temp *k_to_c(struct temp *t) {
    if (t->scale != K) {
        fprintf(stderr, "Error: Cannot convert from %s to Celsius\n", t->scale == C ? "Celsius" : "Fahrenheit");
        return NULL;
    }
    return new_temp(t->value - 273.15, C);
}

struct temp *c_to_k(struct temp *t) {
    if (t->scale != C) {
        fprintf(stderr, "Error: Cannot convert from %s to Kelvin\n", t->scale == F ? "Fahrenheit" : "Celsius");
        return NULL;
    }
    return new_temp(t->value + 273.15, K);
}

int main() {
    struct temp *t1 = new_temp(20.0, C);
    print_temp(t1); // 20.00 degrees Celsius

    struct temp *t2 = c_to_f(t1);
    print_temp(t2); // 68.00 degrees Fahrenheit

    struct temp *t3 = f_to_c(t2);
    print_temp(t3); // 20.00 degrees Celsius

    struct temp *t4 = new_temp(100.0, F);
    print_temp(t4); // 100.00 degrees Fahrenheit

    struct temp *t5 = f_to_c(t4);
    print_temp(t5); // 37.78 degrees Celsius

    struct temp *t6 = new_temp(273.15, K);
    print_temp(t6); // 273.15 degrees Kelvin

    struct temp *t7 = k_to_c(t6);
    print_temp(t7); // 0.00 degrees Celsius

    return 0;
}