//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    float factor;
} unit;

unit units[] = {
    {"m", 1.0},
    {"km", 1000.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 160934.4},
    {"l", 1.0},
    {"ml", 0.001},
    {"fl.oz.", 0.0295735},
    {"gal", 3.78541},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 0.453592},
    {"oz", 0.0283495},
    {"c", 1.0},
    {"f", 1.8 + 32.0}
};

int num_units() {
    return sizeof(units) / sizeof(units[0]);
}

int find_unit(char *name) {
    int i;
    for (i = 0; i < num_units(); i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s from_unit to_unit value\n", argv[0]);
        return 1;
    }

    int from_unit_idx = find_unit(argv[1]);
    if (from_unit_idx == -1) {
        printf("Invalid from unit: %s\n", argv[1]);
        return 1;
    }

    int to_unit_idx = find_unit(argv[2]);
    if (to_unit_idx == -1) {
        printf("Invalid to unit: %s\n", argv[2]);
        return 1;
    }

    float value = atof(argv[3]);

    float result = value * units[to_unit_idx].factor / units[from_unit_idx].factor;

    printf("%.2f %s = %.2f %s\n", value, argv[1], result, argv[2]);

    return 0;
}