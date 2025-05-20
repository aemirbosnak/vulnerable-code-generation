//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Elementary, my dear Watson!
void convert(char *from, char *to, double value) {
    // Measure for measure, my good fellow!
    double result;

    // A trifle of conversion...
    if (strcmp(from, "Celsius") == 0 && strcmp(to, "Fahrenheit") == 0) {
        result = (value * 9 / 5) + 32;
    } else if (strcmp(from, "Fahrenheit") == 0 && strcmp(to, "Celsius") == 0) {
        result = (value - 32) * 5 / 9;
    } else if (strcmp(from, "Meters") == 0 && strcmp(to, "Feet") == 0) {
        result = value * 3.28084;
    } else if (strcmp(from, "Feet") == 0 && strcmp(to, "Meters") == 0) {
        result = value * 0.3048;
    } else if (strcmp(from, "Kilograms") == 0 && strcmp(to, "Pounds") == 0) {
        result = value * 2.20462;
    } else if (strcmp(from, "Pounds") == 0 && strcmp(to, "Kilograms") == 0) {
        result = value * 0.453592;
    } else {
        printf("Elementary, my dear Watson! I cannot convert from %s to %s.\n", from, to);
        return;
    }

    // A moment of clarity...
    printf("The result of converting %f %s to %s is: %f\n", value, from, to, result);
}

int main(int argc, char **argv) {
    // The game is afoot!
    if (argc != 4) {
        printf("Elementary, my dear Watson! You must provide the value, the from unit, and the to unit.\n");
        return 1;
    }

    // The needle in the haystack...
    double value = atof(argv[1]);
    char *from = argv[2];
    char *to = argv[3];

    // Let us be logical...
    convert(from, to, value);

    // The case is closed...
    return 0;
}