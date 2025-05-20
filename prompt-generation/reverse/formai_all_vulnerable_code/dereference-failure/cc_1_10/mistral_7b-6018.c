//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char unit[20];
    double conversionFactor;
} UnitConverter;

UnitConverter units[10] = {
    {"Feet to Meters", 0.3048},
    {"Meters to Feet", 3.28084},
    {"Kilograms to Pounds", 2.20462},
    {"Pounds to Kilograms", 0.453592},
    {"Celsius to Fahrenheit", 1.8 * 33.3},
    {"Fahrenheit to Celsius", 33.3 / 1.8},
    {"Miles to Kilometers", 1.60934},
    {"Kilometers to Miles", 0.621371},
    {"Gallons to Liters", 3.78541},
    {"Liters to Gallons", 0.264172}
};

void printUsage() {
    printf("Usage: unitConverter <sourceUnit> <targetUnit> <value>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (strcmp(argv[1], units[i].unit) == 0) {
            double sourceValue = atof(argv[3]);
            double targetValue = sourceValue * units[i].conversionFactor;

            for (int j = 0; j < 10; j++) {
                if (strcmp(argv[2], units[j].unit) == 0) {
                    printf("%lf %s is equal to %lf %s.\n", sourceValue, argv[1], targetValue / units[j].conversionFactor, argv[2]);
                    return 0;
                }
            }

            printUsage();
            return 1;
        }
    }

    printUsage();
    return 1;
}