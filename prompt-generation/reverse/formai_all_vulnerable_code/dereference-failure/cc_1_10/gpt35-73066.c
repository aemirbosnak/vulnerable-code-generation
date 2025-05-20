//FormAI DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printError(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

float getFloatInput() {
    char input[1024];
    char *endptr;
    float value;

    fgets(input, sizeof(input), stdin);

    if (!isdigit(input[0]) && (input[0] != '-') && (input[0] != '.')) {
        printError("Invalid input: not a number");
    }

    value = strtof(input, &endptr);

    if (*endptr != '\n' && *endptr) {
        printError("Invalid input: not a number");
    }

    return value;
}

float celsiusToFahrenheit(float tempCelsius) {
    return (tempCelsius * 9 / 5) + 32;
}

float fahrenheitToCelsius(float tempFahrenheit) {
    return (tempFahrenheit - 32) * 5 / 9;
}

int main(int argc, char **argv) {
    float temperature;
    char *mode;

    if (argc < 2) {
        printError("Usage: tempconv <mode>");
    }

    mode = argv[1];

    printf("Enter temperature: ");

    temperature = getFloatInput();

    if (strcmp(mode, "c2f") == 0) {
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
    } else if (strcmp(mode, "f2c") == 0) {
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
    } else {
        printError("Invalid mode");
    }

    return 0;
}