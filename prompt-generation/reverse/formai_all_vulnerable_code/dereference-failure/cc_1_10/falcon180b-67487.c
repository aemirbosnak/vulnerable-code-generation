//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

int is_digit(char c);
double convert_temperature(double temperature, char from, char to);

int main() {
    char input[MAX_LENGTH];
    char from[3], to[3];
    double temperature;

    printf("Enter the temperature to convert: ");
    fgets(input, MAX_LENGTH, stdin);

    // Check if input is valid
    if (strlen(input) == 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Extract temperature value from input
    temperature = strtod(input, NULL);

    // Get temperature units from input
    strcpy(from, input + strlen(input) - 2);
    strcpy(to, input + strlen(input) - 1);

    // Convert temperature
    temperature = convert_temperature(temperature, from[0], to[0]);

    // Print result
    printf("%.2f %c = %.2f %c\n", temperature, from[0], temperature, to[0]);

    return 0;
}

int is_digit(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}

double convert_temperature(double temperature, char from, char to) {
    switch (from) {
        case 'C':
            switch (to) {
                case 'F':
                    return (temperature * 9/5) + 32;
                case 'K':
                    return temperature + 273.15;
                default:
                    printf("Invalid temperature units.\n");
                    return 0;
            }
        case 'F':
            switch (to) {
                case 'C':
                    return (temperature - 32) * 5/9;
                case 'K':
                    return (temperature + 459.67) * 5/9;
                default:
                    printf("Invalid temperature units.\n");
                    return 0;
            }
        case 'K':
            switch (to) {
                case 'C':
                    return temperature - 273.15;
                case 'F':
                    return (temperature * 9/5) - 459.67;
                default:
                    printf("Invalid temperature units.\n");
                    return 0;
            }
        default:
            printf("Invalid temperature units.\n");
            return 0;
    }
}