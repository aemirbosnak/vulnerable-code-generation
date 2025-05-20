//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double factor;
} unit_t;

unit_t units[] = {
    {"km", 1000.0},
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"in", 25.4},
    {"ft", 304.8},
    {"yd", 914.4},
    {"mi", 1609344.0},
    {"lb", 0.453592},
    {"kg", 1.0},
    {"g", 0.001},
    {"oz", 0.0283495},
    {"C", 1.0},
    {"F", 1.8},
    {"K", 1.0},
    {"R", 1.8},
};

int num_units = sizeof(units) / sizeof(unit_t);

double convert(double value, char *from, char *to) {
    int i, j;
    double result;

    for (i = 0; i < num_units; i++) {
        if (strcmp(from, units[i].name) == 0) {
            break;
        }
    }

    if (i == num_units) {
        fprintf(stderr, "Invalid unit: %s\n", from);
        return -1.0;
    }

    for (j = 0; j < num_units; j++) {
        if (strcmp(to, units[j].name) == 0) {
            break;
        }
    }

    if (j == num_units) {
        fprintf(stderr, "Invalid unit: %s\n", to);
        return -1.0;
    }

    result = value * units[i].factor / units[j].factor;

    return result;
}

int main(int argc, char **argv) {
    double value;
    char *from, *to;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s value from to\n", argv[0]);
        return EXIT_FAILURE;
    }

    value = atof(argv[1]);
    from = argv[2];
    to = argv[3];

    double result = convert(value, from, to);

    if (result == -1.0) {
        return EXIT_FAILURE;
    }

    printf("%f %s = %f %s\n", value, from, result, to);

    return EXIT_SUCCESS;
}