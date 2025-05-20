//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"nautical mile", 1852.0},
    {"light year", 9460730472580800.0},
    {"astronomical unit", 149597870700.0}
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <value> <from-unit> <to-unit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    int from_unit_index = -1;
    int to_unit_index = -1;

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
        } else if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
        }

        if (from_unit_index != -1 && to_unit_index != -1) {
            break;
        }
    }

    if (from_unit_index == -1) {
        fprintf(stderr, "Invalid from unit: %s\n", from_unit);
        return EXIT_FAILURE;
    }

    if (to_unit_index == -1) {
        fprintf(stderr, "Invalid to unit: %s\n", to_unit);
        return EXIT_FAILURE;
    }

    double converted_value = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%f %s = %f %s\n", value, from_unit, converted_value, to_unit);

    return EXIT_SUCCESS;
}