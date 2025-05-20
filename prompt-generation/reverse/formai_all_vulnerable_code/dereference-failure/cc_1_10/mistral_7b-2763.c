//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unit[10];
    double conversion_factor;
} UnitConversionFactor;

const UnitConversionFactor units[] = {
    {"miles", 0.000621371},
    {"kilometers", 1.60934},
    {"pounds", 0.453592},
    {"kilograms", 2.20462},
    {"degrees Fahrenheit", 1.8},
    {"degrees Celsius", 1.0},
    {"ounces", 0.068521},
    {"grams", 0.035274},
    {"liters", 0.035264},
    {"gallons", 3.78541}
};

int get_unit_index(const char *unit) {
    int i;
    for (i = 0; i < 10; ++i) {
        if (strcmp(units[i].unit, unit) == 0) {
            return i;
        }
    }
    return -1;
}

void print_usage_and_exit() {
    printf("Usage: unit_converter <source_unit> <value> <destination_unit>\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage_and_exit();
    }

    int source_unit_index = get_unit_index(argv[1]);
    if (source_unit_index == -1) {
        printf("Invalid source unit: %s\n", argv[1]);
        print_usage_and_exit();
    }

    double source_value = atof(argv[2]);

    int destination_unit_index = get_unit_index(argv[3]);
    if (destination_unit_index == -1) {
        printf("Invalid destination unit: %s\n", argv[3]);
        print_usage_and_exit();
    }

    double conversion_factor = units[source_unit_index].conversion_factor * units[destination_unit_index].conversion_factor;
    double result = source_value * conversion_factor;

    printf("Value of %lf %s is %lf %s\n", source_value, argv[1], result, argv[3]);

    return 0;
}