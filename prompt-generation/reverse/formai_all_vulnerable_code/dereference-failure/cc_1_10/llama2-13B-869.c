//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_LENGTH 1024
#define UNIT_CONVERTER_DEFAULT_UNIT "cm"

typedef struct {
    char name[UNIT_CONVERTER_MAX_LENGTH];
    double factor;
} unit_t;

static unit_t units[] = {
    {"cm", 1.0},
    {"m", 100.0},
    {"km", 100000.0},
    {"mm", 0.01},
    {"in", 2.54},
    {"ft", 12.0},
    {"yd", 36.0},
    {"mi", 1609.344},
    {"pt", 0.03527396},
    {"wd", 0.02828535},
    {"g", 0.001},
    {"kg", 1000.0},
    {"oz", 0.0283495},
    {"lb", 0.45359237},
    {"ton", 1000000.0}
};

int main() {
    char input[UNIT_CONVERTER_MAX_LENGTH];
    char output[UNIT_CONVERTER_MAX_LENGTH];
    double value;
    int i;

    printf("Enter a value and a unit (e.g. '5 cm' or '3 ft 4 in'): ");
    fgets(input, UNIT_CONVERTER_MAX_LENGTH, stdin);

    // Tokenize the input
    char *token = strtok(input, " ");
    int token_count = 0;

    // Find the unit in the array
    for (i = 0; i < sizeof(units) / sizeof(units[0]); i++) {
        if (strcmp(token, units[i].name) == 0) {
            break;
        }
    }

    // Check if the unit is valid
    if (i == sizeof(units) / sizeof(units[0])) {
        printf("Invalid unit\n");
        return 1;
    }

    // Get the value in the input unit
    value = atof(token);

    // Convert the value to the default unit
    value *= units[i].factor;

    // Format the output
    snprintf(output, UNIT_CONVERTER_MAX_LENGTH, "%.2f %s", value, units[i].name);

    // Print the output
    printf("%s\n", output);

    return 0;
}