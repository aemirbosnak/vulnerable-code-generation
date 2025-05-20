//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Our trusty magnifying glass for unit conversion
typedef struct {
    char *name;
    double factor;
} Unit;

// A collection of common units of measure
Unit units[] = {
    {"inches", 2.54},
    {"feet", 30.48},
    {"yards", 91.44},
    {"miles", 1609.34},
    {"centimeters", 1},
    {"meters", 100},
    {"kilometers", 100000},
};

// The main investigation: unit conversion
int main(int argc, char *argv[]) {
    // Check if we have a valid case
    if (argc != 4) {
        printf("Elementary, my dear Watson! You must provide the following arguments:\n");
        printf("\t1. The value to be converted\n");
        printf("\t2. The unit of the value\n");
        printf("\t3. The unit to convert to\n");
        return EXIT_FAILURE;
    }

    // Parse the provided information
    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    // Find the factors for the provided units
    double from_factor = 1.0;
    double to_factor = 1.0;
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_factor = units[i].factor;
        }
        if (strcmp(to_unit, units[i].name) == 0) {
            to_factor = units[i].factor;
        }
    }

    // Perform the conversion
    double converted_value = value * from_factor / to_factor;

    // Display the results
    printf("The converted value is: %.2f %s\n", converted_value, to_unit);

    return EXIT_SUCCESS;
}