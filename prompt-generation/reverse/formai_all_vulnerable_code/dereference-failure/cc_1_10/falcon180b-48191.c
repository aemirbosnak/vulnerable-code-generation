//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 80

// Function prototypes
void process_input(char *input);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

int main() {
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        process_input(input);
    }
    return 0;
}

void process_input(char *input) {
    char *token;
    double temperature;
    char unit[3];

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Extract temperature and unit
    token = strtok(input, " ");
    strcpy(unit, token);
    temperature = strtod(token, NULL);

    // Convert temperature
    if (strcmp(unit, "C") == 0 || strcmp(unit, "c") == 0) {
        printf("%.2f°C is %.2f°F\n", temperature, celsius_to_fahrenheit(temperature));
    } else if (strcmp(unit, "F") == 0 || strcmp(unit, "f") == 0) {
        printf("%.2f°F is %.2f°C\n", temperature, fahrenheit_to_celsius(temperature));
    } else {
        printf("Invalid unit\n");
    }
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}