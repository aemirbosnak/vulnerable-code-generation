//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char *name;
    double value;
} conversion_t;

static conversion_t conversions[MAX_UNITS][MAX_CONVERSIONS];

int main() {
    int i, j;
    char input[100];
    double value;

    // Initialize conversions
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            conversions[i][j].name = NULL;
            conversions[i][j].value = 0.0;
        }
    }

    // Parse user input
    printf("Enter a value and a unit of measurement (e.g. 5 apples or 2.5 kg): ");
    fgets(input, 100, stdin);

    // Split input into value and unit
    char *ptr = strtok(input, " ");
    value = atof(ptr);
    ptr = strtok(NULL, " ");
    char *unit = ptr;

    // Look up conversions
    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(unit, conversions[i][j].name) == 0) {
                value *= conversions[i][j].value;
                break;
            }
        }
    }

    // Print result
    printf("The value of %s is %g\n", unit, value);

    return 0;
}

// Function to add a conversion
void add_conversion(char *name, double value) {
    int i, j;

    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            if (strcmp(name, conversions[i][j].name) == 0) {
                conversions[i][j].value = value;
                break;
            }
        }
        if (j == MAX_CONVERSIONS) {
            // Add a new conversion
            conversions[i][j].name = name;
            conversions[i][j].value = value;
            break;
        }
    }
}

// Function to print all conversions
void print_conversions() {
    int i, j;

    for (i = 0; i < MAX_UNITS; i++) {
        for (j = 0; j < MAX_CONVERSIONS; j++) {
            printf("%s: %g\n", conversions[i][j].name, conversions[i][j].value);
        }
    }
}