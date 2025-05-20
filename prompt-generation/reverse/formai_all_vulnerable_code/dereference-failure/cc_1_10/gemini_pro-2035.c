//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the conversion types.
#define CONVERSION_TYPE_LENGTH 0
#define CONVERSION_TYPE_MASS 1
#define CONVERSION_TYPE_VOLUME 2
#define CONVERSION_TYPE_TEMPERATURE 3

// Define the units of measurement.
#define UNIT_TYPE_METER 0
#define UNIT_TYPE_KILOMETER 1
#define UNIT_TYPE_MILE 2
#define UNIT_TYPE_GRAM 3
#define UNIT_TYPE_KILOGRAM 4
#define UNIT_TYPE_POUND 5
#define UNIT_TYPE_LITER 6
#define UNIT_TYPE_GALLON 7
#define UNIT_TYPE_CELSIUS 8
#define UNIT_TYPE_FAHRENHEIT 9

// Define the conversion factors.
static const double conversion_factors[][10] = {
    {   1.0,  1000.0, 1609.34, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    1.0,  1.60934, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    0.621371,  1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    0.0, 0.0,  1.0,  1000.0, 35.274, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    0.0, 0.0,  0.0,    1.0,  2.20462, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    0.0, 0.0,  0.0,    0.453592,  1.0, 0.0, 0.0, 0.0, 0.0 },
    {   0.0,    0.0, 0.0,  0.0,    0.0,  0.0,  1.0,  1000.0, 0.0, 0.0 },
    {   0.0,    0.0, 0.0,  0.0,    0.0,  0.0,  0.0,    1.0, 3.78541, 0.0 },
    {   0.0,    0.0, 0.0,  0.0,    0.0,  0.0,  0.0,    0.0,    1.0, 180.0 },
    {   0.0,    0.0, 0.0,  0.0,    0.0,  0.0,  0.0,    0.0,    0.0,  1.0 }
};

// Define the unit names.
static const char *unit_names[] = {
    "meter", "kilometer", "mile", "gram", "kilogram", "pound", "liter", "gallon", "celsius", "fahrenheit"
};

// Get the conversion type.
static int get_conversion_type(const char *conversion_type) {
    if (strcmp(conversion_type, "length") == 0) {
        return CONVERSION_TYPE_LENGTH;
    } else if (strcmp(conversion_type, "mass") == 0) {
        return CONVERSION_TYPE_MASS;
    } else if (strcmp(conversion_type, "volume") == 0) {
        return CONVERSION_TYPE_VOLUME;
    } else if (strcmp(conversion_type, "temperature") == 0) {
        return CONVERSION_TYPE_TEMPERATURE;
    } else {
        return -1;
    }
}

// Get the unit type.
static int get_unit_type(const char *unit_type) {
    if (strcmp(unit_type, "meter") == 0) {
        return UNIT_TYPE_METER;
    } else if (strcmp(unit_type, "kilometer") == 0) {
        return UNIT_TYPE_KILOMETER;
    } else if (strcmp(unit_type, "mile") == 0) {
        return UNIT_TYPE_MILE;
    } else if (strcmp(unit_type, "gram") == 0) {
        return UNIT_TYPE_GRAM;
    } else if (strcmp(unit_type, "kilogram") == 0) {
        return UNIT_TYPE_KILOGRAM;
    } else if (strcmp(unit_type, "pound") == 0) {
        return UNIT_TYPE_POUND;
    } else if (strcmp(unit_type, "liter") == 0) {
        return UNIT_TYPE_LITER;
    } else if (strcmp(unit_type, "gallon") == 0) {
        return UNIT_TYPE_GALLON;
    } else if (strcmp(unit_type, "celsius") == 0) {
        return UNIT_TYPE_CELSIUS;
    } else if (strcmp(unit_type, "fahrenheit") == 0) {
        return UNIT_TYPE_FAHRENHEIT;
    } else {
        return -1;
    }
}

// Convert the value.
static double convert_value(double value, int from_unit_type, int to_unit_type) {
    return value * conversion_factors[from_unit_type][to_unit_type];
}

// Print the result.
static void print_result(double value, const char *to_unit_type) {
    printf("%f %s\n", value, to_unit_type);
}

int main( int argc, char* argv[] )
{
    // Check if the user specified the correct number of arguments.
    if (argc != 5) {
        printf("Usage: %s conversion_type value from_unit_type to_unit_type\n", argv[0]);
        return 1;
    }

    // Get the conversion type.
    int conversion_type = get_conversion_type(argv[1]);
    if (conversion_type == -1) {
        printf("Invalid conversion type: %s\n", argv[1]);
        return 1;
    }

    // Get the value.
    double value = atof(argv[2]);

    // Get the from unit type.
    int from_unit_type = get_unit_type(argv[3]);
    if (from_unit_type == -1) {
        printf("Invalid from unit type: %s\n", argv[3]);
        return 1;
    }

    // Get the to unit type.
    int to_unit_type = get_unit_type(argv[4]);
    if (to_unit_type == -1) {
        printf("Invalid to unit type: %s\n", argv[4]);
        return 1;
    }

    // Convert the value.
    double converted_value = convert_value(value, from_unit_type, to_unit_type);

    // Print the result.
    print_result(converted_value, unit_names[to_unit_type]);

    return 0;
}