//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 20

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units = 0;
    Unit units[MAX_UNITS];
    char input_buffer[100];
    char unit_name[100];
    double value, result;
    int i;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the name of the unit you would like to convert from:\n");
    fgets(input_buffer, 100, stdin);
    strtok(input_buffer, "\n"); // Remove newline character
    strcpy(unit_name, input_buffer);

    printf("Please enter the value you would like to convert:\n");
    fgets(input_buffer, 100, stdin);
    strtok(input_buffer, "\n"); // Remove newline character
    value = atof(input_buffer);

    printf("Please enter the name of the unit you would like to convert to:\n");
    fgets(input_buffer, 100, stdin);
    strtok(input_buffer, "\n"); // Remove newline character
    strcpy(unit_name, input_buffer);

    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            num_units++;
            break;
        }
    }

    if (num_units == 0) {
        printf("Invalid unit. Please try again.\n");
        return 0;
    }

    printf("Please enter the value of 1 %s in terms of the unit you are converting from:\n", unit_name);
    fgets(input_buffer, 100, stdin);
    strtok(input_buffer, "\n"); // Remove newline character
    value = atof(input_buffer);

    for (i = 0; i < num_units; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            result = value * units[i].factor;
            printf("%.2f %s = %.2f %s\n", value, unit_name, result, units[i].name);
            break;
        }
    }

    return 0;
}