//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERT_UNITS 10

struct convert_unit {
    char *name;
    char *symbol;
    double factor;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>...\n", argv[0]);
        return 1;
    }

    double value = strtod(argv[1], NULL);
    int num_units = argc - 2;
    struct convert_unit units[MAX_CONVERT_UNITS];

    for (int i = 0; i < num_units; i++) {
        char *unit_name = argv[i + 2];
        char *unit_symbol = strchr(unit_name, ':');
        if (unit_symbol == NULL) {
            fprintf(stderr, "Invalid unit format: %s\n", unit_name);
            return 1;
        }
        *unit_symbol = '\0';
        unit_symbol++;

        units[i].name = strdup(unit_name);
        units[i].symbol = strdup(unit_symbol);
        units[i].factor = 1.0;
    }

    for (int i = 0; i < num_units - 1; i++) {
        double factor = strtod(units[i].symbol, NULL);
        for (int j = i + 1; j < num_units; j++) {
            double to_factor = strtod(units[j].symbol, NULL);
            if (factor == to_factor) {
                fprintf(stderr, "Cannot convert from %s to %s\n", units[i].name, units[j].name);
                return 1;
            }
        }
        units[i].factor = factor;
    }

    for (int i = num_units - 1; i >= 0; i--) {
        value /= units[i].factor;
    }

    printf("%.2f %s = ", value, units[0].name);
    for (int i = 1; i < num_units; i++) {
        printf("%.2f %s ", value, units[i].name);
    }

    for (int i = 0; i < num_units; i++) {
        free(units[i].name);
        free(units[i].symbol);
    }

    return 0;
}