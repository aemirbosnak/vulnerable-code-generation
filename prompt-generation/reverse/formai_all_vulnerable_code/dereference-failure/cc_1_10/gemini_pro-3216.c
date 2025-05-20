//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

typedef struct {
    float value;
    char *unit;
} Measurement;

typedef struct {
    char *name;
    float factor;
} ConversionFactor;

ConversionFactor conversionFactors[] = {
    {"kilometer", 1000.0},
    {"meter", 1.0},
    {"centimeter", 0.01},
    {"mile", 1609.34},
    {"yard", 0.9144},
    {"foot", 0.3048},
    {"inch", 0.0254}
};

int getFactorIndex(char *unit) {
    for (int i = 0; i < sizeof(conversionFactors) / sizeof(ConversionFactor); i++) {
        if (strcmp(unit, conversionFactors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

float convert(Measurement from, Measurement to) {
    int fromFactorIndex = getFactorIndex(from.unit);
    int toFactorIndex = getFactorIndex(to.unit);
    if (fromFactorIndex == -1 || toFactorIndex == -1) {
        return -1.0;
    }
    return from.value * conversionFactors[fromFactorIndex].factor / conversionFactors[toFactorIndex].factor;
}

int main() {
    printf("Welcome to the Jolly Converter!\n");

    Measurement from, to;

    printf("Enter the value and unit of the measurement you want to convert:");
    scanf("%f %s", &from.value, from.unit);

    printf("Enter the unit you want to convert to:");
    scanf("%s", to.unit);

    float convertedValue = convert(from, to);
    if (convertedValue == -1.0) {
        printf("Invalid unit conversion!\n");
    } else {
        printf("%.2f %s is equal to %.2f %s!\n", from.value, from.unit, convertedValue, to.unit);
    }

    return 0;
}