//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80

typedef enum {
    CELSIUS = 0,
    FAHRENHEIT = 1,
} TemperatureUnit;

double convert_temperature(double temperature, TemperatureUnit from_unit, TemperatureUnit to_unit) {
    double result;
    switch (from_unit) {
        case CELSIUS:
            switch (to_unit) {
                case FAHRENHEIT:
                    result = temperature * 9.0 / 5.0 + 32.0;
                    break;
                default:
                    result = temperature;
                    break;
            }
            break;
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    result = (temperature - 32.0) * 5.0 / 9.0;
                    break;
                default:
                    result = temperature;
                    break;
            }
            break;
        default:
            result = temperature;
            break;
    }
    return result;
}

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    double temperature, result;
    TemperatureUnit from_unit, to_unit;
    char *endptr;

    printf("Enter the temperature value: ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Convert input to double
    temperature = strtod(input_buffer, &endptr);
    if (endptr == input_buffer) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    // Determine input temperature unit
    if (tolower(*endptr) == 'c') {
        from_unit = CELSIUS;
    } else if (tolower(*endptr) == 'f') {
        from_unit = FAHRENHEIT;
    } else {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    // Convert to desired temperature unit
    printf("Enter the desired temperature unit (C or F): ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);
    if (tolower(*input_buffer) == 'c') {
        to_unit = CELSIUS;
    } else if (tolower(*input_buffer) == 'f') {
        to_unit = FAHRENHEIT;
    } else {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    // Convert temperature and display result
    result = convert_temperature(temperature, from_unit, to_unit);
    printf("%.2f %c = %.2f %c\n", temperature, toupper(*endptr), result, toupper(*input_buffer));

    return 0;
}