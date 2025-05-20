//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char *input_string;
    char *endptr;
    double temperature;
    char unit;
    char *result_string;
    int result_length;
    int i;

    // Prompt the user for input
    printf("Enter a temperature value followed by a unit (e.g. 32 F): ");
    fgets(input_buffer, MAX_LINE_LENGTH, stdin);

    // Remove the newline character from the input
    input_string = strtok(input_buffer, "\n");

    // Convert the input to a double and get the unit
    temperature = strtod(input_string, &endptr);
    unit = *endptr;

    // Convert the temperature to the other unit
    switch (unit) {
        case 'C':
            temperature = (temperature * 9/5) + 32;
            unit = 'F';
            break;
        case 'F':
            temperature = (temperature - 32) * 5/9;
            unit = 'C';
            break;
        default:
            printf("Invalid unit. Please enter C or F.\n");
            return 1;
    }

    // Format the result string
    result_length = snprintf(NULL, 0, "%.2f %c", temperature, unit);
    result_string = malloc(result_length + 1);
    snprintf(result_string, result_length + 1, "%.2f %c", temperature, unit);

    // Print the result
    printf("%.2f %c = %s\n", temperature, unit, result_string);
    free(result_string);

    return 0;
}