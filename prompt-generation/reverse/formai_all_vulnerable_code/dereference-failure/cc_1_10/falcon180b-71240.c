//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

// Function to get user input
char* getUserInput(char* prompt) {
    char input[100];
    printf("%s", prompt);
    fgets(input, sizeof(input), stdin);
    return strdup(input);
}

int main() {
    char* input;
    double celsius, fahrenheit;

    // Get user input for temperature and unit
    printf("Enter temperature: ");
    input = getUserInput("");
    celsius = atof(input);
    printf("Enter unit (C or F): ");
    input = getUserInput("");
    char unit = input[0];

    // Convert Celsius to Fahrenheit
    if (unit == 'F' || unit == 'f') {
        fahrenheit = celsiusToFahrenheit(celsius);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    }
    // Convert Fahrenheit to Celsius
    else if (unit == 'C' || unit == 'c') {
        fahrenheit = fahrenheitToCelsius(celsius);
        printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", fahrenheit, celsius);
    }
    // Invalid unit
    else {
        printf("Invalid unit, please enter C or F.\n");
    }

    free(input);
    return 0;
}