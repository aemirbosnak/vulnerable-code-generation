//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char input[100];
    char *unit;
    double temperature, converted;
    int choice;

    printf("Welcome to the temperature converter!\n");
    printf("Please enter a temperature and its unit (e.g. 20 C): ");
    scanf("%s", input);

    // Convert the input string to uppercase
    for(int i=0; input[i]!='\0'; i++) {
        input[i] = toupper(input[i]);
    }

    // Extract the temperature value and its unit
    temperature = strtod(input, &unit);

    // Check if the input is valid
    if(unit[0]!= 'C' && unit[0]!= 'F' && unit[0]!= 'K') {
        printf("Invalid unit.\n");
        return 1;
    }

    printf("Please choose the unit you want to convert to:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            converted = temperature;
            break;
        case 2:
            converted = (temperature * 9/5) + 32;
            break;
        case 3:
            converted = temperature + 273.15;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("The converted temperature is %.2f %c.\n", converted, unit[0]);

    return 0;
}