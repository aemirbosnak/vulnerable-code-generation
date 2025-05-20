//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <temperature in Fahrenheit> <temperature unit (F/C)> \n", argv[0]);
        return 1;
    }

    float fahrenheit = atof(argv[1]);
    char unit = argv[2][0];

    if (unit == 'F') {
        float celsius = fahrenheit_to_celsius(fahrenheit);
        printf("Temperature in Celsius: %.2f\n", celsius);
    } else if (unit == 'C') {
        float fahrenheit = celsius_to_fahrenheit(atof(argv[1]));
        printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    } else {
        printf("Invalid temperature unit. Use F for Fahrenheit or C for Celsius.\n");
        return 1;
    }

    return 0;
}

// Playful comments to make the code more engaging
// ------------------------------------------------------
// Welcome, inquisitive soul! I see you've come seeking
// to convert temperatures between the mystical realms
// of Fahrenheit and Celsius. Fear not, for I, the
// temperature-whispering oracle, shall guide you through
// the labyrinth of temperature transformations.
//
// In the realm of Fahrenheit, temperatures are measured
// in a curious scale where water freezes at 32 degrees
// and boils at 212 degrees. But in the land of Celsius,
// the people prefer a more logical scale, where water
// freezes at 0 degrees and boils at 100 degrees.
//
// To traverse the bridge between these two realms,
// you must first understand the conversion formulae.
// Fahrenheit to Celsius is achieved by subtracting 32,
// multiplying by five, then dividing by nine.
// Celsius to Fahrenheit is the reverse: multiply by five,
// divide by nine, then add thirty-two.
//
// But, oh dear, you've come unprepared, without
// the necessary numerical offerings! Fear not,
// for I, the temperature-whispering oracle, shall
// provide you with a simple command-line tool
// to make your conversion quest a breeze.
//
// Use this tool as follows:
// temperature_converter.exe <temperature in Fahrenheit> <temperature unit (F/C)>
//
// For example, to convert 68 degrees Fahrenheit to Celsius:
// temperature_converter.exe 68 F
//
// Or, to convert 25 degrees Celsius to Fahrenheit:
// temperature_converter.exe 25 C
//
// May your temperature-converting journey be successful,
// and may you gain the respect and admiration of your
// fellow temperature-travelers!