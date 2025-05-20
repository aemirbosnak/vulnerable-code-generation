//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *input = NULL;
    char *unit = NULL;
    char *output = NULL;
    double temperature;
    int result;
    char *units[] = {"Celsius", "Fahrenheit", "Kelvin"};

    // check if the user provided an input string
    if (argc < 2) {
        printf("Usage: %s <temperature> <unit>\n", argv[0]);
        return 1;
    }

    // get the input string and unit
    input = argv[1];
    unit = argv[2];

    // convert the input string to a temperature value
    temperature = strtod(input, NULL);

    // check if the unit is valid
    if (strcmp(unit, "Celsius") == 0) {
        // convert the temperature to Fahrenheit and Kelvin
        temperature = (temperature * 9.0 / 5.0) + 32.0;
        temperature = temperature + 273.15;
        result = 1;
    } else if (strcmp(unit, "Fahrenheit") == 0) {
        // convert the temperature to Celsius and Kelvin
        temperature = (temperature - 32.0) * 5.0 / 9.0;
        temperature = temperature + 273.15;
        result = 1;
    } else if (strcmp(unit, "Kelvin") == 0) {
        // convert the temperature to Celsius and Fahrenheit
        temperature = temperature - 273.15;
        temperature = temperature * 9.0 / 5.0 + 32.0;
        result = 1;
    } else {
        // the unit is not valid
        printf("Invalid unit: %s\n", unit);
        result = 0;
    }

    // print the result
    if (result == 1) {
        output = malloc(strlen(input) + 20);
        sprintf(output, "%.2f %s = %.2f %s", temperature, unit, temperature, units[0]);
        printf("%s\n", output);
        free(output);
    }

    return 0;
}