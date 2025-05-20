//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    float value;
    int base;
} Unit;

void convert(Unit from, Unit to, float value) {
    float conversionFactor = 1.0;

    if (from.base == 2 && to.base == 10) {
        conversionFactor = pow(2, (log10f(value) / log10f(2)));
    } else if (from.base == 10 && to.base == 2) {
        conversionFactor = pow(2, (log10f(value) * log10f(10) / log10f(2)));
    } else if (from.base == 10 && to.base == 10) {
        conversionFactor = 1.0;
    } else {
        printf("Error: Unsupported unit conversion from %s to %s.\n", from.name, to.name);
        exit(1);
    }

    to.value = value * conversionFactor;
}

Unit parseUnit(char* str) {
    Unit unit = {"", 0, 0};
    int i, j = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            break;
        }
        if (i == 0) {
            for (j = 0; j < 20 && str[i + j + 1] != ' ' && str[i + j + 1] != '\0'; j++) {
                unit.name[j] = str[i + j];
            }
            unit.name[j] = '\0';
        }
        if (str[i] >= '0' && str[i] <= '9') {
            unit.base = 10;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            unit.base = 2;
        }
    }

    return unit;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <from_unit> <value> <to_unit>\n", argv[0]);
        return 1;
    }

    Unit from = parseUnit(argv[1]);
    float value = atof(argv[2]);
    Unit to = parseUnit(argv[3]);

    if (from.value == 0 || to.value == 0) {
        printf("Error: Invalid unit %s or %s.\n", from.name, to.name);
        return 1;
    }

    convert(from, to, value);
    printf("%.2f %s = %.2f %s\n", value, from.name, to.value, to.name);

    return 0;
}