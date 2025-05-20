//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double value;
    char* unit;
} Unit;

typedef struct {
    Unit* units;
    int num_units;
} Converter;

Converter* createConverter() {
    Converter* converter = malloc(sizeof(Converter));
    converter->units = malloc(sizeof(Unit) * 10);
    converter->num_units = 0;

    converter->units[0].value = 0;
    converter->units[0].unit = "km";

    converter->units[1].value = 1.609344;
    converter->units[1].unit = "m";

    converter->units[2].value = 0.621371;
    converter->units[2].unit = "ft";

    converter->units[3].value = 0.3048;
    converter->units[3].unit = "in";

    converter->units[4].value = 0.0254;
    converter->units[4].unit = "cm";

    converter->units[5].value = 0.001;
    converter->units[5].unit = "mm";

    converter->units[6].value = 0.0001;
    converter->units[6].unit = "m";

    converter->units[7].value = 0.001;
    converter->units[7].unit = "cm";

    converter->units[8].value = 0.0001;
    converter->units[8].unit = "mm";

    converter->units[9].value = 0.000001;
    converter->units[9].unit = "m";

    return converter;
}

void addUnit(Converter* converter, Unit unit) {
    if (converter->num_units < 10) {
        converter->units[converter->num_units] = unit;
        converter->num_units++;
    }
}

double convert(Converter* converter, double value, char* unit) {
    double result;

    for (int i = 0; i < converter->num_units; i++) {
        if (strcmp(converter->units[i].unit, unit) == 0) {
            result = value / converter->units[i].value;
            break;
        }
    }

    return result;
}

int main() {
    Converter* converter = createConverter();

    Unit unit;
    unit.value = 100;
    unit.unit = "m";
    addUnit(converter, unit);

    unit.value = 123.45;
    unit.unit = "km";
    addUnit(converter, unit);

    unit.value = 500;
    unit.unit = "ft";
    addUnit(converter, unit);

    unit.value = 1000;
    unit.unit = "in";
    addUnit(converter, unit);

    unit.value = 10000;
    unit.unit = "cm";
    addUnit(converter, unit);

    unit.value = 1000000;
    unit.unit = "mm";
    addUnit(converter, unit);

    unit.value = 1000000000;
    unit.unit = "m";
    addUnit(converter, unit);

    unit.value = 1000000000000;
    unit.unit = "km";
    addUnit(converter, unit);

    printf("Converted value: %.2f %s\n", convert(converter, 100.0, "m"), "m");
    printf("Converted value: %.2f %s\n", convert(converter, 123.45, "km"), "km");
    printf("Converted value: %.2f %s\n", convert(converter, 500.0, "ft"), "ft");
    printf("Converted value: %.2f %s\n", convert(converter, 1000.0, "in"), "in");
    printf("Converted value: %.2f %s\n", convert(converter, 10000.0, "cm"), "cm");
    printf("Converted value: %.2f %s\n", convert(converter, 1000000.0, "mm"), "mm");
    printf("Converted value: %.2f %s\n", convert(converter, 1000000000.0, "m"), "m");
    printf("Converted value: %.2f %s\n", convert(converter, 1000000000000.0, "km"), "km");

    free(converter->units);
    free(converter);

    return 0;
}