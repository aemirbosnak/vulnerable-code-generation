//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_UNITS 20

struct unit {
    char *name;
    double factor;
};

struct unit units[MAX_UNITS];
int num_units;

double convert(double value, int from_unit, int to_unit) {
    return value * units[from_unit].factor / units[to_unit].factor;
}

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }
    strcpy(units[num_units].name, name);
    units[num_units].factor = factor;
    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int main() {
    srand(time(0));
    num_units = 0;
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("millimeter", 0.001);
    add_unit("inch", 0.0254);
    add_unit("foot", 0.3048);
    add_unit("yard", 0.9144);
    add_unit("mile", 160934.4);
    add_unit("liter", 1.0);
    add_unit("milliliter", 0.001);
    add_unit("gallon", 3.78541);
    add_unit("ounce", 0.0295735);
    add_unit("pound", 0.453592);
    add_unit("gram", 0.001);
    add_unit("kilogram", 1000.0);
    add_unit("ton", 907.185);
    add_unit("fahrenheit", 1.0);
    add_unit("celsius", 0.555555);
    add_unit("kelvin", 0.555555);
    print_units();
    int choice1, choice2;
    printf("Enter the number of the unit you want to convert from: ");
    scanf("%d", &choice1);
    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &choice2);
    double value, result;
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);
    result = convert(value, choice1-1, choice2-1);
    printf("%.2lf %s = %.2lf %s\n", value, units[choice1-1].name, result, units[choice2-1].name);
    return 0;
}