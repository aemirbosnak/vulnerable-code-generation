//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 5

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meters", 1.0},
    {"kilometers", 1000.0},
    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"liters", 1.0}
};

void print_units(void) {
    printf("Available units:\n");
    for (int i = 0; i < NUM_UNITS; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double value = atof(argv[1]);
    int from_unit_index = -1;
    int to_unit_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(argv[2], units[i].name) == 0) {
            from_unit_index = i;
            break;
        }
    }

    if (from_unit_index == -1) {
        printf("Invalid from unit: %s\n", argv[2]);
        return 1;
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(argv[3], units[i].name) == 0) {
            to_unit_index = i;
            break;
        }
    }

    if (to_unit_index == -1) {
        printf("Invalid to unit: %s\n", argv[3]);
        return 1;
    }

    double result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%f %s = %f %s\n", value, argv[2], result, argv[3]);

    return 0;
}