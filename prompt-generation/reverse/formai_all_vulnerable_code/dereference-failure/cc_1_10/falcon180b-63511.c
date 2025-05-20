//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    char *token;

    // Initialize default units
    units[num_units].name = "meters";
    units[num_units].factor = 1.0;
    num_units++;

    while (num_units < MAX_UNITS) {
        printf("Enter the name of a unit (or press enter to finish): ");
        fgets(input, sizeof(input), stdin);

        if (strlen(input) > 0) {
            token = strtok(input, "\n");
            strcpy(units[num_units].name, token);

            printf("Enter the conversion factor for %s (or press enter to use 1.0): ", units[num_units].name);
            fgets(input, sizeof(input), stdin);

            if (strlen(input) > 0) {
                units[num_units].factor = atof(input);
            } else {
                units[num_units].factor = 1.0;
            }

            num_units++;
        }
    }

    printf("\nEnter a value to convert:\n");
    fgets(input, sizeof(input), stdin);

    double value = atof(input);
    char from_unit[20];
    char to_unit[20];

    printf("Enter the unit to convert from: ");
    fgets(from_unit, sizeof(from_unit), stdin);

    printf("Enter the unit to convert to: ");
    fgets(to_unit, sizeof(to_unit), stdin);

    int from_index = -1;
    int to_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        }

        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Invalid units.\n");
        return 1;
    }

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}