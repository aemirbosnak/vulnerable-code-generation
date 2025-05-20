//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define PI 3.14159

typedef struct Unit
{
    char name[20];
    double value;
    struct Unit *next;
} Unit;

void convert_units(Unit *units)
{
    double result = 1.0;
    Unit *current = units;

    while (current)
    {
        switch (current->name[0])
        {
            case 'm':
                result *= current->value * 1000;
                break;
            case 'c':
                result *= current->value * 100;
                break;
            case 'g':
                result *= current->value * 1000;
                break;
            case 't':
                result *= current->value * 1000 * 1000;
                break;
            default:
                printf("Error: Invalid unit.\n");
                return;
        }
        current = current->next;
    }

    printf("The result is: %.2lf %s.\n", result, units->name);
}

int main()
{
    Unit *units = NULL;

    units = malloc(sizeof(Unit));
    units->name[0] = 'm';
    units->value = 10.0;
    units->next = NULL;

    units = malloc(sizeof(Unit));
    units->name[0] = 'c';
    units->value = 20.0;
    units->next = units;

    units = malloc(sizeof(Unit));
    units->name[0] = 'g';
    units->value = 30.0;
    units->next = units;

    convert_units(units);

    return 0;
}