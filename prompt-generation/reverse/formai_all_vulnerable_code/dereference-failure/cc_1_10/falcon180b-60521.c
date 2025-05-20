//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    double (*convert)(double);
} temperature_unit;

double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double celsius_to_kelvin(double c) {
    return c + 273.15;
}

double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double fahrenheit_to_kelvin(double f) {
    return celsius_to_kelvin(fahrenheit_to_celsius(f));
}

double kelvin_to_celsius(double k) {
    return k - 273.15;
}

double kelvin_to_fahrenheit(double k) {
    return celsius_to_fahrenheit(kelvin_to_celsius(k));
}

int main() {
    temperature_unit units[] = {{"Celsius", celsius_to_fahrenheit},
                                {"Fahrenheit", fahrenheit_to_celsius},
                                {"Kelvin", kelvin_to_celsius}};

    int num_units = sizeof(units) / sizeof(temperature_unit);
    char input_buffer[MAX_LINE_SIZE];
    char *token;
    double value;
    temperature_unit *selected_unit;

    printf("Enter a temperature value followed by its unit (e.g. 25C):\n");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);

    token = strtok(input_buffer, " ");
    value = strtod(token, NULL);

    selected_unit = NULL;
    for (int i = 0; i < num_units; ++i) {
        if (!strcmp(units[i].name, token)) {
            selected_unit = &units[i];
            break;
        }
    }

    if (selected_unit == NULL) {
        printf("Invalid unit.\n");
        return 1;
    }

    double result = selected_unit->convert(value);
    printf("%.2f%s = %.2f%s\n", value, token, result, selected_unit->name);

    return 0;
}