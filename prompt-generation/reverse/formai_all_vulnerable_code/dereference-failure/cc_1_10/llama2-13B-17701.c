//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_AMOUNTS 10

typedef struct unit_converter_t {
    char *name;
    double factor;
} unit_converter_t;

static unit_converter_t unit_converters[UNIT_CONVERTER_MAX_UNITS][UNIT_CONVERTER_MAX_AMOUNTS] = {
    { "inch", 2.54 },
    { "foot", 12 },
    { "yard", 36 },
    { "mile", 5280 },
    { "centimeter", 0.01 },
    { "meter", 1 },
    { "kilometer", 1000 },
    { "gram", 0.001 },
    { "kilogram", 1000 },
    { "ounce", 0.0283495 },
    { "pound", 16 },
    { "ton", 2000 }
};

void init_unit_converters(void) {
    int i, j;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        for (j = 0; j < UNIT_CONVERTER_MAX_AMOUNTS; j++) {
            unit_converters[i][j].name = malloc(sizeof(char) * (strlen(unit_converters[i][j].name) + 1));
            strcpy(unit_converters[i][j].name, unit_converters[i][j].name);
        }
    }
}

void convert_unit(double amount, char *from_unit, char *to_unit) {
    int i, j;
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        for (j = 0; j < UNIT_CONVERTER_MAX_AMOUNTS; j++) {
            if (strcmp(from_unit, unit_converters[i][j].name) == 0) {
                amount *= unit_converters[i][j].factor;
                break;
            }
        }
        if (j == UNIT_CONVERTER_MAX_AMOUNTS) {
            printf("Invalid from unit: %s\n", from_unit);
            return;
        }
    }
    printf("Amount in %s is %f\n", to_unit, amount);
}

int main(void) {
    init_unit_converters();

    double amount = 5.5;
    char from_unit[] = "inch";
    char to_unit[] = "centimeter";

    convert_unit(amount, from_unit, to_unit);

    return 0;
}