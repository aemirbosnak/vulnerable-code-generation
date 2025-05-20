//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_LENGTH 20
#define UNIT_CONVERTER_DELIM " -> "

struct unit_converter {
    char name[UNIT_CONVERTER_MAX_LENGTH];
    int conversion_factor;
};

int main() {
    struct unit_converter units[] = {
        {"second", 1},
        {"minute", 60},
        {"hour", 3600},
        {"day", 86400},
        {"kilogram", 1000},
        {"gram", 0.001},
        {"liter", 1000},
        {"milliliter", 0.001},
        {"meter", 1},
        {"centimeter", 0.01},
        {" millimeter", 0.001},
        {"pound", 453.592},
        {"ounce", 0.0283495},
        {"inch", 2.54},
        {"foot", 12},
        {"yard", 36},
        {"mile", 5280},
        {" Celsius", 0.01 * (100 - 32) / 5},
        {"Fahrenheit", 1.8 * (100 - 32) / 5}
    };

    int input_unit, output_unit;
    double input_value, output_value;

    printf("Welcome to the Unit Converter! Please enter a value and a unit of measurement:\n");

    scanf("%lf %s", &input_value, &input_unit);

    for (int i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            output_unit = units[i].name;
            output_value = input_value * units[i].conversion_factor;
            break;
        }
    }

    if (output_unit == NULL) {
        printf("Invalid unit selected. Please try again.\n");
        return 1;
    }

    printf("Your value of %lf %s is equal to %lf %s\n", input_value, input_unit, output_value, output_unit);

    return 0;
}