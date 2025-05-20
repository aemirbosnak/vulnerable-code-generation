//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    double factor;
} Unit;

Unit units[] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.001},
    {"Pounds", 4.5359237},
    {"Kilograms", 0.00220462},
    {"Ounces", 0.0352739619},
    {"Grams", 35.2739619},
    {"Degrees Fahrenheit", 0.016666667},
    {"Degrees Celsius", 0.018},
    {"Gallons", 3.7854118},
    {"Liters", 0.00264172}
};

int get_index(char *name) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }

    printf("Invalid unit name.\n");
    exit(1);
}

void convert(Unit from, Unit to, double value) {
    printf("%.2lf %s is equal to %.2lf %s\n", value * from.factor, from.name, value * from.factor / to.factor, to.name);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        exit(1);
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[4];

    int from_index = get_index(from_unit);
    int to_index = get_index(to_unit);

    Unit from = units[from_index];
    Unit to = units[to_index];

    convert(from, to, value);

    return 0;
}