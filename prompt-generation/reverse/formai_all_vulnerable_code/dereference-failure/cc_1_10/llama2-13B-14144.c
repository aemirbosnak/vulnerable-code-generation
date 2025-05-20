//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Define the units and their conversions
struct unit {
    char name[20];
    double factor;
};

struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
};

// Array to store the units and conversions
struct unit units[MAX_UNITS] = {
    {"inch", 2.54},
    {"foot", 12 * 2.54},
    {"yard", 3 * 2.54},
    {"mile", 1760 * 2.54},
    {"centimeter", 0.01 * 2.54}
};

struct conversion conversions[MAX_CONVERTIONS] = {
    {"inch", "foot", 12},
    {"foot", "yard", 3},
    {"yard", "mile", 1760},
    {"mile", "centimeter", 1760000}
};

// Function to convert between units
double convert(struct unit *from, struct unit *to, double value) {
    return value * from->factor / to->factor;
}

// Function to print the conversions
void print_conversions(struct conversion *conversions, int num_conversions) {
    for (int i = 0; i < num_conversions; i++) {
        printf("%s (%s) = %g %s\n", conversions[i].from_unit, conversions[i].to_unit, conversions[i].factor, conversions[i].from_unit);
    }
}

int main() {
    int choice;
    double value;

    // Print the list of units and conversions
    print_conversions(units, sizeof(units) / sizeof(units[0]));
    print_conversions(conversions, sizeof(conversions) / sizeof(conversions[0]));

    do {
        printf("Enter a unit (1-5): ");
        scanf("%d", &choice);

        // Check if the user entered a valid unit
        if (choice < 1 || choice > 5) {
            printf("Invalid unit. Try again.\n");
            continue;
        }

        // Get the value to convert
        printf("Enter a value: ");
        scanf("%lf", &value);

        // Convert the value to the chosen unit
        double converted_value = convert(units + choice - 1, units + choice - 1, value);

        // Print the converted value
        printf("Value in unit %s: %g\n", units[choice - 1].name, converted_value);
    } while (1);

    return 0;
}