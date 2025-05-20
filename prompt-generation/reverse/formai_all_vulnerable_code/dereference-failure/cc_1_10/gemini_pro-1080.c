//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ABSOLUTE_ZERO_CELSIUS,
    ABSOLUTE_ZERO_FAHRENHEIT
} absolute_zero_unit;

typedef struct {
    double celsius;
    double fahrenheit;
} temperature_t;

temperature_t convert_temperature(temperature_t temperature, absolute_zero_unit absolute_zero_unit) {
    switch (absolute_zero_unit) {
        case ABSOLUTE_ZERO_CELSIUS:
            temperature.fahrenheit = temperature.celsius * 9.0 / 5.0 + 32.0;
            break;
        case ABSOLUTE_ZERO_FAHRENHEIT:
            temperature.celsius = (temperature.fahrenheit - 32.0) * 5.0 / 9.0;
            break;
    }
    return temperature;
}

void print_temperature(temperature_t temperature, absolute_zero_unit absolute_zero_unit) {
    switch (absolute_zero_unit) {
        case ABSOLUTE_ZERO_CELSIUS:
            printf("%g degrees Celsius", temperature.celsius);
            break;
        case ABSOLUTE_ZERO_FAHRENHEIT:
            printf("%g degrees Fahrenheit", temperature.fahrenheit);
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <temperature> <absolute zero unit>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double temperature_value = atof(argv[1]);
    absolute_zero_unit absolute_zero_unit;
    if (strcmp(argv[2], "celsius") == 0) {
        absolute_zero_unit = ABSOLUTE_ZERO_CELSIUS;
    } else if (strcmp(argv[2], "fahrenheit") == 0) {
        absolute_zero_unit = ABSOLUTE_ZERO_FAHRENHEIT;
    } else {
        fprintf(stderr, "Invalid absolute zero unit: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    temperature_t temperature = {
        .celsius = temperature_value,
        .fahrenheit = temperature_value
    };
    temperature = convert_temperature(temperature, absolute_zero_unit);
    print_temperature(temperature, absolute_zero_unit);
    printf("\n");
    return EXIT_SUCCESS;
}