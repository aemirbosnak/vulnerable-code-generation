//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the unit conversion functions
double cm_to_in(double cm) {
    return cm / 2.54;
}

double in_to_cm(double in) {
    return in * 2.54;
}

double kg_to_lb(double kg) {
    return kg * 2.205;
}

double lb_to_kg(double lb) {
    return lb / 2.205;
}

double c_to_f(double c) {
    return c * 9 / 5 + 32;
}

double f_to_c(double f) {
    return (f - 32) * 5 / 9;
}

// Define the unit types
typedef enum {
    CM,
    IN,
    KG,
    LB,
    C,
    F
} unit_type;

// Define the unit conversion table
const double unit_conversion_table[][6] = {
    {1.0, 0.3937, 0.002205, 0.001016, 0.0, 0.0},
    {2.54, 1.0, 0.005512, 0.002516, 0.0, 0.0},
    {453.592, 181.437, 1.0, 0.453592, 0.0, 0.0},
    {907.185, 396.832, 2.205, 1.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
    {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}
};

// Get the unit type from the user
unit_type get_unit_type(char *unit) {
    if (strcmp(unit, "CM") == 0) {
        return CM;
    } else if (strcmp(unit, "IN") == 0) {
        return IN;
    } else if (strcmp(unit, "KG") == 0) {
        return KG;
    } else if (strcmp(unit, "LB") == 0) {
        return LB;
    } else if (strcmp(unit, "C") == 0) {
        return C;
    } else if (strcmp(unit, "F") == 0) {
        return F;
    } else {
        printf("Invalid unit: %s\n", unit);
        exit(1);
    }
}

// Convert the value from one unit to another
double convert_unit(double value, unit_type from_unit, unit_type to_unit) {
    return value * unit_conversion_table[from_unit][to_unit];
}

// Print the converted value
void print_converted_value(double value, unit_type to_unit) {
    switch (to_unit) {
        case CM:
            printf("%f cm\n", value);
            break;
        case IN:
            printf("%f in\n", value);
            break;
        case KG:
            printf("%f kg\n", value);
            break;
        case LB:
            printf("%f lb\n", value);
            break;
        case C:
            printf("%f C\n", value);
            break;
        case F:
            printf("%f F\n", value);
            break;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        exit(1);
    }

    // Get the value, from unit, and to unit from the user
    double value = atof(argv[1]);
    unit_type from_unit = get_unit_type(argv[2]);
    unit_type to_unit = get_unit_type(argv[3]);

    // Convert the value from one unit to another
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the converted value
    print_converted_value(converted_value, to_unit);

    return 0;
}