//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the unit types
enum unit_type {
    LENGTH,
    MASS,
    TEMPERATURE
};

// Define the unit conversions
struct unit_conversion {
    char *name;
    double factor;
};

// Define the unit types and conversions
struct unit_type_info {
    char *name;
    enum unit_type type;
    struct unit_conversion *conversions;
    int num_conversions;
};

// Define the unit types and conversions
struct unit_type_info unit_types[] = {
    { "Length", LENGTH, (struct unit_conversion[]) {
        { "meter", 1.0 },
        { "kilometer", 1000.0 },
        { "mile", 1609.34 },
        { "foot", 0.3048 },
        { "inch", 0.0254 }
    }, 5 },
    { "Mass", MASS, (struct unit_conversion[]) {
        { "kilogram", 1.0 },
        { "gram", 0.001 },
        { "pound", 0.453592 },
        { "ounce", 0.0283495 }
    }, 4 },
    { "Temperature", TEMPERATURE, (struct unit_conversion[]) {
        { "celsius", 1.0 },
        { "fahrenheit", (5.0 / 9.0) },
        { "kelvin", 1.0 + 273.15 }
    }, 3 }
};

// Define the number of unit types
int num_unit_types = sizeof(unit_types) / sizeof(struct unit_type_info);

// Function to convert a value from one unit to another
double convert_unit(double value, char *from_unit, char *to_unit) {
    // Find the unit types for the from and to units
    struct unit_type_info *from_type = NULL;
    struct unit_type_info *to_type = NULL;
    for (int i = 0; i < num_unit_types; i++) {
        if (strcmp(unit_types[i].name, from_unit) == 0) {
            from_type = &unit_types[i];
        }
        if (strcmp(unit_types[i].name, to_unit) == 0) {
            to_type = &unit_types[i];
        }
    }

    // Check if the unit types are valid
    if (from_type == NULL || to_type == NULL) {
        fprintf(stderr, "Invalid unit types: %s and %s\n", from_unit, to_unit);
        return NAN;
    }

    // Check if the unit types are the same
    if (from_type == to_type) {
        return value;
    }

    // Find the conversion factor from the from unit to the to unit
    double conversion_factor = 1.0;
    for (int i = 0; i < from_type->num_conversions; i++) {
        if (strcmp(from_type->conversions[i].name, to_unit) == 0) {
            conversion_factor = from_type->conversions[i].factor;
            break;
        }
    }

    // Convert the value
    return value * conversion_factor;
}

// Function to print the help message
void print_help() {
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("Example: unit_converter 100 meter kilometer\n");
    printf("\nSupported unit types:\n");
    for (int i = 0; i < num_unit_types; i++) {
        printf(" - %s\n", unit_types[i].name);
    }
    printf("\nSupported unit conversions:\n");
    for (int i = 0; i < num_unit_types; i++) {
        for (int j = 0; j < unit_types[i].num_conversions; j++) {
            printf(" - %s to %s\n", unit_types[i].conversions[j].name, unit_types[i].name);
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the number of arguments is valid
    if (argc != 4) {
        print_help();
        return EXIT_FAILURE;
    }

    // Parse the arguments
    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    // Convert the value
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the result
    printf("%f %s = %f %s\n", value, from_unit, converted_value, to_unit);

    return EXIT_SUCCESS;
}