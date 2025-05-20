//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100
#define UNITS_COUNT 3

typedef struct {
    char symbol;
    float conversion_factor;
} Unit;

Unit units[UNITS_COUNT] = {
    {'C', 1.0f},
    {'F', 1.8f},
    {'K', -273.15f}
};

void print_usage() {
    printf("Usage: temperature_converter <value> <unit>\n");
    printf("Available units: C, F, K\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    float value = atof(argv[1]);
    char unit_from = argv[2][0];

    for (size_t i = 0; i < UNITS_COUNT; ++i) {
        if (units[i].symbol == unit_from) {
            Unit current_unit = units[i];
            float value_in_celsius = 0.0f;

            for (size_t j = 0; j < UNITS_COUNT; ++j) {
                if (j == i)
                    continue;

                float value_in_target_unit = value * current_unit.conversion_factor;
                Unit target_unit = units[j];

                value_in_celsius = value_in_target_unit / target_unit.conversion_factor;
            }

            printf("Value in Celsius: %.2f\n", value_in_celsius);
            return 0;
        }
    }

    print_usage();
    return 1;
}