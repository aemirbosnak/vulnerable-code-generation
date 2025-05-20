//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef uint32_t UnitIdType;
typedef double UnitValue;

typedef struct {
    const char *name;
    double conversion_factor;
} Unit;

static const Unit units[] = {
    {"inch", 2.54},
    {"foot", 30.48},
    {"yard", 91.44},
    {"mile", 160934.4},
    {"centimeter", 1},
    {"meter", 100},
    {"kilometer", 100000},
    {"pound", 0.453592},
    {"kilogram", 1000},
    {"ounce", 28.3495},
    {"gram", 1},
    {"fahrenheit", 5 / 9},
    {"celsius", 9 / 5},
    {"kelvin", 1},
};

static const char *invalid_unit_name = "INVALID";

static UnitIdType find_unit_id(const char *name) {
    for (UnitIdType i = 0; i < ARRAY_SIZE(units); i++) {
        if (strcmp(name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

static UnitValue convert_unit_value(UnitIdType from_unit_id, UnitIdType to_unit_id, UnitValue value) {
    if (from_unit_id == -1 || to_unit_id == -1) {
        return -1;
    }
    return value * units[to_unit_id].conversion_factor / units[from_unit_id].conversion_factor;
}

static int print_unit_conversion(const char *from_unit_name, const char *to_unit_name, UnitValue value) {
    UnitIdType from_unit_id = find_unit_id(from_unit_name);
    UnitIdType to_unit_id = find_unit_id(to_unit_name);
    if (from_unit_id == -1 || to_unit_id == -1) {
        return -1;
    }
    UnitValue converted_value = convert_unit_value(from_unit_id, to_unit_id, value);
    if (converted_value == -1) {
        return -1;
    }
    printf("%f %s is equal to %f %s\n", value, from_unit_name, converted_value, to_unit_name);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return EXIT_FAILURE;
    }
    UnitValue value;
    if (sscanf(argv[1], "%lf", &value) != 1) {
        fprintf(stderr, "Invalid value: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    const char *from_unit_name = argv[2];
    const char *to_unit_name = argv[3];
    if (print_unit_conversion(from_unit_name, to_unit_name, value) != 0) {
        fprintf(stderr, "Invalid unit conversion: %s -> %s\n", from_unit_name, to_unit_name);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}