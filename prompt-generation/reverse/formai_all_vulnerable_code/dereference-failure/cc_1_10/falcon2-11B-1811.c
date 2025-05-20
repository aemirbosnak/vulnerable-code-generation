//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Unit {
    const char* name;
    double factor;
};

static const struct Unit unit_table[] = {
    {"meters", 1.0},
    {"kilometers", 0.001},
    {"miles", 0.000621371},
    {"feet", 3.2808399},
    {"inches", 39.3700787},

    {"grams", 1.0},
    {"kilograms", 1000.0},
    {"pounds", 0.453592},

    {"kelvin", 1.0},
    {"celsius", 273.15},
    {"fahrenheit", 1.8},
};

int main() {
    double input_value, output_value;
    const char* input_unit, *output_unit;
    int i, n_units;

    n_units = sizeof(unit_table) / sizeof(struct Unit);
    printf("Enter a value:\n");
    scanf("%lf", &input_value);

    printf("Enter the unit of measurement (m/km/mi/ft/in/g/kg/lb/K/C/F):\n");
    scanf("%s", input_unit);

    for (i = 0; i < n_units; i++) {
        if (strcmp(input_unit, unit_table[i].name) == 0) {
            output_unit = unit_table[i].name;
            break;
        }
    }

    if (i == n_units) {
        printf("Invalid unit of measurement.\n");
        return 1;
    }

    printf("Enter the desired unit of measurement (m/km/mi/ft/in/g/kg/lb/K/C/F):\n");
    scanf("%s", output_unit);

    for (i = 0; i < n_units; i++) {
        if (strcmp(output_unit, unit_table[i].name) == 0) {
            output_value = input_value * unit_table[i].factor;
            break;
        }
    }

    if (i == n_units) {
        printf("Invalid unit of measurement.\n");
        return 1;
    }

    printf("%.2lf %s = %.2lf %s\n", input_value, input_unit, output_value, output_unit);

    return 0;
}