//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    CELSIUS,
    FAHRENHEIT,
} TemperatureUnit;

double convert_temperature(double value, TemperatureUnit from_unit, TemperatureUnit to_unit) {
    // Conversion from Celsius to Fahrenheit
    if (from_unit == CELSIUS && to_unit == FAHRENHEIT) {
        return (value * 9.0 / 5.0) + 32.0;
    }

    // Conversion from Fahrenheit to Celsius
    else if (from_unit == FAHRENHEIT && to_unit == CELSIUS) {
        return (value - 32.0) * 5.0 / 9.0;
    }

    // No conversion needed
    else {
        return value;
    }
}

void print_conversion_table() {
    double temperature;

    printf("Celsius\tFahrenheit\n");
    for (temperature = -20.0; temperature <= 100.0; temperature += 5.0) {
        printf("%6.1f\t%8.1f\n", temperature, convert_temperature(temperature, CELSIUS, FAHRENHEIT));
    }

    printf("\nFahrenheit\tCelsius\n");
    for (temperature = -4.0; temperature <= 212.0; temperature += 5.0) {
        printf("%8.1f\t%6.1f\n", temperature, convert_temperature(temperature, FAHRENHEIT, CELSIUS));
    }
}

int main() {
    double value, converted_value;
    TemperatureUnit from_unit, to_unit;
    char input[10];

    // Display the conversion table
    print_conversion_table();

    // Get the user's input
    printf("\nEnter a temperature value: ");
    scanf("%lf", &value);

    printf("Enter the unit of the input value (Celsius or Fahrenheit): ");
    scanf("%s", input);

    if (strcmp(input, "Celsius") == 0) {
        from_unit = CELSIUS;
    } else if (strcmp(input, "Fahrenheit") == 0) {
        from_unit = FAHRENHEIT;
    } else {
        printf("Invalid unit entered. Please enter Celsius or Fahrenheit.\n");
        return EXIT_FAILURE;
    }

    // Get the desired unit of conversion
    printf("Enter the desired unit of conversion (Celsius or Fahrenheit): ");
    scanf("%s", input);

    if (strcmp(input, "Celsius") == 0) {
        to_unit = CELSIUS;
    } else if (strcmp(input, "Fahrenheit") == 0) {
        to_unit = FAHRENHEIT;
    } else {
        printf("Invalid unit entered. Please enter Celsius or Fahrenheit.\n");
        return EXIT_FAILURE;
    }

    // Convert the temperature value
    converted_value = convert_temperature(value, from_unit, to_unit);

    // Print the converted value
    printf("%lf %s is equal to %lf %s\n", value, from_unit == CELSIUS ? "Celsius" : "Fahrenheit", converted_value, to_unit == CELSIUS ? "Celsius" : "Fahrenheit");

    return EXIT_SUCCESS;
}