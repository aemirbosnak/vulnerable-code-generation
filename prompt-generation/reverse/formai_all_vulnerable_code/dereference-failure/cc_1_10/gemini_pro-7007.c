//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNITS 10

char *units[] = {"meters", "kilometers", "miles", "feet", "inches", "yards", "centimeters", "millimeters", "micrometers", "nanometers"};
double conversion_factors[] = {1, 1000, 1609.34, 0.3048, 0.0254, 0.9144, 0.01, 0.001, 0.000001, 0.000000001};

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <value> <from_unit> <to_unit>\n", argv[0]);
        printf("Available units: ");
        for (int i = 0; i < UNITS; i++)
        {
            printf("%s%s", units[i], (i == UNITS - 1) ? "\n" : ", ");
        }
        return 1;
    }

    double value = atof(argv[1]);
    char *from_unit = argv[2];
    char *to_unit = argv[3];

    int from_unit_index = -1;
    int to_unit_index = -1;

    for (int i = 0; i < UNITS; i++)
    {
        if (strcmp(from_unit, units[i]) == 0)
        {
            from_unit_index = i;
        }
        if (strcmp(to_unit, units[i]) == 0)
        {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1)
    {
        printf("Invalid unit specified.\n");
        return 1;
    }

    double converted_value = value * conversion_factors[from_unit_index] / conversion_factors[to_unit_index];

    printf("%f %s = %f %s\n", value, from_unit, converted_value, to_unit);

    return 0;
}