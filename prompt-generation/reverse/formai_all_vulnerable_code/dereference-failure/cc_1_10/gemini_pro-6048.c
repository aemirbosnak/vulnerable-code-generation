//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
// Linus Torvalds-style C unit converter

#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define CM_PER_INCH 2.54
#define INCH_PER_CM 1 / CM_PER_INCH
#define FEET_PER_METER 3.281
#define METER_PER_FEET 1 / FEET_PER_METER
#define POUNDS_PER_KILOGRAM 2.205
#define KILOGRAM_PER_POUND 1 / POUNDS_PER_KILOGRAM

// Define the unit types
enum unit_type {
    UNIT_CM,
    UNIT_INCH,
    UNIT_METER,
    UNIT_FEET,
    UNIT_KILOGRAM,
    UNIT_POUND
};

// Define the unit names
const char *unit_names[] = {
    "cm",
    "inch",
    "meter",
    "feet",
    "kilogram",
    "pound"
};

// Convert a value from one unit to another
double convert_units(double value, enum unit_type from, enum unit_type to)
{
    // Check if the units are the same
    if (from == to) {
        return value;
    }

    // Convert the value to the intermediate unit
    double intermediate_value;
    switch (from) {
        case UNIT_CM:
            intermediate_value = value * CM_PER_INCH;
            break;
        case UNIT_INCH:
            intermediate_value = value * INCH_PER_CM;
            break;
        case UNIT_METER:
            intermediate_value = value * FEET_PER_METER;
            break;
        case UNIT_FEET:
            intermediate_value = value * METER_PER_FEET;
            break;
        case UNIT_KILOGRAM:
            intermediate_value = value * POUNDS_PER_KILOGRAM;
            break;
        case UNIT_POUND:
            intermediate_value = value * KILOGRAM_PER_POUND;
            break;
        default:
            fprintf(stderr, "Unknown unit type: %d\n", from);
            exit(EXIT_FAILURE);
    }

    // Convert the value from the intermediate unit to the desired unit
    switch (to) {
        case UNIT_CM:
            return intermediate_value / CM_PER_INCH;
        case UNIT_INCH:
            return intermediate_value * INCH_PER_CM;
        case UNIT_METER:
            return intermediate_value / FEET_PER_METER;
        case UNIT_FEET:
            return intermediate_value * METER_PER_FEET;
        case UNIT_KILOGRAM:
            return intermediate_value / POUNDS_PER_KILOGRAM;
        case UNIT_POUND:
            return intermediate_value * KILOGRAM_PER_POUND;
        default:
            fprintf(stderr, "Unknown unit type: %d\n", to);
            exit(EXIT_FAILURE);
    }
}

// Print the usage message
void print_usage(void)
{
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("Where:\n");
    printf("  <value> is the value to convert\n");
    printf("  <from_unit> is the unit of the value to convert\n");
    printf("  <to_unit> is the unit to convert the value to\n");
    printf("\n");
    printf("Valid units are:\n");
    for (int i = 0; i < UNIT_POUND + 1; i++) {
        printf("  %s\n", unit_names[i]);
    }
}

// Main function
int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Parse the arguments
    double value = atof(argv[1]);
    enum unit_type from = -1;
    enum unit_type to = -1;
    for (int i = 0; i < UNIT_POUND + 1; i++) {
        if (strcmp(argv[2], unit_names[i]) == 0) {
            from = i;
        }
        if (strcmp(argv[3], unit_names[i]) == 0) {
            to = i;
        }
    }

    // Check if the units are valid
    if (from == -1 || to == -1) {
        print_usage();
        return EXIT_FAILURE;
    }

    // Convert the value
    double converted_value = convert_units(value, from, to);

    // Print the result
    printf("%f %s = %f %s\n", value, unit_names[from], converted_value, unit_names[to]);

    return EXIT_SUCCESS;
}