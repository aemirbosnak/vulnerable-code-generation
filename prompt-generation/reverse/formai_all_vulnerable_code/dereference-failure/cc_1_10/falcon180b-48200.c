//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    num_units++;
}

int main() {
    add_unit("Kilometers", 1000);
    add_unit("Meters", 1);
    add_unit("Centimeters", 0.01);
    add_unit("Millimeters", 0.001);
    add_unit("Inches", 0.0254);
    add_unit("Feet", 0.3048);
    add_unit("Yards", 0.9144);
    add_unit("Miles", 160934.4);

    int choice;
    double value, result;

    do {
        printf("\n");
        printf("1. Kilometers to other units\n");
        printf("2. Other units to kilometers\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit: ");
            scanf("%s", units[0].name);

            for (int i = 1; i < num_units; i++) {
                result = value / units[0].factor * units[i].factor;
                printf("%s = %.2lf\n", units[i].name, result);
            }
            break;

        case 2:
            printf("Enter value: ");
            scanf("%lf", &value);
            printf("Enter unit: ");
            scanf("%s", units[0].name);

            for (int i = 1; i < num_units; i++) {
                result = value / units[i].factor * units[0].factor;
                printf("%s = %.2lf\n", units[i].name, result);
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}