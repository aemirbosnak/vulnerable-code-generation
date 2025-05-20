//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONVERT_NUM 10

typedef struct ConvertUnit {
    char unit_name[20];
    double conversion_factor;
    int min_num;
    int max_num;
} ConvertUnit;

ConvertUnit units[] = {
    {"Gram", 1, 0, MAX_CONVERT_NUM},
    {"Kilogram", 1000, 0, MAX_CONVERT_NUM},
    {"Pound", 2.2046, 0, MAX_CONVERT_NUM},
    {"Ounces", 2.2046, 0, MAX_CONVERT_NUM},
    {"Pint", 0.0568, 0, MAX_CONVERT_NUM},
    {"Quart", 0.2364, 0, MAX_CONVERT_NUM},
    {"Liter", 1000, 0, MAX_CONVERT_NUM},
    {"Cubic Meter", 1000000, 0, MAX_CONVERT_NUM}
};

double convert_unit(double value, char from_unit, char to_unit) {
    int i = 0;
    double conversion_factor = 1;

    for (i = 0; i < MAX_CONVERT_NUM; i++) {
        if (strcmp(units[i].unit_name, from_unit) == 0) {
            conversion_factor = units[i].conversion_factor;
        }
        if (strcmp(units[i].unit_name, to_unit) == 0) {
            return value * conversion_factor;
        }
    }

    return -1;
}

int main() {
    double value = 50;
    char from_unit = 'K';
    char to_unit = 'G';

    double converted_value = convert_unit(value, from_unit, to_unit);

    if (converted_value != -1) {
        printf("%lf %s is equal to %lf %s.\n", value, from_unit, converted_value, to_unit);
    } else {
        printf("Error converting units.\n");
    }

    return 0;
}