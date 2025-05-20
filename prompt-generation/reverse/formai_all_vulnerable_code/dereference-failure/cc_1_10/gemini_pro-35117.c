//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    UNIT_INVALID,
    UNIT_METERS,
    UNIT_CENTIMETERS,
    UNIT_INCHES,
    UNIT_FEET,
    UNIT_YARDS,
    UNIT_MILES,
    UNIT_KILOMETERS,
} Unit;

typedef struct {
    double value;
    Unit unit;
} Measurement;

static const char *unit_names[] = {
    "Invalid",
    "Meters",
    "Centimeters",
    "Inches",
    "Feet",
    "Yards",
    "Miles",
    "Kilometers",
};

static double conversion_factors[] = {
    1.0,                          // Meters
    0.01,                         // Centimeters
    0.0254,                       // Inches
    0.3048,                       // Feet
    0.9144,                       // Yards
    1609.34,                      // Miles
    1000.0,                      // Kilometers
};

static Measurement convert_measurement(Measurement measurement, Unit to_unit) {
    if (measurement.unit == UNIT_INVALID || to_unit == UNIT_INVALID) {
        fprintf(stderr, "Invalid unit conversion.\n");
        exit(EXIT_FAILURE);
    }

    double converted_value = measurement.value * conversion_factors[measurement.unit] / conversion_factors[to_unit];

    Measurement converted_measurement = {
        .value = converted_value,
        .unit = to_unit,
    };

    return converted_measurement;
}

static void print_measurement(Measurement measurement) {
    printf("%f %s\n", measurement.value, unit_names[measurement.unit]);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    double value = atof(argv[1]);
    Unit from_unit = UNIT_INVALID;
    Unit to_unit = UNIT_INVALID;

    for (int i = 0; i < sizeof(unit_names) / sizeof(unit_names[0]); i++) {
        if (strcmp(argv[2], unit_names[i]) == 0) {
            from_unit = i;
        }

        if (strcmp(argv[3], unit_names[i]) == 0) {
            to_unit = i;
        }
    }

    if (from_unit == UNIT_INVALID || to_unit == UNIT_INVALID) {
        fprintf(stderr, "Invalid unit specified.\n");
        exit(EXIT_FAILURE);
    }

    Measurement measurement = {
        .value = value,
        .unit = from_unit,
    };

    Measurement converted_measurement = convert_measurement(measurement, to_unit);

    print_measurement(converted_measurement);

    return 0;
}