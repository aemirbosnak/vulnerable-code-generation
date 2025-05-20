//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 10

struct unit_type {
    char *name;
    double factor;
};

struct unit_type units[MAX_UNITS];

int main() {
    int num_units, i;
    char input[100];

    // Initialize units
    units[0].name = "meter";
    units[0].factor = 1.0;

    units[1].name = "kilometer";
    units[1].factor = 0.001;

    units[2].name = "centimeter";
    units[2].factor = 100.0;

    units[3].name = "millimeter";
    units[3].factor = 1000.0;

    units[4].name = "inch";
    units[4].factor = 0.393701;

    units[5].name = "foot";
    units[5].factor = 3.28084;

    units[6].name = "yard";
    units[6].factor = 1.09361;

    units[7].name = "mile";
    units[7].factor = 0.000621371;

    units[8].name = "ounce";
    units[8].factor = 0.035274;

    units[9].name = "pound";
    units[9].factor = 0.453592;

    // Prompt user for input
    printf("Enter a value and its unit (e.g. 5.5 meter): ");
    scanf("%s", input);

    // Extract value and unit from input
    char *value_str = strtok(input, " ");
    char *unit_str = strtok(NULL, " ");

    // Convert value to numeric format
    double value = atof(value_str);

    // Convert unit to uppercase for comparison
    for (i = 0; i < strlen(unit_str); i++) {
        unit_str[i] = toupper(unit_str[i]);
    }

    // Check if unit is valid
    int unit_found = 0;
    for (i = 0; i < num_units; i++) {
        if (strcmp(unit_str, units[i].name) == 0) {
            unit_found = 1;
            break;
        }
    }

    // Convert value to desired unit
    if (unit_found) {
        double result = value * units[i].factor;
        printf("%.2f %s = %.2f %s\n", value, unit_str, result, units[i].name);
    } else {
        printf("Invalid unit\n");
    }

    return 0;
}