//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define NUM_UNITS 10

typedef struct {
    char *name;
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"meter", 1.0},
    {"kilogram", 1000.0},
    {"second", 1.0},
    {"ampere", 1.0},
    {"kelvin", 1.0},
    {"mole", 6.02214076e23},
    {"coulomb", 3.33564e-19},
    {"watt", 1.0},
    {"joule", 1.0},
    {"volt", 1.0}
};

void print_usage(void) {
    printf("Usage: unit_converter <convert|list|help> <from_unit> <to_unit> <value>\n");
}

bool parse_unit(char *str, Unit *unit, size_t unit_count) {
    for (size_t i = 0; i < unit_count; i++) {
        size_t len = strlen(units[i].name);
        if (strncmp(str, units[i].name, len) == 0) {
            *unit = units[i];
            return true;
        }
    }
    return false;
}

void convert(Unit from_unit, Unit to_unit, double value) {
    double result = value * (to_unit.conversion_factor / from_unit.conversion_factor);
    printf("%.16f %s is equal to %.16f %s\n", value, from_unit.name, result, to_unit.name);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    char action = argv[1][0];
    Unit from_unit, to_unit;
    double value;

    if (action != 'c' && action != 'l' && action != 'h') {
        print_usage();
        return 1;
    }

    if (action == 'h') {
        print_usage();
        return 0;
    }

    if (sscanf(argv[2], "%lf", &value) != 1) {
        fprintf(stderr, "Invalid value: %s\n", argv[2]);
        print_usage();
        return 1;
    }

    if (parse_unit(argv[3], &from_unit, NUM_UNITS)) {
        if (parse_unit(argv[4], &to_unit, NUM_UNITS)) {
            if (action == 'c') {
                convert(from_unit, to_unit, value);
            }
        } else {
            fprintf(stderr, "Invalid to unit: %s\n", argv[4]);
            print_usage();
            return 1;
        }
    } else {
        fprintf(stderr, "Invalid from unit: %s\n", argv[3]);
        print_usage();
        return 1;
    }

    return 0;
}