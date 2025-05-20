//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *unit;
    double factor;
} TemperatureUnit;

TemperatureUnit temperature_units[] = {
    {"C", 1.0},
    {"F", 1.8},
    {"K", 1.0}
};

int temperature_units_count = sizeof(temperature_units) / sizeof(TemperatureUnit);

double get_temperature(char *line) {
    char *endptr;
    double temperature = strtod(line, &endptr);
    if (endptr == line || *endptr!= '\0') {
        printf("Invalid temperature value: %s\n", line);
        exit(1);
    }
    return temperature;
}

int get_unit_index(char *unit) {
    for (int i = 0; i < temperature_units_count; i++) {
        if (strcmp(unit, temperature_units[i].unit) == 0) {
            return i;
        }
    }
    printf("Invalid temperature unit: %s\n", unit);
    exit(1);
}

void convert_temperature(double temperature, int from_unit_index, int to_unit_index) {
    double factor = temperature_units[to_unit_index].factor;
    double result = temperature * factor;
    printf("%g %s = %g %s\n", temperature, temperature_units[from_unit_index].unit, result, temperature_units[to_unit_index].unit);
}

int main() {
    char input_line[MAX_LINE_LENGTH];
    while (fgets(input_line, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *line = input_line;
        char *unit_from = strtok(line, " ");
        char *unit_to = strtok(NULL, " ");
        if (unit_from == NULL || unit_to == NULL) {
            printf("Invalid input format: %s\n", input_line);
            continue;
        }
        double temperature_from = get_temperature(unit_from);
        int from_unit_index = get_unit_index(unit_from);
        int to_unit_index = get_unit_index(unit_to);
        convert_temperature(temperature_from, from_unit_index, to_unit_index);
    }
    return 0;
}