//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_UNITS 7

typedef struct {
    char *name;
    double factor;
    char *abbreviation;
} Unit;

Unit units[NUM_UNITS] = {
    {"meter", 1.0, "m"},
    {"kilometer", 1000.0, "km"},
    {"gram", 1.0, "g"},
    {"kilogram", 1000.0, "kg"},
    {"liter", 1.0, "L"},
    {"milliliter", 0.001, "ml"},
    {"second", 1.0, "s"}
};

int main() {
    char input[100];
    char *token;
    int i;
    double value, result;
    Unit *from_unit, *to_unit;

    printf("Enter a value to convert:\n");
    fgets(input, sizeof(input), stdin);
    value = strtod(input, NULL);

    printf("Enter the unit to convert from:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(token, units[i].name) == 0 || strcmp(token, units[i].abbreviation) == 0) {
            from_unit = &units[i];
            break;
        }
    }

    printf("Enter the unit to convert to:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    for (i = 0; i < NUM_UNITS; i++) {
        if (strcmp(token, units[i].name) == 0 || strcmp(token, units[i].abbreviation) == 0) {
            to_unit = &units[i];
            break;
        }
    }

    result = (value * from_unit->factor) / to_unit->factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit->name, result, to_unit->name);

    return 0;
}