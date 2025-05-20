//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 1000

typedef struct {
    char *name;
    double factor;
} Unit;

int main(int argc, char *argv[]) {
    int num_units;
    char input[100];
    char *token;
    Unit *units = malloc(MAX_UNITS * sizeof(Unit));
    int i = 0;

    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    while (i < num_units) {
        printf("Enter unit name: ");
        scanf("%s", input);
        units[i].name = strdup(input);
        printf("Enter unit factor: ");
        scanf("%lf", &units[i].factor);
        i++;
    }

    printf("Enter the value to convert: ");
    scanf("%s", input);
    token = strtok(input, " ");

    while (token!= NULL) {
        int j;
        for (j = 0; j < num_units; j++) {
            if (strcmp(token, units[j].name) == 0) {
                printf("%s = %.2lf %s\n", input, units[j].factor * atof(strtok(NULL, " ")), units[j].name);
                break;
            }
        }
        if (j == num_units) {
            printf("Invalid unit: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    free(units);
    return 0;
}