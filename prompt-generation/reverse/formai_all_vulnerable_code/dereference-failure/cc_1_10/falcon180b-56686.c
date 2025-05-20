//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 1000

typedef struct {
    char name[20];
    double factor;
    char *unit;
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor, char *unit) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    strcpy(units[*num_units].name, name);
    units[*num_units].factor = factor;
    strcpy(units[*num_units].unit, unit);

    (*num_units)++;
}

void print_units(Unit *units, int num_units) {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s (%s)\n", units[i].name, units[i].unit);
    }
}

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;

    add_unit(units, &num_units, "Length", 1.0, "m");
    add_unit(units, &num_units, "Mass", 1.0, "kg");
    add_unit(units, &num_units, "Time", 1.0, "s");
    add_unit(units, &num_units, "Temperature", 1.0, "K");

    print_units(units, num_units);

    char from_unit[20], to_unit[20];
    double value, result;

    printf("\nEnter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].unit) == 0 && strcmp(to_unit, units[i].unit) == 0) {
            result = value * units[i].factor;
            printf("Result: %lf %s\n", result, units[i].unit);
            break;
        }
    }

    return 0;
}