//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERSIONS 5

typedef struct unit_converter {
    char *name;
    double conversion_factor;
} unit_converter_t;

unit_converter_t units[UNIT_CONVERTER_MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000.0},
    {"mi", 1609.34},
    {"ft", 0.3048},
    {"in", 0.0254},
    {"yd", 0.9144},
    {"mile", 1.60934}
};

void unit_converter_init(void);
void unit_converter_cleanup(void);
void unit_converter_convert(double value, char *from_unit, char *to_unit);

int main() {
    srand(time(NULL));

    unit_converter_init();

    printf("Welcome to the Unit Converter!\n");

    do {
        printf("Enter a value: ");
        double value = atof(gets());

        char from_unit[UNIT_CONVERTER_MAX_UNITS][20];
        char to_unit[UNIT_CONVERTER_MAX_UNITS][20];

        printf("Enter the unit to convert from (e.g. 'm', 'ft', etc.): ");
        fgets(from_unit, 20, stdin);

        printf("Enter the unit to convert to (e.g. 'm', 'ft', etc.): ");
        fgets(to_unit, 20, stdin);

        unit_converter_convert(value, from_unit, to_unit);
    } while (1);

    unit_converter_cleanup();

    return 0;
}

void unit_converter_init(void) {
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        units[i].name = malloc(strlen(units[i].name) + 1);
        strcpy(units[i].name, units[i].name);
    }
}

void unit_converter_cleanup(void) {
    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        free(units[i].name);
    }
}

void unit_converter_convert(double value, char *from_unit, char *to_unit) {
    int from_index = 0;
    int to_index = 0;

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_index = i;
            break;
        }
    }

    for (int i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            to_index = i;
            break;
        }
    }

    double conversion_factor = units[from_index].conversion_factor;

    double result = value * conversion_factor;

    char result_string[20];
    sprintf(result_string, "%.2f %s", result, to_unit);

    printf("%s is equal to %s\n", from_unit, result_string);
}