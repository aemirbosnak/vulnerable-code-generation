//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_LENGTH 50
#define MIN_FAHRENHEIT -327.67
#define MAX_FAHRENHEIT 327.67
#define MIN_CELSIUS -273.15
#define MAX_CELSIUS 273.15

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnit;

void print_usage() {
    printf("Usage: temperature_converter <value> <F/C>\n");
    printf("Example: temperature_converter 72 F\n");
    printf("         temperature_converter 22.5 C\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
    }

    TemperatureUnit unit = FAHRENHEIT;
    double value = atof(argv[1]);
    char conversion_char = argv[2][0];

    if (strlen(argv[1]) > MAX_INPUT_LENGTH || strlen(argv[2]) > 2) {
        print_usage();
    }

    if (argv[2][1] != '\0') {
        print_usage();
    }

    if (conversion_char == 'F' || conversion_char == 'f') {
        if (value < MIN_FAHRENHEIT || value > MAX_FAHRENHEIT) {
            printf("Error: Fahrenheit value out of range\n");
            print_usage();
        }
        unit = FAHRENHEIT;
    } else if (conversion_char == 'C' || conversion_char == 'c') {
        if (value < MIN_CELSIUS || value > MAX_CELSIUS) {
            printf("Error: Celsius value out of range\n");
            print_usage();
        }
        unit = CELSIUS;
    } else {
        print_usage();
    }

    double result;

    switch (unit) {
        case FAHRENHEIT:
            result = (value - 32) * 5.0 / 9.0;
            printf("%.2f Fahrenheit is equal to %.2f Celsius\n", value, result);
            break;
        case CELSIUS:
            result = value * 9.0 / 5.0 + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit\n", value, result);
            break;
    }

    return 0;
}