//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units;
    Unit units[MAX_UNITS];
    char input[100];

    printf("Welcome to the Unit Converter!\n");
    printf("How many units do you want to convert? (1-10): ");
    scanf("%d", &num_units);

    for (int i = 0; i < num_units; i++) {
        printf("Enter unit name %d: ", i+1);
        scanf("%s", input);
        strcpy(units[i].name, input);
        printf("Enter conversion factor for %s: ", input);
        scanf("%lf", &units[i].factor);
    }

    char from_unit[100];
    char to_unit[100];

    while (1) {
        printf("\nEnter a value to convert (or type 'exit' to quit):\n");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        printf("Enter the unit you want to convert from: ");
        scanf("%s", from_unit);

        printf("Enter the unit you want to convert to: ");
        scanf("%s", to_unit);

        for (int i = 0; i < num_units; i++) {
            if (strcmp(from_unit, units[i].name) == 0) {
                for (int j = 0; j < num_units; j++) {
                    if (strcmp(to_unit, units[j].name) == 0) {
                        printf("\n%s = %.2lf %s\n", input, (double)atof(input) * units[i].factor / units[j].factor, to_unit);
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}