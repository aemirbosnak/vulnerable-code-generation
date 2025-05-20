//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

static Unit units[NUM_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592}
};

int main(int argc, char *argv[]) {
    char *input_unit, *output_unit;
    double value, result;

    printf("Enter a value and its unit of measurement (e.g. 5.5 kg): ");
    if (scanf("%lf %s", &value, input_unit)!= 2) {
        printf("Invalid input format.\n");
        return 1;
    }

    printf("Enter the desired unit of measurement: ");
    scanf("%s", output_unit);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            for (int j = 0; j < NUM_UNITS; j++) {
                if (strcmp(output_unit, units[j].name) == 0) {
                    result = value * units[j].factor / units[i].factor;
                    printf("%lf %s = %lf %s\n", value, input_unit, result, output_unit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}