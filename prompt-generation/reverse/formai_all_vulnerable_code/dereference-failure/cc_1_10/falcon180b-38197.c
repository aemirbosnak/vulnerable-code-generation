//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 100

int main() {
    char input[MAX_LINE_SIZE];
    char *unit = NULL;
    double value, result;
    int base;

    printf("Enter a temperature value followed by its unit (e.g. 25C): ");
    fgets(input, MAX_LINE_SIZE, stdin);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Extract temperature value
    value = strtod(input, &unit);

    // Extract unit
    if (unit == input) {
        printf("Invalid input. Please enter a valid temperature value followed by its unit.\n");
        return 1;
    }

    // Convert unit to uppercase
    for (int i = 0; unit[i]!= '\0'; i++) {
        unit[i] = toupper(unit[i]);
    }

    // Determine base unit
    if (strstr(unit, "K")) {
        base = 0;
    } else if (strstr(unit, "C")) {
        base = 1;
    } else if (strstr(unit, "F")) {
        base = 2;
    } else {
        printf("Invalid unit. Please enter a valid temperature unit (K, C, F).\n");
        return 1;
    }

    // Convert temperature to different units
    switch (base) {
        case 0:
            result = value;
            break;
        case 1:
            result = value + 273.15;
            break;
        case 2:
            result = (value + 273.15) * 9 / 5;
            break;
        default:
            printf("Invalid base unit. Please enter a valid base unit (K, C, F).\n");
            return 1;
    }

    // Print result
    printf("%.2f%s = %.2f%s\n", value, unit, result, "K");

    return 0;
}