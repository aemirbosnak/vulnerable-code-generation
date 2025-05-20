//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 50
#define INPUT_SIZE 100

typedef struct {
    char *name;
    double factor;
} unit;

unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Too many units defined.\n");
        return;
    }
    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

int get_unit_index(char *name) {
    int i;
    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, int from_unit_index, int to_unit_index) {
    return value * units[to_unit_index].factor / units[from_unit_index].factor;
}

int main() {
    char input[INPUT_SIZE];
    char *token;
    int from_unit_index, to_unit_index;
    double value;

    num_units = 0;
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("liter", 1.0);
    add_unit("gallon", 3.78541);

    printf("Enter a conversion request (e.g. 5 meters to liters):\n");
    fgets(input, INPUT_SIZE, stdin);

    token = strtok(input, " ");
    if (token == NULL) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    value = atof(token);

    from_unit_index = get_unit_index(token);
    if (from_unit_index == -1) {
        printf("Error: Invalid unit.\n");
        return 1;
    }

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    to_unit_index = get_unit_index(token);
    if (to_unit_index == -1) {
        printf("Error: Invalid unit.\n");
        return 1;
    }

    printf("%.2f %s = %.2f %s\n", value, units[from_unit_index].name, convert(value, from_unit_index, to_unit_index), units[to_unit_index].name);

    return 0;
}