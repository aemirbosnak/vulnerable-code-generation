//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_LINE 1000

int main() {
    char input[MAX_LINE];
    char unit[MAX_LINE];
    char *endptr;
    double value, result;
    int choice;

    printf("Enter temperature value and unit (e.g. 20 C): ");
    fgets(input, MAX_LINE, stdin);

    // Extract temperature value
    value = strtod(input, &endptr);
    if (endptr == input) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    // Extract unit
    strcpy(unit, endptr);
    for (int i = 0; i < strlen(unit); i++) {
        if (!isalpha(unit[i])) {
            unit[i] = '\0';
            break;
        }
    }

    // Convert to Celsius
    switch (toupper(unit[0])) {
        case 'F':
            result = (value - 32) * 5 / 9;
            printf("%.2f F = %.2f C\n", value, result);
            break;
        case 'K':
            result = value - 273.15;
            printf("%.2f K = %.2f C\n", value, result);
            break;
        default:
            printf("Invalid unit.\n");
            return 1;
    }

    printf("Would you like to convert another temperature? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'n') {
        return 0;
    }

    return 1;
}