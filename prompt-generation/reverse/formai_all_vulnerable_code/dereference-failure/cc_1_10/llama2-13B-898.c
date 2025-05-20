//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNIT_CONVERTER_MAX_LENGTH 50

// Define the supported unit types
enum unit_types {
    UNIT_NONE,
    UNIT_LENGTH,
    UNIT_MASS,
    UNIT_TIME,
    UNIT_TEMPERATURE,
};

// Define the conversion table
struct unit_conversion {
    char *name;
    double factor;
};

static struct unit_conversion conversion_table[] = {
    {"ft", 0.3048}, {"in", 0.0254}, {"yd", 0.9144},
    {"lb", 0.453592}, {"oz", 0.0283495}, {"kg", 0.001},
    {"s", 1}, {"min", 60}, {"hr", 3600},
    {"F", 5/9}, {"C", 100/9}
};

// Define the current unit
int current_unit = UNIT_NONE;

// Define the input string
char input_string[UNIT_CONVERTER_MAX_LENGTH];

// Define the output string
char output_string[UNIT_CONVERTER_MAX_LENGTH];

int main() {
    // Initialize the program
    srand(time(NULL));

    // Print the title
    printf("Unit Converter\n");

    // Print the welcome message
    printf("Welcome to the Unit Converter! \n");

    // Print the available units
    printf("Supported units: length, mass, time, temperature\n");

    // Print the usage instructions
    printf("Enter a unit in the format '[length] [unit]' or '[mass] [unit]' or '[time] [unit]' or '[temperature] [unit]'\n");
    printf("Example: '5ft 3in' or '2.5kg' or '3min 45s' or '75F'\n");

    // Main loop
    while (1) {
        // Get the input string from the user
        printf("Enter a unit in the format '[length] [unit]' or '[mass] [unit]' or '[time] [unit]' or '[temperature] [unit]': ");
        fgets(input_string, UNIT_CONVERTER_MAX_LENGTH, stdin);

        // Check if the input string is valid
        if (input_string[0] == '\0' || strlen(input_string) > UNIT_CONVERTER_MAX_LENGTH) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Tokenize the input string
        char *token = strtok(input_string, " ");

        // Check if the first token is a unit
        if (token[0] == '\0') {
            printf("Invalid input. Please specify a unit.\n");
            continue;
        }

        // Get the current unit
        current_unit = strtol(token, NULL, 10);

        // Check if the current unit is valid
        if (current_unit < 0 || current_unit > UNIT_NONE) {
            printf("Invalid unit. Please specify a valid unit.\n");
            continue;
        }

        // Get the second token
        token = strtok(NULL, " ");

        // Check if the second token is a value
        if (token[0] == '\0') {
            printf("Invalid input. Please specify a value.\n");
            continue;
        }

        // Convert the value to the current unit
        double value = strtod(token, NULL);

        // Check if the value is valid
        if (value < 0 || value > 100) {
            printf("Invalid value. Please specify a valid value.\n");
            continue;
        }

        // Get the conversion factor for the current unit
        struct unit_conversion *conversion = &conversion_table[current_unit];

        // Calculate the converted value
        double converted_value = value * conversion->factor;

        // Print the converted value
        printf("%.2f %s\n", converted_value, conversion->name);
    }

    return 0;
}