//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_OPERATIONS 5

typedef struct {
    char *name;
    double value;
} unit_t;

unit_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"inch", 0.01},
    {"foot", 12},
    {"yard", 36},
    {"mile", 5280},
    {"gram", 0.001},
    {"kilogram", 1000},
    {"pound", 453.592},
    {"ounce", 0.0283495},
    {"fluid_ounce", 0.0295736},
    {"cup", 0.0832764}
};

void convert_unit(unit_t *unit, double value) {
    int i = 0;
    while (i < UNIT_CONVERTER_MAX_UNITS && strcmp(units[i].name, unit->name) != 0) i++;
    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit: %s\n", unit->name);
        return;
    }
    double result = value * units[i].value / units[i - 1].value;
    unit->value = result;
}

int main() {
    unit_t unit;
    double value;

    printf("Enter a unit: ");
    scanf("%s", unit.name);
    printf("Enter a value: ");
    scanf("%lf", &value);

    convert_unit(&unit, value);

    printf("Result: %s (%lf)\n", unit.name, unit.value);

    return 0;
}