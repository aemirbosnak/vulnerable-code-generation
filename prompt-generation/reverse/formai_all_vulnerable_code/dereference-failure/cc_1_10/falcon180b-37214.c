//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[*num_units].name = strdup(name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    Unit units[MAX_UNITS] = {0};
    int num_units = 0;

    add_unit(units, &num_units, "meter", 1.0);
    add_unit(units, &num_units, "kilometer", 1000.0);
    add_unit(units, &num_units, "inch", 0.0254);
    add_unit(units, &num_units, "foot", 0.3048);
    add_unit(units, &num_units, "yard", 0.9144);
    add_unit(units, &num_units, "mile", 160934.4);

    char from_unit[20];
    char to_unit[20];

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int from_index = -1;
    int to_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Error: Invalid unit(s).\n");
        return 1;
    }

    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}