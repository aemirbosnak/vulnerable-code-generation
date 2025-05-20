//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 100

typedef struct {
    char name[MAX_UNITS];
    double conversion_factor;
} unit;

typedef struct {
    char input_unit[MAX_UNITS];
    char output_unit[MAX_UNITS];
    double value;
} conversion;

int main() {
    char input_buffer[MAX_UNITS];
    char *token;
    int num_units;
    unit *units;
    conversion *conversions;
    int num_conversions;
    int i, j;

    // read in units and their conversion factors
    num_units = 0;
    units = malloc(sizeof(unit) * MAX_UNITS);
    while (fgets(input_buffer, MAX_UNITS, stdin)!= NULL) {
        if (num_units >= MAX_UNITS) {
            printf("Error: too many units.\n");
            exit(1);
        }
        token = strtok(input_buffer, " ");
        strcpy(units[num_units].name, token);
        units[num_units].conversion_factor = strtod(strtok(NULL, " "), NULL);
        num_units++;
    }

    // read in conversions
    num_conversions = 0;
    conversions = malloc(sizeof(conversion) * MAX_CONVERSIONS);
    while (fgets(input_buffer, MAX_UNITS, stdin)!= NULL) {
        if (num_conversions >= MAX_CONVERSIONS) {
            printf("Error: too many conversions.\n");
            exit(1);
        }
        token = strtok(input_buffer, " ");
        strcpy(conversions[num_conversions].input_unit, token);
        token = strtok(NULL, " ");
        strcpy(conversions[num_conversions].output_unit, token);
        conversions[num_conversions].value = strtod(strtok(NULL, " "), NULL);
        num_conversions++;
    }

    // perform conversions
    for (i = 0; i < num_conversions; i++) {
        for (j = 0; j < num_units; j++) {
            if (strcmp(conversions[i].input_unit, units[j].name) == 0) {
                conversions[i].value *= units[j].conversion_factor;
                break;
            }
        }
        if (j == num_units) {
            printf("Error: unknown input unit.\n");
            exit(1);
        }
    }

    // print results
    for (i = 0; i < num_conversions; i++) {
        printf("%s %s = %.2f\n", conversions[i].input_unit, conversions[i].output_unit, conversions[i].value);
    }

    return 0;
}