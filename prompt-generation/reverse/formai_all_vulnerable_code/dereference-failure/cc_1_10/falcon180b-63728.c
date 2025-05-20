//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8 + 32);
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return ((fahrenheit - 32) / 1.8);
}

// Function to generate a random number between two given numbers
int getRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to print the usage of the program
void printUsage() {
    printf("Usage:./program [celsius/fahrenheit] [value]\n");
    printf("Example:./program celsius 25\n");
    printf("Example:./program fahrenheit 77\n");
    exit(1);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printUsage();
    }

    char *unit = argv[1];
    double value = atof(argv[3]);

    // Convert Celsius to Fahrenheit
    if (strcmp(unit, "celsius") == 0) {
        double fahrenheit = celsiusToFahrenheit(value);
        printf("%.2f Celsius is equal to %.2f Fahrenheit\n", value, fahrenheit);
    }
    // Convert Fahrenheit to Celsius
    else if (strcmp(unit, "fahrenheit") == 0) {
        double celsius = fahrenheitToCelsius(value);
        printf("%.2f Fahrenheit is equal to %.2f Celsius\n", value, celsius);
    }
    // Invalid unit
    else {
        printUsage();
    }

    return 0;
}