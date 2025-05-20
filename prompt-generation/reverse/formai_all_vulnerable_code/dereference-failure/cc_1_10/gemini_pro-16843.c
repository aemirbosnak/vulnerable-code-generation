//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_PER_FEET 12
#define FEET_PER_YARD 3
#define YARDS_PER_MILE 1760
#define MILES_PER_KILOMETER 1.60934

// Define the unit types
enum unit_type {
    INCHES,
    FEET,
    YARDS,
    MILES,
    KILOMETERS
};

// Define the unit names
char *unit_names[] = {
    "inches",
    "feet",
    "yards",
    "miles",
    "kilometers"
};

// Convert a value from one unit to another
double convert_units(double value, enum unit_type from_unit, enum unit_type to_unit)
{
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to inches
    double inches = 0;
    switch (from_unit) {
        case INCHES:
            inches = value;
            break;
        case FEET:
            inches = value * INCHES_PER_FEET;
            break;
        case YARDS:
            inches = value * INCHES_PER_FEET * FEET_PER_YARD;
            break;
        case MILES:
            inches = value * INCHES_PER_FEET * FEET_PER_YARD * YARDS_PER_MILE;
            break;
        case KILOMETERS:
            inches = value * INCHES_PER_FEET * FEET_PER_YARD * YARDS_PER_MILE * MILES_PER_KILOMETER;
            break;
    }

    // Convert the value from inches to the desired unit
    double result = 0;
    switch (to_unit) {
        case INCHES:
            result = inches;
            break;
        case FEET:
            result = inches / INCHES_PER_FEET;
            break;
        case YARDS:
            result = inches / INCHES_PER_FEET / FEET_PER_YARD;
            break;
        case MILES:
            result = inches / INCHES_PER_FEET / FEET_PER_YARD / YARDS_PER_MILE;
            break;
        case KILOMETERS:
            result = inches / INCHES_PER_FEET / FEET_PER_YARD / YARDS_PER_MILE / MILES_PER_KILOMETER;
            break;
    }

    return result;
}

// Print the help message
void print_help()
{
    printf("Unit converter\n");
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("Example: unit_converter 10 feet inches\n");
    printf("Supported units: inches, feet, yards, miles, kilometers\n");
}

// Parse the command line arguments
int main(int argc, char *argv[])
{
    // Check if the number of arguments is correct
    if (argc != 4) {
        print_help();
        return 1;
    }

    // Parse the value
    double value = atof(argv[1]);

    // Parse the from unit
    enum unit_type from_unit;
    for (int i = 0; i < 5; i++) {
        if (strcmp(argv[2], unit_names[i]) == 0) {
            from_unit = i;
            break;
        }
    }

    // Parse the to unit
    enum unit_type to_unit;
    for (int i = 0; i < 5; i++) {
        if (strcmp(argv[3], unit_names[i]) == 0) {
            to_unit = i;
            break;
        }
    }

    // Convert the value
    double result = convert_units(value, from_unit, to_unit);

    // Print the result
    printf("%f %s is equal to %f %s\n", value, unit_names[from_unit], result, unit_names[to_unit]);

    return 0;
}