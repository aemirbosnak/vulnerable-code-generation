//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char unit[3];
    float conversionFactor;
} UnitConversion;

UnitConversion KelvinToFahrenheit = {"F", 1.8};
UnitConversion KelvinToCelsius = {"C", 1.0};
UnitConversion FahrenheitToKelvin = {"K", 273.15};
UnitConversion FahrenheitToCelsius = {"C", 5.0/9.0};

void printUsage() {
    printf("Usage: temperatureConverter <temperature> <fromUnit> <toUnit>\n");
    printf("Example: temperatureConverter 30 C\n");
    printf("Example: temperatureConverter 68 F\n");
    printf("Example: temperatureConverter 293.15 K\n");
    exit(EXIT_FAILURE);
}

float temperatureConverter(float temperature, UnitConversion *fromUnit, UnitConversion *toUnit) {
    float result;
    result = temperature * fromUnit->conversionFactor;
    temperature = result;
    result = result * toUnit->conversionFactor;
    return result;
}

int main(int argc, char **argv) {
    float temperature, result;
    UnitConversion *fromUnit, *toUnit;

    if (argc != 4) printUsage();

    if (strcmp(argv[2], "F") == 0) {
        fromUnit = &FahrenheitToKelvin;
    } else if (strcmp(argv[2], "C") == 0) {
        if (strcmp(argv[3], "F") == 0) {
            fromUnit = &KelvinToFahrenheit;
            toUnit = &FahrenheitToCelsius;
        } else {
            fromUnit = &KelvinToCelsius;
            toUnit = &KelvinToFahrenheit;
        }
    } else if (strcmp(argv[2], "K") == 0) {
        if (strcmp(argv[3], "F") == 0) {
            fromUnit = &FahrenheitToKelvin;
            toUnit = &FahrenheitToCelsius;
        } else {
            fromUnit = &KelvinToCelsius;
            toUnit = &KelvinToFahrenheit;
        }
    } else {
        printUsage();
    }

    temperature = atof(argv[1]);
    result = temperatureConverter(temperature, fromUnit, toUnit);
    printf("%.2f %s is equal to %.2f %s.\n", temperature, argv[2], result, argv[3]);

    free(fromUnit);
    free(toUnit);

    return EXIT_SUCCESS;
}