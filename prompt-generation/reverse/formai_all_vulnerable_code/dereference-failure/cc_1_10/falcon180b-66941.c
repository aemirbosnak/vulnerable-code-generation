//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define UNIT_COUNT 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[UNIT_COUNT] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"lb", 0.453592},
    {"kg", 1.0},
    {"gal", 3.78541},
    {"l", 1.0},
    {"c", 1.0},
    {"f", 1.8}
};

int main() {
    char input[100];
    char *unit_name;
    double value, result;
    int i;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter a value and the unit you want to convert from and to.\n");
    printf("For example: 10 kg to lb\n");
    scanf("%s", input);

    unit_name = strtok(input, " ");
    value = atof(strtok(NULL, " "));

    for (i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            break;
        }
    }

    if (i == UNIT_COUNT) {
        printf("Invalid unit: %s\n", unit_name);
        return 1;
    }

    printf("Enter the unit you want to convert to:\n");
    scanf("%s", input);

    for (i = 0; i < UNIT_COUNT; i++) {
        if (strcmp(input, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%g %s = %g %s\n", value, unit_name, result, input);
            return 0;
        }
    }

    printf("Invalid unit: %s\n", input);
    return 1;
}