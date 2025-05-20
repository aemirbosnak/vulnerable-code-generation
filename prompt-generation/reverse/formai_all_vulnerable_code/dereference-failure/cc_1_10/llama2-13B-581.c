//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERSIONS 5

typedef struct unit_converter {
    char *name;
    double factor;
} unit_converter_t;

static unit_converter_t unit_converters[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"yd", 0.9144},
    {"ft", 1},
    {"in", 0.0254},
    {"lb", 0.453592},
    {"oz", 0.0283495}
};

void unit_converter_init(void);
void unit_converter_add_conversion(const char *from_unit, const char *to_unit);
void unit_converter_convert(const char *from_unit, const char *to_unit, double value);

int main() {
    srand(time(NULL));

    unit_converter_init();

    char *from_unit = "ft";
    char *to_unit = "m";
    double value = 5.5;

    unit_converter_convert(from_unit, to_unit, value);

    printf("Result: %f\n", value);

    return 0;
}

void unit_converter_init(void) {
    int i;

    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        unit_converters[i].name = (char *) malloc(strlen("Unknown Unit") + 1);
        strcpy(unit_converters[i].name, "Unknown Unit");
    }
}

void unit_converter_add_conversion(const char *from_unit, const char *to_unit) {
    int i = 0;

    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, unit_converters[i].name) == 0) {
            break;
        }
    }

    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return;
    }

    unit_converters[i].name = (char *) malloc(strlen(to_unit) + 1);
    strcpy(unit_converters[i].name, to_unit);
    unit_converters[i].factor = 1;
}

void unit_converter_convert(const char *from_unit, const char *to_unit, double value) {
    int i = 0;

    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, unit_converters[i].name) == 0) {
            break;
        }
    }

    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit: %s\n", from_unit);
        return;
    }

    value *= unit_converters[i].factor;
    value /= unit_converters[i].factor;

    printf("Conversion: %f %s -> %f %s\n", value, from_unit, value, to_unit);
}