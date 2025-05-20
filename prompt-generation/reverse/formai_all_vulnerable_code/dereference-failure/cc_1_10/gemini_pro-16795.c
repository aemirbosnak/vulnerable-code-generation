//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double (*convert)(double);
} unit;

double convert_inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double convert_centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

unit units[] = {
    { "inches", convert_inches_to_centimeters },
    { "centimeters", convert_centimeters_to_inches },
    { "pounds", convert_pounds_to_kilograms },
    { "kilograms", convert_kilograms_to_pounds },
    { "fahrenheit", convert_fahrenheit_to_celsius },
    { "celsius", convert_celsius_to_fahrenheit },
    { NULL, NULL }
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <value> <from-unit> <to-unit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    unit *from = NULL;
    unit *to = NULL;

    for (unit *u = units; u->name != NULL; u++) {
        if (strcmp(u->name, from_unit) == 0) {
            from = u;
        }
        if (strcmp(u->name, to_unit) == 0) {
            to = u;
        }
    }

    if (from == NULL || to == NULL) {
        fprintf(stderr, "Invalid unit: %s or %s\n", from_unit, to_unit);
        return EXIT_FAILURE;
    }

    double result = from->convert(value);
    result = to->convert(result);

    printf("%f %s = %f %s\n", value, from_unit, result, to_unit);

    return EXIT_SUCCESS;
}