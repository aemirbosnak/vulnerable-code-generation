//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double to_base;
    double from_base;
} unit;

unit units[] = {
    {"meter", 1.0, 100.0},
    {"centimeter", 0.01, 100.0},
    {"millimeter", 0.001, 1000.0},
    {"kilometer", 1000.0, 1.0},
    {"inch", 0.0254, 39.3701},
    {"foot", 0.3048, 3.28084},
    {"yard", 0.9144, 1.09361},
    {"mile", 1609.34, 0.000621371},
    {"pound", 0.453592, 2.20462},
    {"ounce", 0.0283495, 35.274},
    {"gram", 0.001, 1000.0},
    {"kilogram", 1.0, 1.0},
    {"Celsius", 1.0, 1.8},
    {"Fahrenheit", 1.8, 1.0},
    {"Kelvin", 1.0, 1.0},
    {NULL, 0.0, 0.0}
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
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

    double converted_value = value * from->to_base / to->from_base;

    printf("%f %s = %f %s\n", value, from_unit, converted_value, to_unit);

    return EXIT_SUCCESS;
}