//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

double pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

Unit units[] = {
    {"in", inches_to_centimeters},
    {"cm", centimeters_to_inches},
    {"lb", pounds_to_kilograms},
    {"kg", kilograms_to_pounds},
    {"°F", fahrenheit_to_celsius},
    {"°C", celsius_to_fahrenheit}
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double value = atof(argv[1]);
    char *from = argv[2];
    char *to = argv[3];

    Unit *unit_from = NULL;
    Unit *unit_to = NULL;

    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, from) == 0) {
            unit_from = &units[i];
        } else if (strcmp(units[i].name, to) == 0) {
            unit_to = &units[i];
        }
    }

    if (unit_from == NULL || unit_to == NULL) {
        fprintf(stderr, "Invalid unit(s) specified\n");
        return EXIT_FAILURE;
    }

    double result = unit_to->convert(unit_from->convert(value));

    printf("%f %s is equal to %f %s\n", 
        value, unit_from->name, result, unit_to->name);

    return EXIT_SUCCESS;
}