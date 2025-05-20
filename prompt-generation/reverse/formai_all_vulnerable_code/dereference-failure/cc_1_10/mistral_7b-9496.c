//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char unit[20];
    float conversion_factor;
} UnitConversionFactor;

UnitConversionFactor units[] = {
    {"miles", 0.0001892845},
    {"kilometers", 1.609344},
    {"pounds", 0.453592},
    {"kilograms", 2.20462},
    {"liters", 0.264172},
    {"gallons", 3.78541},
    {"square meters", 1.07639},
    {"square feet", 0.092903},
    {"celsius", 1.8},
    {"fahrenheit", 1.8}, //Same conversion factor for both Celsius and Fahrenheit as the conversion between them is a two-step process.
};

int main(int argc, char *argv[]) {
    float value, conversion_factor, result;
    int i, choice1, choice2;

    if (argc != 4) {
        printf("Usage : %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    value = atof(argv[1]);

    for (i = 0; i < 10; i++) {
        if (strcmp(argv[2], units[i].unit) == 0) {
            choice1 = i;
            break;
        }
    }

    for (i = 0; i < 10; i++) {
        if (strcmp(argv[3], units[i].unit) == 0) {
            choice2 = i;
            break;
        }
    }

    conversion_factor = units[choice1].conversion_factor * units[choice2].conversion_factor;

    result = value * conversion_factor;

    printf("%.2f %s is equal to %.2f %s\n", value, argv[2], result, argv[3]);

    return 0;
}