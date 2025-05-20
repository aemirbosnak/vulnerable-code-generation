//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the supported unit types
enum unit_type {
    LENGTH,
    MASS,
    TEMPERATURE
};

// Define the supported units for each unit type
struct unit {
    enum unit_type type;
    char *name;
    double conversion_factor;
};

// Define the supported units for length
struct unit length_units[] = {
    {LENGTH, "centimeters", 1.0},
    {LENGTH, "meters", 100.0},
    {LENGTH, "inches", 2.54},
    {LENGTH, "feet", 30.48},
    {LENGTH, "yards", 91.44},
    {LENGTH, "miles", 160934.4}
};

// Define the supported units for mass
struct unit mass_units[] = {
    {MASS, "grams", 1.0},
    {MASS, "kilograms", 1000.0},
    {MASS, "ounces", 28.35},
    {MASS, "pounds", 453.592},
    {MASS, "tons", 907184.74}
};

// Define the supported units for temperature
struct unit temperature_units[] = {
    {TEMPERATURE, "celsius", 1.0},
    {TEMPERATURE, "fahrenheit", 1.8},
    {TEMPERATURE, "kelvin", 273.15}
};

// Get the unit index for a given unit name
int get_unit_index(struct unit *units, int num_units, char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

// Convert a value from one unit to another
double convert_units(double value, struct unit *from_unit, struct unit *to_unit) {
    if (from_unit->type != to_unit->type) {
        fprintf(stderr, "Error: Cannot convert between different unit types\n");
        return 0.0;
    }

    return value * to_unit->conversion_factor / from_unit->conversion_factor;
}

// Print the supported units for a given unit type
void print_units(struct unit *units, int num_units) {
    printf("Supported units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("    %s\n", units[i].name);
    }
}

int main(int argc, char *argv[]) {
    // Check if the user specified a value to convert
    if (argc < 4) {
        fprintf(stderr, "Usage: %s value from_unit to_unit\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the value to convert
    double value = atof(argv[1]);

    // Get the from and to unit indexes
    int from_unit_index = get_unit_index(length_units, sizeof(length_units) / sizeof(struct unit), argv[2]);
    int to_unit_index = get_unit_index(length_units, sizeof(length_units) / sizeof(struct unit), argv[3]);

    // Check if the from and to units are valid
    if (from_unit_index == -1 || to_unit_index == -1) {
        fprintf(stderr, "Error: Invalid unit name\n");
        return EXIT_FAILURE;
    }

    // Convert the value
    double converted_value = convert_units(value, &length_units[from_unit_index], &length_units[to_unit_index]);

    // Print the converted value
    printf("%f %s = %f %s\n", value, length_units[from_unit_index].name, converted_value, length_units[to_unit_index].name);

    return EXIT_SUCCESS;
}