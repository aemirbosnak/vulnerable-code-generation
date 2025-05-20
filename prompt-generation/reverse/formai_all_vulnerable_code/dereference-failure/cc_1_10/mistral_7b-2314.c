//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP (-50.0)
#define MAX_TEMP (150.0)

void temperature_conversion(double temp, char unit, double *result, char *resultUnit) {
    const double F_TO_C = 5.0 / 9.0;

    if (unit == 'F') {
        *result = temp * F_TO_C;
        *resultUnit = 'C';
    } else if (unit == 'C') {
        *result = (temp + 273.15) * 1.8;
        *resultUnit = 'F';
    } else {
        printf("Invalid temperature unit. Use F for Fahrenheit or C for Celsius.\n");
        *result = 0.0;
        return;
    }

    if (*result < MIN_TEMP) {
        printf("Error: Temperature is below minimum allowed value.\n");
        *result = 0.0;
        return;
    }

    if (*result > MAX_TEMP) {
        printf("Error: Temperature is above maximum allowed value.\n");
        *result = 0.0;
        return;
    }
}

int main(int argc, char *argv[]) {
    double temp, result;
    char unit, resultUnit;

    if (argc != 3) {
        printf("Usage: %s <temperature> <F|C>\n", argv[0]);
        return 1;
    }

    temp = atof(argv[1]);
    unit = argv[2][0];

    temperature_conversion(temp, unit, &result, &resultUnit);

    if (result == 0.0) {
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", result, resultUnit);

    return 0;
}