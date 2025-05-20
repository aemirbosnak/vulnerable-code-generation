//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char output[100];
    char unit_name[MAX_UNITS][20];
    int num_units;
    Unit units[MAX_UNITS];

    printf("Welcome to the Cheerful Unit Converter!\n");

    printf("Enter a value to convert: ");
    scanf("%s", input);

    printf("Enter the original unit (e.g. meters, seconds): ");
    scanf("%s", output);

    printf("Enter the unit you want to convert to (e.g. feet, minutes): ");
    scanf("%s", output);

    printf("Enter the conversion factor (e.g. 3.28084, 60): ");
    scanf("%lf", &units[0].factor);

    num_units = 1;

    while (num_units < MAX_UNITS) {
        printf("Enter another unit to convert to (or press enter to finish): ");
        scanf("%s", output);

        if (output[0]!= '\0') {
            strcpy(units[num_units].name, output);
            printf("Enter the conversion factor for %s: ", output);
            scanf("%lf", &units[num_units].factor);
            num_units++;
        } else {
            break;
        }
    }

    printf("Converting %s %s to various units:\n", input, output);

    for (int i = 0; i < num_units; i++) {
        printf("%s = %.2lf %s\n", input, units[i].factor * atof(output), units[i].name);
    }

    return 0;
}