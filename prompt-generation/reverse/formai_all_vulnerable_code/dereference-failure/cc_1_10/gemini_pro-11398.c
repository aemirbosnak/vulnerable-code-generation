//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>

// Declare a cheerful greeting message
const char *greeting = "Hello there, welcome to the amazing unit converter!\n";

// Define the supported conversions and their conversion factors
typedef struct {
    char *name;
    double factor;
} conversion_t;

conversion_t conversions[] = {
    {"miles to kilometers", 1.60934},
    {"kilometers to miles", 0.621371},
    {"pounds to kilograms", 0.453592},
    {"kilograms to pounds", 2.20462},
    {"gallons to liters", 3.78541},
    {"liters to gallons", 0.264172},
    {"inches to centimeters", 2.54},
    {"centimeters to inches", 0.393701},
    {"fahrenheit to celsius", (5.0 / 9.0)},
    {"celsius to fahrenheit", (9.0 / 5.0)},
};

// Define the number of supported conversions
const int num_conversions = sizeof(conversions) / sizeof(conversion_t);

// Print the cheerful greeting message
void print_greeting() {
    printf("%s", greeting);
}

// Print the list of supported conversions
void print_conversions() {
    printf("Supported conversions:\n");
    for (int i = 0; i < num_conversions; i++) {
        printf("  %s\n", conversions[i].name);
    }
}

// Convert a value from one unit to another
double convert(double value, conversion_t conversion) {
    return value * conversion.factor;
}

// Get the user's input for the conversion
void get_input(double *value, char **unit, char **to_unit) {
    printf("Enter a value to convert: ");
    scanf("%lf", value);
    printf("Enter the unit of the value: ");
    scanf("%s", *unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", *to_unit);
}

// Find the conversion factor for the given units
conversion_t find_conversion(char *unit, char *to_unit) {
    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(unit, conversions[i].name) == 0 && strcmp(to_unit, conversions[i].name) == 0) {
            return conversions[i];
        }
    }
    
    // If no conversion is found, return an error
    fprintf(stderr, "Error: Invalid conversion specified.\n");
    exit(1);
}

// Print the result of the conversion
void print_result(double value, char *unit, char *to_unit, double result) {
    printf("%lf %s is equal to %lf %s\n", value, unit, result, to_unit);
}

// The main function
int main() {
    // Print the cheerful greeting message
    print_greeting();
    
    // Print the list of supported conversions
    print_conversions();
    
    // Get the user's input
    double value;
    char *unit, *to_unit;
    get_input(&value, &unit, &to_unit);
    
    // Find the conversion factor for the given units
    conversion_t conversion = find_conversion(unit, to_unit);
    
    // Convert the value
    double result = convert(value, conversion);
    
    // Print the result of the conversion
    print_result(value, unit, to_unit, result);
    
    return 0;
}