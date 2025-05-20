//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the structure of an element
typedef struct {
    int atomic_number;
    char *name;
    char *symbol;
    float atomic_mass;
    int group;
    int period;
    char *category;
} element;

// Create an array of elements
element elements[NUM_ELEMENTS];

// Initialize the elements array with data from a CSV file
void initialize_elements() {
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line and store the data in the elements array
        char *fields[7];
        int num_fields = 0;
        char *field = strtok(line, ",");
        while (field) {
            fields[num_fields++] = field;
            field = strtok(NULL, ",");
        }

        element *e = &elements[atoi(fields[0]) - 1];
        e->atomic_number = atoi(fields[0]);
        e->name = strdup(fields[1]);
        e->symbol = strdup(fields[2]);
        e->atomic_mass = atof(fields[3]);
        e->group = atoi(fields[4]);
        e->period = atoi(fields[5]);
        e->category = strdup(fields[6]);
    }

    fclose(fp);
}

// Print the periodic table
void print_periodic_table() {
    // Print the header
    printf("Atomic Number | Name | Symbol | Atomic Mass | Group | Period | Category\n");
    printf("--------------+------+--------+-------------+------+--------+---------\n");

    // Print the elements
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element *e = &elements[i];
        printf("%-14d | %-6s | %-6s | %-12.2f | %-6d | %-7d | %-8s\n",
            e->atomic_number, e->name, e->symbol, e->atomic_mass, e->group, e->period, e->category);
    }
}

// Get the element by atomic number
element *get_element_by_atomic_number(int atomic_number) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element *e = &elements[i];
        if (e->atomic_number == atomic_number) {
            return e;
        }
    }

    return NULL;
}

// Get the element by name
element *get_element_by_name(char *name) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element *e = &elements[i];
        if (strcmp(e->name, name) == 0) {
            return e;
        }
    }

    return NULL;
}

// Get the element by symbol
element *get_element_by_symbol(char *symbol) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element *e = &elements[i];
        if (strcmp(e->symbol, symbol) == 0) {
            return e;
        }
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the elements array
    initialize_elements();

    // Print the periodic table
    print_periodic_table();

    // Get the element by atomic number
    element *e = get_element_by_atomic_number(1);
    printf("Element with atomic number 1: %s\n", e->name);

    // Get the element by name
    e = get_element_by_name("Hydrogen");
    printf("Element with name Hydrogen: %s\n", e->symbol);

    // Get the element by symbol
    e = get_element_by_symbol("H");
    printf("Element with symbol H: %s\n", e->name);

    return 0;
}