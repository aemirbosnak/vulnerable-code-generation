//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    double (*convert)(double);
} Conversion;

double celsius_to_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5.0 / 9.0;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

Conversion *get_conversion(char *name) {
    static Conversion conversions[] = {
        {"Celsius", celsius_to_fahrenheit},
        {"Celsius", celsius_to_kelvin},
        {"Fahrenheit", fahrenheit_to_celsius},
        {"Fahrenheit", fahrenheit_to_kelvin},
        {"Kelvin", kelvin_to_celsius},
        {"Kelvin", kelvin_to_fahrenheit},
        {NULL, NULL}
    };

    for (Conversion *conv = conversions; conv->name!= NULL; conv++) {
        if (strcmp(conv->name, name) == 0) {
            return conv;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s temperature_value unit\n", argv[0]);
        return 1;
    }

    char *unit = argv[2];
    double value = strtod(argv[1], NULL);

    Conversion *conv = get_conversion(unit);
    if (conv == NULL) {
        printf("Invalid unit: %s\n", unit);
        return 1;
    }

    double result = conv->convert(value);
    printf("%.2f %s = %.2f %s\n", value, unit, result, conv->name);

    return 0;
}