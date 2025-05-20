//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units to be converted
typedef enum {
    UNIT_NONE,
    UNIT_METER,
    UNIT_CENTIMETER,
    UNIT_MILLIMETER,
    UNIT_KILOMETER,
    UNIT_INCH,
    UNIT_FOOT,
    UNIT_YARD,
    UNIT_MILE,
    UNIT_POUND,
    UNIT_OUNCE,
    UNIT_GRAM,
    UNIT_KILOGRAM,
    UNIT_LITER,
    UNIT_MILLILITER,
    UNIT_GALLON,
    UNIT_QUART,
    UNIT_PINT,
    UNIT_CUP,
    UNIT_TABLESPOON,
    UNIT_TEASPOON
} Unit;

// Define the conversion factors
typedef struct {
    double factor;
    char *name;
} Conversion;

// Define the available conversions
static Conversion conversions[] = {
    {1.0, "m"},
    {1.0/100.0, "cm"},
    {1.0/1000.0, "mm"},
    {1.0/1000000.0, "km"},
    {2.54, "in"},
    {12.0, "ft"},
    {3.0, "yd"},
    {0.000621371, "mi"},
    {453.592, "lb"},
    {28.3495, "oz"},
    {0.035274, "oz"},
    {0.001, "g"},
    {1.0, "kg"},
    {1.0/4.546, "l"},
    {0.004546, "l"},
    {3.78541, "l"},
    {0.946353, "l"},
    {0.236588, "l"}
};

// Define the number of conversions available
#define NUM_CONVERSIONS (sizeof(conversions)/sizeof(conversions[0]))

// Define the main function
int main(int argc, char *argv[])
{
    int i;
    double value, result;
    Unit from_unit, to_unit;
    char *from_unit_name, *to_unit_name;

    // Check if the correct number of arguments are provided
    if (argc!= 5) {
        printf("Usage: %s <from_unit> <to_unit> <value>\n", argv[0]);
        return 1;
    }

    // Get the from and to units from the command line arguments
    from_unit_name = argv[1];
    to_unit_name = argv[2];

    // Find the indices of the from and to units
    for (i = 0; i < NUM_CONVERSIONS; i++) {
        if (strcmp(from_unit_name, conversions[i].name) == 0) {
            from_unit = (Unit)i;
        }
        if (strcmp(to_unit_name, conversions[i].name) == 0) {
            to_unit = (Unit)i;
        }
    }

    // Check if the from and to units are valid
    if (from_unit == UNIT_NONE || to_unit == UNIT_NONE) {
        printf("Invalid unit(s).\n");
        return 1;
    }

    // Get the value to be converted
    value = atof(argv[3]);

    // Convert the value
    result = value * conversions[from_unit].factor;

    // Round the result to 2 decimal places
    result = round(result * 100) / 100;

    // Print the result
    printf("%.2f %s = %.2f %s\n", value, conversions[from_unit].name, result, conversions[to_unit].name);

    return 0;
}