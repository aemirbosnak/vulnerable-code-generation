//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
    int index;
} Unit;

Unit units[MAX_UNITS] = {
    {"meters", 1.0, 0},
    {"feet", 0.3048, 1},
    {"inches", 0.0254, 2},
    {"kilograms", 1.0, 3},
    {"pounds", 2.20462, 4},
    {"grams", 0.001, 5},
    {"ounces", 0.0283495, 6},
    {"liters", 1.0, 7},
    {"gallons", 3.78541, 8},
    {"celsius", 1.0, 9}
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double value = atof(argv[1]);
    int from_unit = -1, to_unit = -1;

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(argv[2], units[i].name) == 0) {
            from_unit = i;
            break;
        }
    }

    if (from_unit == -1) {
        printf("Invalid from unit: %s\n", argv[2]);
        return 1;
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(argv[3], units[i].name) == 0) {
            to_unit = i;
            break;
        }
    }

    if (to_unit == -1) {
        printf("Invalid to unit: %s\n", argv[3]);
        return 1;
    }

    double result = value * units[from_unit].factor / units[to_unit].factor;

    printf("%.2f %s = %.2f %s\n", value, units[from_unit].name, result, units[to_unit].name);

    return 0;
}