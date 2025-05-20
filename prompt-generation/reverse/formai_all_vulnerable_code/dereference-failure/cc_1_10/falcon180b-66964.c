//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VALUES 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    char *value;
} key_value_pair;

int main() {
    int num_values = 0;
    key_value_pair values[MAX_VALUES];
    char input_buffer[MAX_STRING_LENGTH];
    char *name, *value;
    char delimiter = '=';

    printf("Welcome to the C Browser Plugin Example Program!\n");
    printf("This program will demonstrate how to parse and manipulate data in a browser plugin.\n");

    // Read in input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Parse input file
    while (fgets(input_buffer, MAX_STRING_LENGTH, input_file)!= NULL) {
        name = strtok(input_buffer, &delimiter);
        value = strtok(NULL, &delimiter);

        // Add key-value pair to array
        values[num_values].name = strdup(name);
        values[num_values].value = strdup(value);
        num_values++;
    }

    fclose(input_file);

    // Manipulate data
    for (int i = 0; i < num_values; i++) {
        printf("Name: %s\n", values[i].name);
        printf("Value: %s\n\n", values[i].value);
    }

    // Free memory
    for (int i = 0; i < num_values; i++) {
        free(values[i].name);
        free(values[i].value);
    }

    return 0;
}