//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char unit[10];
    float conversion_factor;
} ConversionFactor;

ConversionFactor length_conversions[] = {
    {"Meters", 1.0},
    {"Kilometers", 1000.0},
    {"Centimeters", 0.01},
    {"Miles", 1609.34},
    {"Feet", 0.3048}
};

ConversionFactor weight_conversions[] = {
    {"Grams", 1.0},
    {"Kilograms", 1000.0},
    {"Ounces", 0.035274},
    {"Stones", 14.0}
};

void print_usage() {
    printf("Usage: unit_converter <source_unit> <target_unit> <value>\n");
    printf("Supported length units: Meters, Kilometers, Centimeters, Miles, Feet\n");
    printf("Supported weight units: Grams, Kilograms, Ounces, Stones\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
    }

    ConversionFactor *source_unit, *target_unit;
    float value;

    for (int i = 0; i < 5; i++) {
        if (strcmp(length_conversions[i].unit, argv[1]) == 0) {
            source_unit = &length_conversions[i];
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (strcmp(length_conversions[i].unit, argv[2]) == 0) {
            target_unit = &length_conversions[i];
            break;
        }
    }

    if (source_unit == NULL || target_unit == NULL) {
        print_usage();
    }

    value = atof(argv[3]);

    if (strcmp(source_unit->unit, target_unit->unit) == 0) {
        printf("%.2f %s is equal to %.2f %s\n", value, source_unit->unit, value, source_unit->unit);
    } else {
        float result = value * source_unit->conversion_factor * target_unit->conversion_factor;
        printf("%.2f %s is equal to %.2f %s\n", value, source_unit->unit, result, target_unit->unit);
    }

    return EXIT_SUCCESS;
}