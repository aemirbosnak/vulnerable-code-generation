//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char input[50];
    char unit[5];
    double temperature;
    int i;

    // Prompt user to enter temperature and unit
    printf("Enter temperature and unit (e.g. 32 F): ");
    scanf("%s", input);

    // Check if unit is valid
    for (i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            printf("Invalid unit. Please enter a valid unit.\n");
            return 1;
        }
    }

    // Convert input string to uppercase
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Extract temperature value from input string
    temperature = atof(input);

    // Extract unit from input string
    strcpy(unit, input + strlen(input) - 1);

    // Convert temperature to Celsius
    if (strcmp(unit, "F") == 0) {
        temperature = (temperature - 32) * 5 / 9;
        printf("%.2lf F is %.2lf C\n", temperature, temperature);
    }

    // Convert temperature to Fahrenheit
    else if (strcmp(unit, "C") == 0) {
        temperature = (temperature * 9 / 5) + 32;
        printf("%.2lf C is %.2lf F\n", temperature, temperature);
    }

    // Invalid unit
    else {
        printf("Invalid unit. Please enter a valid unit.\n");
        return 1;
    }

    return 0;
}