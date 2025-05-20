//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for units
typedef struct {
    char name[32];
    float conversion_factor;
} Unit;

// Define an array of common units
Unit units[] = {
    {"Meter", 1.0},
    {"Foot", 0.3048},
    {"Kilogram", 1.0},
    {"Pound", 0.453592},
    {"Liter", 1.0},
    {"Gallon", 3.78541},
    {"Celsius", 1.0},
    {"Fahrenheit", 1.8},
    {"Hertz", 1.0},
    {"Kilometer per hour", 3.6},
};

// Function to find unit index by name
int find_unit_index(char* name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to convert value between units
float convert_value(Unit from_unit, Unit to_unit, float value) {
    return value * (to_unit.conversion_factor / from_unit.conversion_factor);
}

// Function to print usage and exit
void print_usage() {
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 4) {
        print_usage();
    }

    // Parse command line arguments
    float value = atof(argv[1]);
    int from_unit_index = find_unit_index(argv[2]);
    int to_unit_index = find_unit_index(argv[3]);

    // Check for valid units
    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid unit name(s)\n");
        print_usage();
    }

    // Convert value between units
    Unit from_unit = units[from_unit_index];
    Unit to_unit = units[to_unit_index];
    float result = convert_value(from_unit, to_unit, value);

    // Print result
    printf("Result: %.6f %s\n", result, to_unit.name);

    return 0;
}