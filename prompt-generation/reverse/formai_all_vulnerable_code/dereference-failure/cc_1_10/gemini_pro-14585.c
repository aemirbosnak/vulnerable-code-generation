//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    LENGTH,
    MASS,
    TIME,
    TEMPERATURE
} UnitType;

typedef struct {
    UnitType type;
    double value;
} Unit;

typedef struct {
    UnitType fromType;
    UnitType toType;
    double conversionFactor;
} ConversionFactor;

ConversionFactor conversionFactors[] = {
    {LENGTH, LENGTH, 1.0},
    {LENGTH, MASS, 0.0},
    {LENGTH, TIME, 0.0},
    {LENGTH, TEMPERATURE, 0.0},
    {MASS, LENGTH, 0.0},
    {MASS, MASS, 1.0},
    {MASS, TIME, 0.0},
    {MASS, TEMPERATURE, 0.0},
    {TIME, LENGTH, 0.0},
    {TIME, MASS, 0.0},
    {TIME, TIME, 1.0},
    {TIME, TEMPERATURE, 0.0},
    {TEMPERATURE, LENGTH, 0.0},
    {TEMPERATURE, MASS, 0.0},
    {TEMPERATURE, TIME, 0.0},
    {TEMPERATURE, TEMPERATURE, 1.0}
};

double convertUnit(Unit fromUnit, Unit toUnit) {
    if (fromUnit.type == toUnit.type) {
        return fromUnit.value;
    }

    ConversionFactor *conversionFactor = NULL;
    for (int i = 0; i < sizeof(conversionFactors) / sizeof(ConversionFactor); i++) {
        if (conversionFactors[i].fromType == fromUnit.type && conversionFactors[i].toType == toUnit.type) {
            conversionFactor = &conversionFactors[i];
            break;
        }
    }

    if (conversionFactor == NULL) {
        fprintf(stderr, "Conversion factor not found for unit types %d and %d.\n", fromUnit.type, toUnit.type);
        exit(EXIT_FAILURE);
    }

    return fromUnit.value * conversionFactor->conversionFactor;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <from_value> <from_unit_type> <to_unit_type>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    double fromValue = atof(argv[1]);
    UnitType fromUnitType = atoi(argv[2]);
    UnitType toUnitType = atoi(argv[3]);

    Unit fromUnit = {fromUnitType, fromValue};
    Unit toUnit = {toUnitType, convertUnit(fromUnit, toUnit)};

    printf("%f %d -> %f %d\n", fromUnit.value, fromUnit.type, toUnit.value, toUnit.type);

    return EXIT_SUCCESS;
}