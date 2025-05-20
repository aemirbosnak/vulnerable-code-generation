//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROTECTED

typedef struct UnitConverter {
    double value;
    char unit_from;
    char unit_to;
} UnitConverter;

UnitConverter* convert_units(double value, char unit_from, char unit_to) {
    UnitConverter* converter = malloc(sizeof(UnitConverter));
    converter->value = value;
    converter->unit_from = unit_from;
    converter->unit_to = unit_to;
    return converter;
}

void print_conversion(UnitConverter* converter) {
    double converted_value = converter->value;
    char unit_to = converter->unit_to;

    switch (unit_to) {
        case 'm':
            converted_value *= 1000;
            printf("%lf meters\n", converted_value);
            break;
        case 'kg':
            converted_value *= 1000;
            printf("%lf kilograms\n", converted_value);
            break;
        case 'l':
            converted_value *= 1000;
            printf("%lf liters\n", converted_value);
            break;
        default:
            printf("Invalid unit conversion.\n");
    }
}

int main() {
    PROTECTED

    double value = 10;
    char unit_from = 'kg';
    char unit_to = 'm';

    UnitConverter* converter = convert_units(value, unit_from, unit_to);
    print_conversion(converter);

    free(converter);

    return 0;
}