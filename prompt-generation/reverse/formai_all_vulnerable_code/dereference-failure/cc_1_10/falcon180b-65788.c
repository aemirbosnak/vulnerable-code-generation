//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEMP_CONVERSIONS 10

struct temp_conversion {
    char *input_unit;
    char *output_unit;
    double (*convert_func)(double);
};

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

double kelvin_to_celsius(double kelvin) {
    return kelvin - 273.15;
}

double celsius_to_kelvin(double celsius) {
    return celsius + 273.15;
}

struct temp_conversion temp_conversions[] = {
    {"C", "F", celsius_to_fahrenheit},
    {"F", "C", fahrenheit_to_celsius},
    {"C", "K", celsius_to_kelvin},
    {"K", "C", kelvin_to_celsius}
};

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *input_unit, *output_unit;
    double input_temp, output_temp;
    int num_conversions = 0;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert, followed by the input unit and the output unit.\n");
    printf("For example: 25 C F\n");

    while (num_conversions < MAX_TEMP_CONVERSIONS) {
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove newline character

        input_temp = strtod(input_buffer, NULL);
        input_unit = strtok(input_buffer, " ");
        output_unit = strtok(NULL, " ");

        for (int i = 0; i < sizeof(temp_conversions) / sizeof(struct temp_conversion); i++) {
            if (strcmp(input_unit, temp_conversions[i].input_unit) == 0 &&
                strcmp(output_unit, temp_conversions[i].output_unit) == 0) {
                output_temp = temp_conversions[i].convert_func(input_temp);
                printf("%.2f %s = %.2f %s\n", input_temp, input_unit, output_temp, output_unit);
                num_conversions++;
                break;
            }
        }
    }

    printf("Thank you for using the Temperature Converter!\n");
    return 0;
}