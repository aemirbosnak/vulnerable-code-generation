//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"km", 1000.0},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"l", 1.0},
    {"ml", 0.001},
    {"fl oz", 0.0295735},
    {"gal", 3.78541},
    {"c", 1.0},
    {"f", 1.8},
    {"k", -273.15},
    {"°C", 1.0},
    {"°F", 1.8},
    {"k", 1.0},
    {NULL, 0.0}
};

int main() {
    char input[100];
    char *unit;
    double value;
    int i;

    printf("Enter a value and a unit of measurement:\n");
    scanf("%s %s", input, unit);

    for (i = 0; units[i].name!= NULL; i++) {
        if (strcmp(unit, units[i].name) == 0) {
            value = strtod(input, NULL) * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, units[i].name, value, "m");
            break;
        }
    }

    if (units[i].name == NULL) {
        printf("Invalid unit of measurement.\n");
    }

    return 0;
}