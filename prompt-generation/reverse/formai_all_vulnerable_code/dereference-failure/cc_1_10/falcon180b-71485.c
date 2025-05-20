//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char *convert_temperature(char *temperature_str, char *unit) {
    double temperature = 0;
    char *endptr = NULL;
    char *result_str = NULL;

    if (strcasecmp(unit, "c") == 0) {
        temperature = strtod(temperature_str, &endptr);
        if (endptr == NULL || *endptr!= '\0') {
            printf("Invalid input: %s\n", temperature_str);
            return NULL;
        }
        result_str = malloc(MAX_LENGTH);
        sprintf(result_str, "%.2f°C", temperature + 273.15);
    } else if (strcasecmp(unit, "f") == 0) {
        temperature = strtod(temperature_str, &endptr);
        if (endptr == NULL || *endptr!= '\0') {
            printf("Invalid input: %s\n", temperature_str);
            return NULL;
        }
        result_str = malloc(MAX_LENGTH);
        sprintf(result_str, "%.2f°F", temperature * 9 / 5 + 32);
    } else {
        printf("Invalid unit: %s\n", unit);
        return NULL;
    }

    return result_str;
}

int main() {
    char input_buffer[MAX_LENGTH];
    char unit_buffer[MAX_LENGTH];
    char *result = NULL;

    printf("Enter temperature and unit (e.g. 25 C): ");
    fgets(input_buffer, MAX_LENGTH, stdin);
    strtok(input_buffer, " ");
    strcpy(unit_buffer, strtok(NULL, " "));

    result = convert_temperature(input_buffer, unit_buffer);

    if (result!= NULL) {
        printf("Result: %s\n", result);
        free(result);
    }

    return 0;
}