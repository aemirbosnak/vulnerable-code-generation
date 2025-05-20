//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

// Define the units of measurement
struct unit {
    const char *name;
    double factor;
};

// Define the conversions
struct conversion {
    const char *from_unit;
    const char *to_unit;
    double factor;
};

// Initialize the units and conversions
struct unit units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"foot", 0.3048},
    {"inch", 0.0254},
    {"yard", 0.9144}
};

struct conversion conversions[MAX_CONVERSIONS] = {
    {"meter", "foot", 3.2808},
    {"kilometer", "mile", 0.621371},
    {"foot", "inch", 12},
    {"inch", "yard", 0.083333}
};

// Function to convert between units
double convert(const char *from_unit, const char *to_unit, double value) {
    int i = 0;
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return 0;
    }
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        if (strcmp(to_unit, conversions[i].from_unit) == 0) {
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Invalid unit: %s\n", to_unit);
        return 0;
    }
    return value * conversions[i].factor;
}

int main() {
    double value = 10;
    printf("10 meters is equal to %f feet\n", convert("meter", "foot", value));
    printf("10 kilometers is equal to %f miles\n", convert("kilometer", "mile", value));
    printf("10 inches is equal to %f yards\n", convert("inch", "yard", value));
    return 0;
}