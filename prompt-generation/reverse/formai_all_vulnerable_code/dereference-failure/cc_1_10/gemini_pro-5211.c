//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the supported units and their conversion factors
typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[] = {
    {"mm", 1.0},
    {"cm", 10.0},
    {"m", 1000.0},
    {"km", 1000000.0},
    {"in", 25.4},
    {"ft", 304.8},
    {"yd", 914.4},
    {"mi", 1609344.0},
    {"g", 1.0},
    {"kg", 1000.0},
    {"lb", 453.592},
    {"oz", 28.3495},
    {"ml", 1.0},
    {"l", 1000.0},
    {"pt", 473.176},
    {"gal", 3785.41},
};

// Get the index of a unit by its name
int get_unit_index(char *name) {
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Convert a value from one unit to another
double convert(double value, char *from, char *to) {
    int from_index = get_unit_index(from);
    int to_index = get_unit_index(to);
    if (from_index == -1 || to_index == -1) {
        return -1.0; // Invalid unit
    }
    return value * units[to_index].factor / units[from_index].factor;
}

// Print the usage information
void print_usage() {
    printf("Usage: unit_converter <value> <from_unit> <to_unit>\n");
    printf("Example: unit_converter 10.0 cm m\n");
    printf("Supported units:\n");
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        printf("  %s\n", units[i].name);
    }
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        print_usage();
        return 1;
    }

    // Parse the arguments
    double value = atof(argv[1]);
    char *from = argv[2];
    char *to = argv[3];

    // Convert the value
    double result = convert(value, from, to);

    // Check for errors
    if (result == -1.0) {
        printf("Invalid unit(s).\n");
        return 1;
    }

    // Print the result
    printf("%.2f %s is equal to %.2f %s\n", value, from, result, to);

    return 0;
}