//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define NUM_CONVERSION_PAIRS 13

typedef struct ConversionPair {
    char unit[10];
    double conversionFactor;
} ConversionPair;

ConversionPair conversionPairs[NUM_CONVERSION_PAIRS] = {
    {"cm", 0.01},
    {"m", 1.0},
    {"km", 1000.0},
    {"lbs", 0.45359237},
    {"kg", 2.20462},
    {"gal", 3.785411784},
    {"liters", 1.0},
    {"oz", 0.0352736},
    {"cups", 0.236588},
    {"pints", 0.47317647},
    {"miles", 1609.34},
    {"feet", 0.3048},
    {"inches", 0.0254}
};

void printUsage() {
    printf("\nUnitBuddy v1.0.0 - A friendly unit converter\n");
    printf("Usage: UnitBuddy <source-unit> <target-unit> <value>\n");
    printf("Example: UnitBuddy cm miles 5\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }

    int indexSource = -1;
    int indexTarget = -1;

    for (int i = 0; i < NUM_CONVERSION_PAIRS; i++) {
        if (strcmp(argv[1], conversionPairs[i].unit) == 0) {
            indexSource = i;
        }

        if (strcmp(argv[2], conversionPairs[i].unit) == 0) {
            indexTarget = i;
        }
    }

    if (indexSource == -1 || indexTarget == -1) {
        printUsage();
        return 1;
    }

    double value = atof(argv[3]);
    double result = 0;

    if (indexSource < indexTarget) {
        result = value * conversionPairs[indexSource].conversionFactor / conversionPairs[indexTarget].conversionFactor;
    } else {
        result = value * conversionPairs[indexTarget].conversionFactor / conversionPairs[indexSource].conversionFactor;
    }

    printf("%.12f %s is equal to %.12f %s\n", value, argv[1], result, argv[2]);

    return 0;
}