//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

typedef struct {
    char *name;
    double (*convert)(double);
} unit_t;

double convert_inches_to_centimeters(double inches) {
    return inches * 2.54;
}

double convert_centimeters_to_inches(double centimeters) {
    return centimeters / 2.54;
}

double convert_pounds_to_kilograms(double pounds) {
    return pounds * 0.453592;
}

double convert_kilograms_to_pounds(double kilograms) {
    return kilograms / 0.453592;
}

double convert_fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

unit_t units[] = {
    {"inches", convert_inches_to_centimeters},
    {"centimeters", convert_centimeters_to_inches},
    {"pounds", convert_pounds_to_kilograms},
    {"kilograms", convert_kilograms_to_pounds},
    {"fahrenheit", convert_fahrenheit_to_celsius},
    {"celsius", convert_celsius_to_fahrenheit},
};

int main(int argc, char **argv) {
    char *input = NULL;
    size_t input_size = 0;
    getline(&input, &input_size, stdin);

    char *from_unit = strtok(input, " ");
    char *to_unit = strtok(NULL, " ");
    double value = atof(strtok(NULL, " "));

    unit_t *from_unit_ptr = NULL;
    unit_t *to_unit_ptr = NULL;

    for (int i = 0; i < sizeof(units) / sizeof(unit_t); i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_unit_ptr = &units[i];
        } else if (strcmp(units[i].name, to_unit) == 0) {
            to_unit_ptr = &units[i];
        }
    }

    if (from_unit_ptr == NULL || to_unit_ptr == NULL) {
        fprintf(stderr, "Invalid unit(s) specified.\n");
        exit(EXIT_FAILURE);
    }

    double converted_value = from_unit_ptr->convert(value);
    converted_value = to_unit_ptr->convert(converted_value);

    printf("%f %s\n", converted_value, to_unit);

    free(input);
    return EXIT_SUCCESS;
}