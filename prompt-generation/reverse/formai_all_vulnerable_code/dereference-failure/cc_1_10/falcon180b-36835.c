//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 10

struct unit_conversion {
    char *from_unit;
    char *to_unit;
    double conversion_factor;
};

struct unit_conversion conversions[MAX_CONVERSIONS] = {
    {"meters", "feet", 3.28084},
    {"meters", "inches", 39.3701},
    {"meters", "yards", 1.09361},
    {"meters", "miles", 0.00062},
    {"kilograms", "pounds", 2.20462},
    {"kilograms", "ounces", 35.274},
    {"liters", "gallons", 0.264172},
    {"liters", "quarts", 1.05669},
    {"liters", "pints", 2.11338},
    {"liters", "cups", 4.22675}
};

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <from_unit> <to_unit> <value>\n", argv[0]);
        return 1;
    }

    char *from_unit = argv[1];
    char *to_unit = argv[2];
    double value = atof(argv[3]);

    int found_conversion = 0;
    for (int i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(conversions[i].from_unit, from_unit) == 0 && strcmp(conversions[i].to_unit, to_unit) == 0) {
            double result = value * conversions[i].conversion_factor;
            printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
            found_conversion = 1;
            break;
        }
    }

    if (!found_conversion) {
        printf("Invalid conversion\n");
    }

    return 0;
}