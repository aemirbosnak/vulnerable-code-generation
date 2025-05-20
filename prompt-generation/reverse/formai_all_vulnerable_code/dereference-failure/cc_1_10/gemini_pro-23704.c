//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure to hold the unit conversion data
typedef struct {
    char *name;
    double factor;
} unit_conversion;

// Create an array of unit conversions
unit_conversion conversions[] = {
    {"inches", 2.54},
    {"feet", 30.48},
    {"yards", 91.44},
    {"miles", 1609.34},
    {"centimeters", 1},
    {"meters", 100},
    {"kilometers", 100000},
    {"pounds", 0.453592},
    {"ounces", 28.3495},
    {"grams", 1},
    {"kilograms", 1000},
    {"fahrenheit", (5.0 / 9.0)},
    {"celsius", (9.0 / 5.0)},
    {"kelvin", 1},
};

// Get the number of unit conversions
int num_conversions = sizeof(conversions) / sizeof(conversions[0]);

// Print the unit conversions
void print_conversions() {
    for (int i = 0; i < num_conversions; i++) {
        printf("%s: %f\n", conversions[i].name, conversions[i].factor);
    }
}

// Convert a value from one unit to another
double convert(double value, char *from, char *to) {
    // Find the conversion factors for the from and to units
    double from_factor = 1;
    double to_factor = 1;
    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(conversions[i].name, from) == 0) {
            from_factor = conversions[i].factor;
        }
        if (strcmp(conversions[i].name, to) == 0) {
            to_factor = conversions[i].factor;
        }
    }

    // Convert the value
    return value * from_factor / to_factor;
}

// Get the user input
void get_user_input(double *value, char **from, char **to) {
    printf("Enter the value to convert: ");
    scanf("%lf", value);

    printf("Enter the unit to convert from: ");
    *from = malloc(256);
    scanf("%s", *from);

    printf("Enter the unit to convert to: ");
    *to = malloc(256);
    scanf("%s", *to);
}

// Print the conversion result
void print_result(double value, char *from, char *to) {
    printf("%f %s is equal to %f %s\n", value, from, convert(value, from, to), to);
}

// Main function
int main() {
    // Print the unit conversions
    print_conversions();

    // Get the user input
    double value;
    char *from;
    char *to;
    get_user_input(&value, &from, &to);

    // Convert the value
    double result = convert(value, from, to);

    // Print the conversion result
    print_result(value, from, to);

    // Free the allocated memory
    free(from);
    free(to);

    return 0;
}