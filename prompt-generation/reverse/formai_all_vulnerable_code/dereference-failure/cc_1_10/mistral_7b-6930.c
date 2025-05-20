//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 50
#define NUM_UNITS 10

typedef struct {
    char name[MAX_INPUT_SIZE];
    double conversion_factor;
} Unit;

Unit units[NUM_UNITS] = {
    {"Miles", 1609.34},
    {"Kilometers", 0.621371},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Fahrenheit", 0.555556},
    {"Celsius", 0.555556},
    {"Gallons", 3.78541},
    {"Liters", 0.264172},
    {"Degrees", 1},
    {"Radians", 0.01745329251}
};

void print_usage() {
    printf("Usage: %s <input> <unit> <output> <unit>\n", __FILE__);
    printf("Example: %s 10 Miles Kilometers\n", __FILE__);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        print_usage();
    }

    int input_index = -1;
    int output_index = -1;

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(argv[1], units[i].name) == 0) {
            input_index = i;
        }
        if (strcmp(argv[3], units[i].name) == 0) {
            output_index = i;
        }
    }

    if (input_index == -1 || output_index == -1) {
        print_usage();
    }

    double input = atof(argv[2]);
    double output = input * units[output_index].conversion_factor / units[input_index].conversion_factor;

    printf("%s %s is %s %s\n", argv[1], argv[2], argv[3], argv[4]);
    printf("%s %s is %s %s\n", argv[1], argv[2], argv[3], units[output_index].name);
    printf("%s %s is %g %s\n", argv[1], argv[2], output, argv[4]);

    return 0;
}