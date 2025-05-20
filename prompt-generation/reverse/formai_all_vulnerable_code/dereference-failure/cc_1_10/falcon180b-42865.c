//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100
#define MAX_CONVERSION_FACTOR 10

typedef struct {
    char* name;
    double conversion_factor;
} unit;

int main() {
    int num_units = 0;
    unit* units = malloc(MAX_UNITS * sizeof(unit));

    printf("Enter units and their conversion factors (type 'done' when finished):\n");
    while(1) {
        char input[100];
        fgets(input, 100, stdin);
        if(strcasecmp(input, "done") == 0) {
            break;
        }
        char* name = strtok(input, " ");
        double conversion_factor = strtod(strtok(NULL, " "), NULL);
        if(num_units >= MAX_UNITS) {
            printf("Error: too many units!\n");
            exit(1);
        }
        strcpy(units[num_units].name, name);
        units[num_units].conversion_factor = conversion_factor;
        num_units++;
    }

    printf("Enter a value and units to convert from and to:\n");
    char from_unit[100], to_unit[100];
    fgets(from_unit, 100, stdin);
    fgets(to_unit, 100, stdin);

    int from_unit_index = -1, to_unit_index = -1;
    for(int i = 0; i < num_units; i++) {
        if(strcasecmp(units[i].name, from_unit) == 0) {
            from_unit_index = i;
        } else if(strcasecmp(units[i].name, to_unit) == 0) {
            to_unit_index = i;
        }
    }

    if(from_unit_index == -1 || to_unit_index == -1) {
        printf("Error: invalid units!\n");
        exit(1);
    }

    double value = strtod(from_unit, NULL);
    double result = value * units[to_unit_index].conversion_factor;

    printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);

    return 0;
}