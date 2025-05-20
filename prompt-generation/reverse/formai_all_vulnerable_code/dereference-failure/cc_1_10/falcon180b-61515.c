//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    Unit units[MAX_UNITS];
    int num_units = 0;

    units[num_units].name = "m";
    units[num_units].factor = 1.0;
    num_units++;

    units[num_units].name = "km";
    units[num_units].factor = 1000.0;
    num_units++;

    units[num_units].name = "cm";
    units[num_units].factor = 0.01;
    num_units++;

    units[num_units].name = "mm";
    units[num_units].factor = 0.001;
    num_units++;

    units[num_units].name = "in";
    units[num_units].factor = 0.0254;
    num_units++;

    units[num_units].name = "ft";
    units[num_units].factor = 0.3048;
    num_units++;

    units[num_units].name = "yd";
    units[num_units].factor = 0.9144;
    num_units++;

    units[num_units].name = "mi";
    units[num_units].factor = 160934.4;
    num_units++;

    int from_unit_index = -1;
    int to_unit_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
        }

        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid units.\n");
        return 1;
    }

    double result = value * units[from_unit_index].factor / units[to_unit_index].factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}