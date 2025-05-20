//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[10];
    double conversion_factor;
} Unit;

Unit temperature_units[] = {{"Fahrenheit", 5.0/9.0}, {"Celsius", 1.0}};
Unit length_units[] = {{"Inches", 2.54}};

void print_usage() {
    printf("Usage: unit_converter [convert|help] [unit] [value]\n");
    printf("Converts temperature or length units.\n");
    printf("Available temperature units: Fahrenheit, Celsius.\n");
    printf("Available length units: Inches.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    char command = argv[1][0];
    char unit_name[10];
    strcpy(unit_name, argv[2]);
    double value, result;

    if (command != 'c' && command != 'v' && command != 'h') {
        print_usage();
        return 1;
    }

    int i;
    for (i = 0; i < 2; i++) {
        if (strcmp(unit_name, temperature_units[i].name) == 0) {
            if (command == 'c') {
                value = atof(argv[3]);
                result = value * temperature_units[i].conversion_factor;
                printf("%.2f %s is equal to %.2f %s\n", value, unit_name, result, temperature_units[(i + 1) % 2].name);
            } else {
                value = atof(argv[3]);
                result = value * 1.0 / temperature_units[i].conversion_factor;
                printf("%.2f %s is equal to %.2f %s\n", value, unit_name, result, temperature_units[(i + 1) % 2].name);
            }
            break;
        }
    }

    for (i = 0; i < 1; i++) {
        if (strcmp(unit_name, length_units[i].name) == 0) {
            if (command == 'c') {
                value = atof(argv[3]);
                result = value * length_units[i].conversion_factor;
                printf("%.2f %s is equal to %.2f %s\n", value, unit_name, result, length_units[0].name);
            } else {
                value = atof(argv[3]);
                result = value / length_units[i].conversion_factor;
                printf("%.2f %s is equal to %.2f %s\n", value, unit_name, result, length_units[0].name);
            }
            break;
        }
    }

    if (i == 2) {
        printf("Invalid unit.\n");
        print_usage();
        return 1;
    }

    return 0;
}