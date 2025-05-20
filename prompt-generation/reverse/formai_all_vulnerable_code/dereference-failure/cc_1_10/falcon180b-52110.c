//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit;

int main() {
    int num_units;
    unit *units;
    char input[100];
    double value, result = 0;
    int i;

    // Initialize the units array
    units = (unit *)malloc(MAX_UNITS * sizeof(unit));
    if (units == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    num_units = 0;

    // Prompt the user to enter the number of units
    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    // Prompt the user to enter the unit names and factors
    for (i = 0; i < num_units; i++) {
        printf("Enter unit %d name: ", i+1);
        scanf("%s", input);
        strcpy(units[i].name, input);

        printf("Enter unit %d factor: ", i+1);
        scanf("%lf", &units[i].factor);
    }

    // Prompt the user to enter the value to convert
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    // Convert the value to all the units
    for (i = 0; i < num_units; i++) {
        result = value * units[i].factor;
        printf("%.2lf %s = %.2lf %s\n", value, units[i].name, result, units[i].name);
    }

    free(units);
    return 0;
}