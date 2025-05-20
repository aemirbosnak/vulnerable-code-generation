//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define GALLONS_TO_LITERS 3.78541
#define LITERS_TO_GALLONS 0.264172

// Define the unit types
typedef enum {
    INCHES,
    CENTIMETERS,
    POUNDS,
    KILOGRAMS,
    GALLONS,
    LITERS
} unit_type;

// Define the unit names
const char *unit_names[] = {
    "inches",
    "centimeters",
    "pounds",
    "kilograms",
    "gallons",
    "liters"
};

// Print the usage information
void print_usage() {
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("where <value> is the value to be converted\n");
    printf("      <from_unit> is the unit of the input value\n");
    printf("      <to_unit> is the unit of the output value\n");
    printf("Supported units are:\n");
    for (int i = 0; i < 6; i++) {
        printf("  - %s\n", unit_names[i]);
    }
}

// Convert a value from one unit to another
double convert_value(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to the base unit (inches)
    switch (from_unit) {
        case CENTIMETERS:
            value /= INCHES_TO_CENTIMETERS;
            break;
        case POUNDS:
            value /= POUNDS_TO_KILOGRAMS;
            break;
        case GALLONS:
            value /= GALLONS_TO_LITERS;
            break;
        default:
            break;
    }

    // Convert the value to the target unit
    switch (to_unit) {
        case CENTIMETERS:
            value *= INCHES_TO_CENTIMETERS;
            break;
        case POUNDS:
            value *= POUNDS_TO_KILOGRAMS;
            break;
        case GALLONS:
            value *= GALLONS_TO_LITERS;
            break;
        default:
            break;
    }

    return value;
}

// Get the unit type from the unit name
unit_type get_unit_type(const char *unit_name) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(unit_name, unit_names[i]) == 0) {
            return i;
        }
    }

    return -1;
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        print_usage();
        return 1;
    }

    // Get the value, from unit, and to unit
    double value = atof(argv[1]);
    unit_type from_unit = get_unit_type(argv[2]);
    unit_type to_unit = get_unit_type(argv[3]);

    // Check if the units are valid
    if (from_unit == -1 || to_unit == -1) {
        printf("Invalid unit(s) specified\n");
        return 1;
    }

    // Convert the value
    double converted_value = convert_value(value, from_unit, to_unit);

    // Print the result
    printf("%f %s = %f %s\n", value, unit_names[from_unit], converted_value, unit_names[to_unit]);

    return 0;
}