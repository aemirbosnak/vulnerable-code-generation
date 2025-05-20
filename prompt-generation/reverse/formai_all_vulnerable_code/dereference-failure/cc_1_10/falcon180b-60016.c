//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define PI 3.14159265359
#define MAX_LINE_LENGTH 1000

typedef struct {
    double celsius;
    double fahrenheit;
    double kelvin;
} Temperature;

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <celsius|fahrenheit|kelvin> <value> <output>\n", argv[0]);
        return 1;
    }

    char *unit = argv[1];
    double value = atof(argv[2]);
    char *output = argv[3];

    if (value < -1000 || value > 1000) {
        printf("Invalid value. Please enter a number between -1000 and 1000.\n");
        return 1;
    }

    Temperature temp;
    if (strcmp(unit, "celsius") == 0) {
        temp.celsius = value;
        temp.fahrenheit = (value * 9 / 5) + 32;
        temp.kelvin = value + 273.15;
    } else if (strcmp(unit, "fahrenheit") == 0) {
        temp.fahrenheit = value;
        temp.celsius = (value - 32) * 5 / 9;
        temp.kelvin = (value + 459.67) * 5 / 9;
    } else if (strcmp(unit, "kelvin") == 0) {
        temp.kelvin = value;
        temp.celsius = value - 273.15;
        temp.fahrenheit = (value * 9 / 5) - 459.67;
    } else {
        printf("Invalid unit. Please enter celsius, fahrenheit, or kelvin.\n");
        return 1;
    }

    printf("%.2f %s = %.2f %s = %.2f K\n", value, unit, temp.celsius, "C", temp.kelvin);

    FILE *fp = fopen(output, "w");
    if (fp == NULL) {
        printf("Error opening file '%s'.\n", output);
        return 1;
    }

    fprintf(fp, "%.2f %s = %.2f %s = %.2f K\n", value, unit, temp.celsius, "C", temp.kelvin);
    fclose(fp);

    return 0;
}