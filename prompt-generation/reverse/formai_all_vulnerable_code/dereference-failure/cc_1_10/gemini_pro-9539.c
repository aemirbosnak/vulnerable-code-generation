//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

// Define the conversion functions
double ctof(double c) { return (c * 9 / 5) + 32; }
double ftoc(double f) { return (f - 32) * 5 / 9; }

// Define the unit types
enum unit_type {CELSIUS, FAHRENHEIT};

// Define the conversion structure
typedef struct {
    enum unit_type from;
    enum unit_type to;
    double (*convert)(double);
} conversion;

// Define the conversions
static conversion conversions[] = {
    {CELSIUS,    FAHRENHEIT,  ctof},
    {FAHRENHEIT,  CELSIUS,    ftoc},
};

// Define the number of conversions
static const int num_conversions = sizeof(conversions) / sizeof(conversions[0]);

// Print the usage
void usage(void) {
    printf("Usage: unit_converter <from> <to> <value>\n");
    printf("Available conversions:\n");
    for (int i = 0; i < num_conversions; i++) {
        printf("  %s to %s\n",
            conversions[i].from == CELSIUS ? "Celsius" : "Fahrenheit",
            conversions[i].to == CELSIUS ? "Celsius" : "Fahrenheit");
    }
}

// Parse the arguments
int main(int argc, char **argv) {
    if (argc != 4) {
        usage();
        return 1;
    }

    // Parse the from and to unit types
    enum unit_type from = CELSIUS;
    if (strcmp(argv[1], "Celsius") == 0) {
        from = CELSIUS;
    } else if (strcmp(argv[1], "Fahrenheit") == 0) {
        from = FAHRENHEIT;
    } else {
        usage();
        return 1;
    }

    enum unit_type to = CELSIUS;
    if (strcmp(argv[2], "Celsius") == 0) {
        to = CELSIUS;
    } else if (strcmp(argv[2], "Fahrenheit") == 0) {
        to = FAHRENHEIT;
    } else {
        usage();
        return 1;
    }

    // Find the conversion
    conversion *conv = NULL;
    for (int i = 0; i < num_conversions; i++) {
        if (conversions[i].from == from && conversions[i].to == to) {
            conv = &conversions[i];
            break;
        }
    }

    if (conv == NULL) {
        printf("No conversion available from %s to %s\n", argv[1], argv[2]);
        return 1;
    }

    // Parse the value
    double value = atof(argv[3]);

    // Convert the value
    double converted_value = conv->convert(value);

    // Print the result
    printf("%f %s = %f %s\n",
        value, argv[1], converted_value, argv[2]);

    return 0;
}