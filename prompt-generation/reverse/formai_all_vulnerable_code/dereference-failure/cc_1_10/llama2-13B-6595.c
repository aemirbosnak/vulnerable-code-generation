//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    Unit units[MAX_UNITS];
} Conversion;

static Conversion conversions[MAX_CONVERSIONS] = {
    {"m", {{"m", 1.0}, {"cm", 0.01}, {"km", 1000.0}}},
    {"cm", {{"cm", 1.0}, {"m", 0.01}, {"km", 0.001}}},
    {"km", {{"km", 1.0}, {"m", 0.001}, {"cm", 0.00001}}},
    {"g", {{"g", 1.0}, {"kg", 0.001}, {"lb", 0.00001}}},
    {"kg", {{"kg", 1.0}, {"g", 0.001}, {"lb", 0.00001}}},
    {"lb", {{"lb", 1.0}, {"g", 0.00001}, {"kg", 0.0001}}},
    {"ft", {{"ft", 1.0}, {"m", 3.28084}, {"yd", 0.9144}}},
    {"yd", {{"yd", 1.0}, {"ft", 0.9144}, {"m", 0.9144}}},
    {"inch", {{"inch", 1.0}, {"ft", 12.0}, {"yd", 36.0}}},
};

void init_conversions(void) {
    int i;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        conversions[i].name = malloc(strlen(conversions[i].name) + 1);
        strcpy(conversions[i].name, conversions[i].name);
    }
}

void destroy_conversions(void) {
    int i;
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        free(conversions[i].name);
    }
}

void convert(double value, char *from_unit, char *to_unit) {
    int i = 0;
    for (; i < MAX_CONVERSIONS; i++) {
        if (strcmp(from_unit, conversions[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_CONVERSIONS) {
        printf("Invalid unit: %s\n", from_unit);
        return;
    }
    for (; i < MAX_UNITS; i++) {
        if (strcmp(to_unit, conversions[i].name) == 0) {
            break;
        }
    }
    if (i == MAX_UNITS) {
        printf("Invalid unit: %s\n", to_unit);
        return;
    }
    double factor = conversions[i].units[0].factor;
    value *= factor;
    printf("%.2f %s = %.2f %s\n", value, from_unit, value, to_unit);
}

int main() {
    init_conversions();
    double value = 5.0;
    char from_unit[] = "m";
    char to_unit[] = "ft";
    convert(value, from_unit, to_unit);
    destroy_conversions();
    return 0;
}