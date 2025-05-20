//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_LINE 1000

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to handle input errors
void input_error(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

// Function to read a line of input from stdin
char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }
    }

    return line;
}

// Function to convert temperature using user-specified units
double convert_temperature(double temp, const char* from_unit, const char* to_unit) {
    if (strcmp(from_unit, "C") == 0 && strcmp(to_unit, "F") == 0) {
        return celsius_to_fahrenheit(temp);
    }
    else if (strcmp(from_unit, "F") == 0 && strcmp(to_unit, "C") == 0) {
        return fahrenheit_to_celsius(temp);
    }

    input_error("Invalid temperature units");
    return 0.0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        input_error("Usage:./temp_converter <temperature> <from_unit> <to_unit>");
    }

    double temp = strtod(argv[1], NULL);
    const char* from_unit = argv[2];
    const char* to_unit = argv[3];

    double result = convert_temperature(temp, from_unit, to_unit);

    printf("%.2f %s = %.2f %s\n", temp, from_unit, result, to_unit);

    return 0;
}