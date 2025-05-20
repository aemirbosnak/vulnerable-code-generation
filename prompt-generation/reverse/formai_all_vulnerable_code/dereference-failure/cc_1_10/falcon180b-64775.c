//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_TOKEN_SIZE 20
#define MAX_ERROR_SIZE 50

typedef struct {
    char *name;
    int value;
} temperature_unit;

temperature_unit units[] = {{"celsius", 0}, {"fahrenheit", 1}};

int get_unit_value(char *unit_name) {
    int i = 0;
    while (i < sizeof(units) / sizeof(units[0])) {
        if (strcmp(unit_name, units[i].name) == 0) {
            return units[i].value;
        }
        i++;
    }
    return -1;
}

double convert_temperature(double temperature, int from_unit, int to_unit) {
    if (from_unit == to_unit) {
        return temperature;
    }
    if (from_unit == 0 && to_unit == 1) {
        return (temperature * 9 / 5) + 32;
    }
    if (from_unit == 1 && to_unit == 0) {
        return (temperature - 32) * 5 / 9;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <temperature> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }
    char *endptr = NULL;
    double temperature = strtod(argv[1], &endptr);
    if (endptr == argv[1]) {
        printf("Invalid temperature value.\n");
        return 1;
    }
    int from_unit = get_unit_value(argv[2]);
    int to_unit = get_unit_value(argv[3]);
    if (from_unit == -1 || to_unit == -1) {
        printf("Invalid temperature unit.\n");
        return 1;
    }
    double result = convert_temperature(temperature, from_unit, to_unit);
    if (result == -1) {
        printf("Invalid temperature conversion.\n");
        return 1;
    }
    printf("%.2f %s = %.2f %s\n", temperature, argv[2], result, argv[3]);
    return 0;
}