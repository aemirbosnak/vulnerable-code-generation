//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CONVERTERS 14

typedef struct converter {
    char *name;
    double factor;
    int is_si;
} converter_t;

converter_t converters[NUM_CONVERTERS] = {
    {"Meter (m)", 1.0, 1},
    {"Kilometer (km)", 1000.0, 1},
    {"Micrometer (µm)", 0.000001, 0},
    {"Nanometer (nm)", 0.000000001, 0},
    {"Hectometer (hm)", 10000.0, 0},
    {"Decimeter (dm)", 0.1, 0},
    {"Centimeter (cm)", 0.01, 0},
    {"Millimeter (mm)", 0.001, 0},
    {"Kilogram (kg)", 1000.0, 1},
    {"Gram (g)", 0.001, 1},
    {"Milligram (mg)", 0.000001, 1},
    {"Kilopascal (kPa)", 0.001, 1},
    {"Pascal (Pa)", 1.0, 1}
};

void print_usage(void) {
    printf("Usage: unit_converter <from_unit> <to_unit> <value>\n");
    printf("Available units:\n");
    for (int i = 0; i < NUM_CONVERTERS; ++i) {
        printf("%s\n", converters[i].name);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    int from_index = -1;
    int to_index = -1;

    for (int i = 0; i < NUM_CONVERTERS; ++i) {
        if (strcmp(argv[1], converters[i].name) == 0) {
            from_index = i;
        }
        if (strcmp(argv[2], converters[i].name) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        print_usage();
        return 1;
    }

    double value;
    int success = sscanf(argv[3], "%lf", &value);
    if (success != 1) {
        printf("Invalid value: %s\n", argv[3]);
        print_usage();
        return 1;
    }

    double result = value * converters[to_index].factor / converters[from_index].factor;
    printf("%.16lf %s is equal to %.16lf %s\n", value, argv[1], result, argv[2]);

    return 0;
}