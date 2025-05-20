//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 5
#define MAX_CONVERSIONS 5

struct unit {
    const char *name;
    double factor;
};

struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

static struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12.0},
    {"yard", 36.0},
    {"mile", 5280.0},
    {"light-year", 5.88e12}
};

static struct conversion conversions[MAX_CONVERSIONS] = {
    {"inch", "foot", 1.0},
    {"foot", "yard", 0.3048},
    {"yard", "mile", 0.025625},
    {"mile", "light-year", 0.00000671},
    {"light-year", "inch", 5.88e12}
};

void print_units(void) {
    int i;
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%s: %f\n", units[i].name, units[i].factor);
    }
}

void print_conversions(void) {
    int i, j;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            if (i != j) {
                printf("%s (%s) = %f %s\n", conversions[i].from_unit, conversions[i].to_unit, conversions[i].factor * conversions[j].factor, conversions[j].to_unit);
            }
        }
    }
}

void convert(double value, const char *from_unit, const char *to_unit) {
    int i = 0;
    for (; i < MAX_UNITS; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return;
    }
    for (; i < MAX_CONVERSIONS; i++) {
        if (strcmp(conversions[i].from_unit, from_unit) == 0) {
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Invalid conversion: %s to %s\n", from_unit, to_unit);
        return;
    }
    value *= conversions[i].factor;
    value /= conversions[i].factor;
    printf("%f %s = %f %s\n", value, to_unit, value, from_unit);
}

int main(void) {
    double value;
    const char *from_unit, *to_unit;

    printf("Welcome to the Unit Converter!\n");

    while (1) {
        printf("Enter a value: ");
        scanf("%lf", &value);

        printf("Enter a unit (inch, foot, yard, mile, light-year): ");
        scanf("%s", &from_unit);

        printf("Enter a conversion (inch, foot, yard, mile, light-year): ");
        scanf("%s", &to_unit);

        convert(value, from_unit, to_unit);
    }

    return 0;
}