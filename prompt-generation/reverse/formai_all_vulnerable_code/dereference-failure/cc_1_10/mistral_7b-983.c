//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char* name;
    double conversionFactor;
} Unit;

const Unit units[] = {
    {"Miles", 0.000621371},
    {"Kilometers", 1.60934},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Fahrenheit", 1.8},
    {"Celsius", 1.0},
    {"Gallons", 3.78541},
    {"Liters", 0.264172},
    {"Inches", 0.0254},
    {"Centimeters", 0.01}
};

void printUsage() {
    printf("\nUsage: %s <value> <fromUnit> <toUnit>\n", __FILE__);
    printf("Example: %s 2.5 Miles Kilometers\n", __FILE__);
    printf("Available units: ");
    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        printf(" %s", units[i].name);
    }
    printf("\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printUsage();
    }

    double value;
    Unit fromUnit, toUnit;

    if (sscanf(argv[1], "%lf", &value) != 1) {
        printUsage();
    }

    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(argv[2], units[i].name) == 0) {
            fromUnit = units[i];
            break;
        }
    }

    for (int i = 0; i < sizeof(units) / sizeof(Unit); i++) {
        if (strcmp(argv[3], units[i].name) == 0) {
            toUnit = units[i];
            break;
        }
    }

    if (fromUnit.name == NULL || toUnit.name == NULL) {
        printUsage();
    }

    double result = value * toUnit.conversionFactor / fromUnit.conversionFactor;

    printf("%s %s is equal to %s %s: %f\n", argv[1], fromUnit.name, argv[3], toUnit.name, result);

    return 0;
}