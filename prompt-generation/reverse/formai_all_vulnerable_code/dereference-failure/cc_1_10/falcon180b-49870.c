//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct {
    char *name;
    double (*convert)(double);
} Unit;

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double kelvin_to_fahrenheit(double kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

int main() {
    Unit units[] = {{"Celsius", celsius_to_fahrenheit}, {"Fahrenheit", fahrenheit_to_celsius}, {"Kelvin", kelvin_to_celsius}};
    int num_units = sizeof(units) / sizeof(units[0]);
    char input[MAX_LENGTH];
    double value;
    int choice;

    printf("Temperature Converter\n");
    printf("Enter a temperature followed by its unit (e.g. 25C for 25 degrees Celsius):\n");
    scanf("%[A-Za-z]", input);
    value = atof(input);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(input + strlen(input) - 1, units[i].name) == 0) {
            choice = i;
            break;
        }
    }

    double result = units[choice].convert(value);

    printf("%.2f%s = %.2f%s\n", value, input + strlen(input) - 1, result, units[choice].name);

    return 0;
}