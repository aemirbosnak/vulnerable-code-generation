//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

enum unit_type {
    METERS,
    CENTIMETERS,
    KILOMETERS,
    INCHES,
    FEET,
    YARDS,
    MILES,
};

struct conversion_table {
    enum unit_type type;
    double multiplier;
};

static const struct conversion_table table[] = {
    { METERS, 1.0 },
    { CENTIMETERS, 0.01 },
    { KILOMETERS, 1000.0 },
    { INCHES, 0.0254 },
    { FEET, 0.3048 },
    { YARDS, 0.9144 },
    { MILES, 1609.34 },
};

static const size_t num_conversions = sizeof(table) / sizeof(table[0]);

int main(int argc, char **argv) {
    double value;
    enum unit_type from_unit, to_unit;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s value from_unit to_unit\n", argv[0]);
        return 1;
    }

    value = atof(argv[1]);

    from_unit = strtol(argv[2], NULL, 10);
    to_unit = strtol(argv[3], NULL, 10);

    if (from_unit < 0 || from_unit >= num_conversions ||
        to_unit < 0 || to_unit >= num_conversions) {
        fprintf(stderr, "Invalid unit type\n");
        return 1;
    }

    printf("%f %s = %f %s\n",
        value, table[from_unit].type,
        value * table[from_unit].multiplier / table[to_unit].multiplier,
        table[to_unit].type);

    return 0;
}