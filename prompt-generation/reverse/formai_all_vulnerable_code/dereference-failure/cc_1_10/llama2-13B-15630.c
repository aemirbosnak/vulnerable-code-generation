//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 100
#define UNIT_CONVERTER_MAX_CONVERSIONS 10

typedef struct unit_converter_t {
    char *name;
    double factor;
} unit_converter_t;

static unit_converter_t unit_converters[UNIT_CONVERTER_MAX_UNITS][UNIT_CONVERTER_MAX_CONVERSIONS];

void init_unit_converters(void) {
    unit_converters[0][0].name = "m";
    unit_converters[0][0].factor = 1;
    unit_converters[1][0].name = "cm";
    unit_converters[1][0].factor = 0.01;
    unit_converters[2][0].name = "km";
    unit_converters[2][0].factor = 0.001;
    unit_converters[3][0].name = "ft";
    unit_converters[3][0].factor = 0.3048;
    unit_converters[4][0].name = "in";
    unit_converters[4][0].factor = 0.0254;
    unit_converters[5][0].name = "yd";
    unit_converters[5][0].factor = 0.09144;
    unit_converters[6][0].name = "mi";
    unit_converters[6][0].factor = 0.000621371;
    unit_converters[7][0].name = "gal";
    unit_converters[7][0].factor = 0.003785;
    unit_converters[8][0].name = "pt";
    unit_converters[8][0].factor = 0.00035274;
    unit_converters[9][0].name = "fl oz";
    unit_converters[9][0].factor = 0.02366;
}

void convert_unit(double value, char *from_unit, char *to_unit) {
    int from_index = 0, to_index = 0;
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, unit_converters[i][0].name) == 0) {
            from_index = i;
            break;
        }
    }
    for (int i = 0; i < UNIT_CONVERTER_MAX_CONVERSIONS; i++) {
        if (strcmp(to_unit, unit_converters[from_index][i].name) == 0) {
            to_index = from_index;
            break;
        }
    }
    double factor = unit_converters[from_index][to_index].factor;
    value *= factor;
    printf("%.2f %s = %.2f %s\n", value, from_unit, value / factor, to_unit);
}

int main(void) {
    srand(time(NULL));
    init_unit_converters();
    double value = rand() % 100;
    char from_unit[10];
    char to_unit[10];
    do {
        printf("Enter a unit (m/cm/km/ft/in/yd/mi): ");
        fgets(from_unit, 10, stdin);
        printf("Enter a conversion (m/cm/km/ft/in/yd/mi): ");
        fgets(to_unit, 10, stdin);
        convert_unit(value, from_unit, to_unit);
    } while (1);
    return 0;
}