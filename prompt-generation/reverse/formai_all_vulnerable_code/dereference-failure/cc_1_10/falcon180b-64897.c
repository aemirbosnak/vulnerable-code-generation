//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONVERSIONS 1000

typedef struct {
    char *name;
    double factor;
    int decimal_places;
} Conversion;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_value> <input_unit> <output_unit>\n", argv[0]);
        return 1;
    }

    char *input_value_str = argv[1];
    char *input_unit = argv[2];
    char *output_unit = argv[3];

    double input_value = strtod(input_value_str, NULL);
    int input_unit_index = -1;
    int output_unit_index = -1;

    Conversion conversions[MAX_CONVERSIONS];
    int num_conversions = 0;

    conversions[num_conversions++] = (Conversion) {"meters", 1.0, 2};
    conversions[num_conversions++] = (Conversion) {"centimeters", 0.01, 2};
    conversions[num_conversions++] = (Conversion) {"millimeters", 0.001, 2};
    conversions[num_conversions++] = (Conversion) {"kilometers", 1000.0, 2};

    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(input_unit, conversions[i].name) == 0) {
            input_unit_index = i;
            break;
        }
    }

    for (int i = 0; i < num_conversions; i++) {
        if (strcmp(output_unit, conversions[i].name) == 0) {
            output_unit_index = i;
            break;
        }
    }

    if (input_unit_index == -1 || output_unit_index == -1) {
        printf("Invalid unit(s)\n");
        return 1;
    }

    double factor = conversions[output_unit_index].factor / conversions[input_unit_index].factor;
    int decimal_places = conversions[output_unit_index].decimal_places;

    double result = input_value * factor;

    printf("%.*f %s = %.*f %s\n", decimal_places, input_value, input_unit, decimal_places, result, output_unit);

    return 0;
}