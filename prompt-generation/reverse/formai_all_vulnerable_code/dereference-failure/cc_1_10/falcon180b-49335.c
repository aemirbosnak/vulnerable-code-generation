//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_CONVERSIONS 10

typedef struct {
    char *name;
    double (*convert)(double);
} Conversion;

double length_to_meters(double value) {
    return value * 100;
}

double weight_to_kilograms(double value) {
    return value * 0.453592;
}

double volume_to_liters(double value) {
    return value * 0.264172;
}

Conversion conversions[] = {
    {"meters", length_to_meters},
    {"centimeters", length_to_meters},
    {"millimeters", length_to_meters},
    {"kilograms", weight_to_kilograms},
    {"grams", weight_to_kilograms},
    {"liters", volume_to_liters},
    {"cubic centimeters", volume_to_liters},
    {"cubic meters", volume_to_liters},
    {"gallons", volume_to_liters},
    {"quarts", volume_to_liters}
};

int main() {
    char input[MAX_LENGTH];
    char *token;
    Conversion *conversion;
    double value, result;
    int num_conversions;

    printf("Welcome to the Unit Converter, by Sherlock Holmes.\n");
    printf("Enter a value and its unit, separated by a space:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Parse input
    token = strtok(input, " ");
    value = strtod(token, NULL);
    conversion = NULL;
    num_conversions = 0;

    while (conversions[num_conversions].name!= NULL) {
        if (strcmp(conversions[num_conversions].name, token) == 0) {
            conversion = &conversions[num_conversions];
            break;
        }
        num_conversions++;
    }

    if (conversion == NULL) {
        printf("Invalid unit: %s\n", token);
        return 1;
    }

    // Convert value
    result = conversion->convert(value);

    // Print result
    printf("%.2f %s = %.2f %s\n", value, token, result, conversions[num_conversions].name);

    return 0;
}