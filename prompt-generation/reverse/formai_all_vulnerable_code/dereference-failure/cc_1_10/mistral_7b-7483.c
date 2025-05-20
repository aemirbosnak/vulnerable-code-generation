//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define NUM_CONVERTERS 3

typedef struct {
    char *name;
    double (*converter)(double value, void *params);
} Converter;

double inches_to_millimeters(double value, void *params) {
    return value * 25.4;
}

double pounds_to_kilograms(double value, void *params) {
    return value * 0.453592;
}

double fahrenheit_to_celsius(double value, void *params) {
    return (value - 32) * 5.0 / 9.0;
}

Converter converters[NUM_CONVERTERS] = {
    {"inch to millimeter", inches_to_millimeters},
    {"pound to kilogram", pounds_to_kilograms},
    {"Fahrenheit to Celsius", fahrenheit_to_celsius}
};

void print_usage() {
    printf("Usage: converter <unit> <value>\n");
    printf("Available units:\n");
    for (int i = 0; i < NUM_CONVERTERS; i++) {
        printf("%s\n", converters[i].name);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *unit = argv[1];
    double value = atof(argv[2]);

    for (int i = 0; i < NUM_CONVERTERS; i++) {
        if (strcmp(unit, converters[i].name) == 0) {
            double result = converters[i].converter(value, NULL);
            printf("%s: %g %s -> %g %s\n", unit, value, argv[1], result, argv[1][0] == 'F' ? "Fahrenheit" : "inches/pounds");
            return 0;
        }
    }

    print_usage();
    return 1;
}