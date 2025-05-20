//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100

struct unit {
    char *name;
    double factor;
};

int main() {
    struct unit units[MAX_UNITS];
    int num_units = 0;
    char input[100];
    char *token;
    double value, result;
    int i;

    printf("Enter units and their conversion factors (e.g. meter 2.54 cm)\n");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, "\n");
    while (token!= NULL) {
        if (num_units >= MAX_UNITS) {
            printf("Maximum number of units exceeded.\n");
            exit(1);
        }
        units[num_units].name = strdup(token);
        units[num_units].factor = 1.0;
        num_units++;
        token = strtok(NULL, "\n");
    }

    printf("Enter a value to convert:\n");
    fgets(input, sizeof(input), stdin);
    value = atof(input);

    printf("Enter the unit to convert from:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    for (i = 0; i < num_units; i++) {
        if (strcmp(token, units[i].name) == 0) {
            break;
        }
    }
    if (i == num_units) {
        printf("Invalid unit.\n");
        exit(1);
    }

    printf("Enter the unit to convert to:\n");
    fgets(input, sizeof(input), stdin);
    token = strtok(input, " ");
    for (i = 0; i < num_units; i++) {
        if (strcmp(token, units[i].name) == 0) {
            result = value * units[i].factor;
            break;
        }
    }
    if (i == num_units) {
        printf("Invalid unit.\n");
        exit(1);
    }

    printf("%.2f %s = %.2f %s\n", value, units[i].name, result, token);

    return 0;
}