//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    double (*convert)(double);
} unit_t;

double convert_millimeters_to_inches(double millimeters) {
    return millimeters / 25.4;
}

double convert_inches_to_millimeters(double inches) {
    return inches * 25.4;
}

double convert_centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

double convert_inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double convert_meters_to_feet(double meters) {
    return meters * 3.28084;
}

double convert_feet_to_meters(double feet) {
    return feet / 3.28084;
}

double convert_kilometers_to_miles(double kilometers) {
    return kilometers / 1.60934;
}

double convert_miles_to_kilometers(double miles) {
    return miles * 1.60934;
}

double convert_grams_to_ounces(double grams) {
    return grams / 28.3495;
}

double convert_ounces_to_grams(double ounces) {
    return ounces * 28.3495;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds / 2.20462;
}

double convert_liters_to_gallons(double liters) {
    return liters / 3.78541;
}

double convert_gallons_to_liters(double gallons) {
    return gallons * 3.78541;
}

double convert_celsius_to_fahrenheit(double celsius) {
    return celsius * 9 / 5 + 32;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

unit_t units[] = {
    {"millimeters", convert_millimeters_to_inches},
    {"inches", convert_inches_to_millimeters},
    {"centimeters", convert_centimeters_to_inches},
    {"inches", convert_inches_to_centimeters},
    {"meters", convert_meters_to_feet},
    {"feet", convert_feet_to_meters},
    {"kilometers", convert_kilometers_to_miles},
    {"miles", convert_miles_to_kilometers},
    {"grams", convert_grams_to_ounces},
    {"ounces", convert_ounces_to_grams},
    {"kilograms", convert_kilograms_to_pounds},
    {"pounds", convert_pounds_to_kilograms},
    {"liters", convert_liters_to_gallons},
    {"gallons", convert_gallons_to_liters},
    {"celsius", convert_celsius_to_fahrenheit},
    {"fahrenheit", convert_fahrenheit_to_celsius}
};

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <value> <from> <to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    double value = atof(argv[1]);
    char *from = argv[2];
    char *to = argv[3];

    int from_index = -1;
    int to_index = -1;
    for (int i = 0; i < sizeof(units) / sizeof(unit_t); i++) {
        if (strcmp(from, units[i].name) == 0) {
            from_index = i;
        }
        if (strcmp(to, units[i].name) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1) {
        fprintf(stderr, "Invalid unit: %s\n", from);
        return EXIT_FAILURE;
    }

    if (to_index == -1) {
        fprintf(stderr, "Invalid unit: %s\n", to);
        return EXIT_FAILURE;
    }

    double result = units[from_index].convert(value);
    result = units[to_index].convert(result);

    printf("%f %s = %f %s\n", value, from, result, to);

    return EXIT_SUCCESS;
}