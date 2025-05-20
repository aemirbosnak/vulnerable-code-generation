//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNIT_CONVERSION_ERROR -1
#define UNIT_CONVERSION_SUCCESS 0

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    double value;
    Unit *unit;
} Quantity;

Unit *new_unit(char *name, double factor) {
    Unit *unit = (Unit *)malloc(sizeof(Unit));
    unit->name = strdup(name);
    unit->factor = factor;
    return unit;
}

Quantity *new_quantity(char *name, double value, Unit *unit) {
    Quantity *quantity = (Quantity *)malloc(sizeof(Quantity));
    quantity->name = strdup(name);
    quantity->value = value;
    quantity->unit = unit;
    return quantity;
}

int convert_quantity(Quantity *from, Quantity *to) {
    double factor = from->unit->factor / to->unit->factor;
    to->value = from->value * factor;
    return UNIT_CONVERSION_SUCCESS;
}

int main() {
    Unit *meter = new_unit("meter", 1);
    Unit *centimeter = new_unit("centimeter", 0.01);
    Unit *kilometer = new_unit("kilometer", 1000);

    Quantity *distance = new_quantity("distance", 1500, meter);

    printf("The distance is %s.\n", distance->name);

    Quantity *new_distance = new_quantity("distance", 1500, centimeter);

    int conversion_result = convert_quantity(distance, new_distance);

    if (conversion_result == UNIT_CONVERSION_SUCCESS) {
        printf("The distance is now %s.\n", new_distance->name);
    } else {
        printf("Conversion error.\n");
    }

    return 0;
}