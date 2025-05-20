//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100

struct unit {
    char *name;
    double factor;
};

struct unit *units[MAX_UNITS];
int num_units;

void add_unit(const char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    struct unit *u = malloc(sizeof(struct unit));
    u->name = strdup(name);
    u->factor = factor;
    units[num_units++] = u;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i]->name);
    }
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("millimeter", 0.001);

    print_units();

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *value_str = strtok(input, " ");
        char *unit_str = strtok(NULL, " ");

        struct unit *u = NULL;
        for (int i = 0; i < num_units; i++) {
            if (strcmp(units[i]->name, unit_str) == 0) {
                u = units[i];
                break;
            }
        }

        if (u == NULL) {
            printf("Error: Invalid unit '%s'.\n", unit_str);
            continue;
        }

        double value = strtod(value_str, NULL);
        double result = value * u->factor;

        printf("%.2f %s = %.2f %s\n", value, unit_str, result, u->name);
    }

    return 0;
}