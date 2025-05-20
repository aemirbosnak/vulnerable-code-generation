//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 100
#define MAX_UNIT_NAME_LEN 32
#define MAX_CONVERSION_FACTOR_LEN 32

typedef struct {
    char name[MAX_UNIT_NAME_LEN];
    double conversion_factor;
} unit_t;

unit_t units[MAX_UNITS];
int num_units = 0;

void add_unit(char *name, double conversion_factor) {
    if (num_units == MAX_UNITS) {
        fprintf(stderr, "Too many units\n");
        exit(1);
    }

    strcpy(units[num_units].name, name);
    units[num_units].conversion_factor = conversion_factor;
    num_units++;
}

void print_units() {
    for (int i = 0; i < num_units; i++) {
        printf("%s: %f\n", units[i].name, units[i].conversion_factor);
    }
}

double convert(char *from_unit, char *to_unit, double value) {
    int from_unit_index = -1;
    int to_unit_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_index = i;
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1) {
        fprintf(stderr, "Invalid from unit: %s\n", from_unit);
        exit(1);
    }

    if (to_unit_index == -1) {
        fprintf(stderr, "Invalid to unit: %s\n", to_unit);
        exit(1);
    }

    return value * units[from_unit_index].conversion_factor / units[to_unit_index].conversion_factor;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s from_unit to_unit value conversion_factor\n", argv[0]);
        exit(1);
    }

    double value = atof(argv[3]);
    double conversion_factor = atof(argv[4]);

    add_unit(argv[1], conversion_factor);
    add_unit(argv[2], 1.0);

    printf("%f %s = %f %s\n", value, argv[1], convert(argv[1], argv[2], value), argv[2]);

    return 0;
}