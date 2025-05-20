//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024
#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"cm", 0.01},
    {"m", 1},
    {"km", 1000},
    {"mm", 0.001},
    {"in", 0.08333333333333333},
    {"ft", 12},
    {"yd", 36},
    {"mi", 1760},
    {"kg", 0.001},
    {"g", 0.000001},
    {"lb", 0.45359237000000001}
};

void init_units(void);
void convert_units(double value, char *from_unit, char *to_unit);

int main(void) {
    init_units();

    char *input_unit = "cm";
    char *output_unit = "in";
    double value = 10;

    convert_units(value, input_unit, output_unit);

    return 0;
}

void init_units(void) {
    for (int i = 0; i < MAX_UNITS; i++) {
        units[i].name = (char *)malloc(strlen(units[i].name) + 1);
        strcpy(units[i].name, units[i].name);
    }
}

void convert_units(double value, char *from_unit, char *to_unit) {
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, units[i].name) == 0) {
            value /= units[i].factor;
            break;
        }
    }

    printf("%.2f %s = %.2f %s\n", value, from_unit, value, to_unit);
}