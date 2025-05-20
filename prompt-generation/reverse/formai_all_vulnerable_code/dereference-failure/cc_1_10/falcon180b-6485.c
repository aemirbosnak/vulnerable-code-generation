//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

int main() {
    char input_line[MAX_LINE_SIZE];
    char *token;
    double temperature;
    char input_unit[10];
    char output_unit[10];
    int valid_input = 0;

    printf("Enter temperature value and units (e.g. 100 C): ");
    fgets(input_line, MAX_LINE_SIZE, stdin);
    strtok(input_line, " ");
    strcpy(input_unit, strtok(NULL, " "));
    strcpy(output_unit, "");

    if (strcmp(input_unit, "C") == 0) {
        strcpy(output_unit, "F");
    } else if (strcmp(input_unit, "F") == 0) {
        strcpy(output_unit, "C");
    } else {
        printf("Invalid input unit.\n");
        return 1;
    }

    temperature = strtod(strtok(NULL, " "), NULL);

    if (temperature >= -273.15 && temperature <= 1000) {
        valid_input = 1;
    } else {
        printf("Invalid temperature value.\n");
        return 1;
    }

    if (strcmp(input_unit, "C") == 0) {
        temperature = (temperature * 9/5) + 32;
        strcpy(output_unit, "F");
    } else if (strcmp(input_unit, "F") == 0) {
        temperature = (temperature - 32) * 5/9;
        strcpy(output_unit, "C");
    }

    printf("%.2lf %s = %.2lf %s\n", temperature, input_unit, temperature, output_unit);

    return 0;
}