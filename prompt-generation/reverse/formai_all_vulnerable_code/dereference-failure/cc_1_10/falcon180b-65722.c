//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char* name;
    double factor;
} Unit;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        return 1;
    }

    double value = strtod(argv[1], NULL);
    char* from_unit = argv[2];
    char* to_unit = argv[3];

    Unit* units = calloc(sizeof(Unit), 9);
    units[0].name = "meter";
    units[0].factor = 1.0;
    units[1].name = "kilogram";
    units[1].factor = 1.0;
    units[2].name = "second";
    units[2].factor = 1.0;
    units[3].name = "ampere";
    units[3].factor = 1.0;
    units[4].name = "kelvin";
    units[4].factor = 1.0;
    units[5].name = "mole";
    units[5].factor = 1.0;
    units[6].name = "candela";
    units[6].factor = 1.0;
    units[7].name = "radian";
    units[7].factor = 1.0;
    units[8].name = "steradian";
    units[8].factor = 1.0;

    for (int i = 0; i < 9; i++) {
        if (!strcmp(from_unit, units[i].name)) {
            for (int j = 0; j < 9; j++) {
                if (!strcmp(to_unit, units[j].name)) {
                    value *= units[i].factor / units[j].factor;
                    printf("%.3f %s = %.3f %s\n", value, units[j].name, value, units[i].name);
                    return 0;
                }
            }
        }
    }

    printf("Invalid units\n");
    return 1;
}