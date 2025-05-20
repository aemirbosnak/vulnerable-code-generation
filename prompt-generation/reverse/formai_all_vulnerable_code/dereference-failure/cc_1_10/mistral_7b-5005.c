//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    float value;
    char unit;
} Unit;

Unit units[] = {
    {3.28084, 'F'},
    {0.0254, 'm'},
    {0.001, 'kg'},
    {2.54, 'cm'},
    {1440.0, 'ft'},
    {1609.34, 'm'},
    {22046.2, 'lb'},
    {9.80665, 'kg/m^2'},
    {1609344.0, 'mile'},
    {121527.8, 'km'}
};

void print_usage() {
    printf("Usage:\n");
    printf("    converter <value> <from_unit> <to_unit>\n");
    printf("Example:\n");
    printf("    converter 10 F C\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    float value = atof(argv[1]);
    char from_unit = argv[2][0];
    char to_unit = argv[3][0];

    for (int i = 0; i < 10; ++i) {
        if (units[i].unit == from_unit) {
            value *= units[i].value;
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        if (units[i].unit == to_unit) {
            value /= units[i].value;
            printf("Result: %.2f %c\n", value, units[i].unit);
            return 0;
        }
    }

    printf("Invalid units. Use --help for more information.\n");
    return 1;
}