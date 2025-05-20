//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the element struct
typedef struct {
    char *name;
    char *symbol;
    int atomic_number;
    float atomic_mass;
} element;

// Define the periodic table array
element periodic_table[NUM_ELEMENTS];

// Read the periodic table data from a file
void read_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (!file) {
        perror("Error opening periodic table file");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        float atomic_mass = atof(strtok(NULL, ","));

        element element = {name, symbol, atomic_number, atomic_mass};
        periodic_table[atomic_number - 1] = element;
    }

    fclose(file);
}

// Print the periodic table
void print_periodic_table() {
    printf("Periodic Table\n");
    printf("===================================================================================================================\n");
    printf("| Atomic | Symbol | Name | Atomic Mass |\n");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element element = periodic_table[i];
        printf("| %6d | %6s | %12s | %12.2f |\n", element.atomic_number, element.symbol, element.name, element.atomic_mass);
    }
    printf("===================================================================================================================\n");
}

// Search for an element by name
element *search_element_by_name(char *name) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element element = periodic_table[i];
        if (strcmp(element.name, name) == 0) {
            return &element;
        }
    }

    return NULL;
}

// Search for an element by symbol
element *search_element_by_symbol(char *symbol) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        element element = periodic_table[i];
        if (strcmp(element.symbol, symbol) == 0) {
            return &element;
        }
    }

    return NULL;
}

// Search for an element by atomic number
element *search_element_by_atomic_number(int atomic_number) {
    if (atomic_number < 1 || atomic_number > NUM_ELEMENTS) {
        return NULL;
    }

    return &periodic_table[atomic_number - 1];
}

// Main function
int main() {
    // Read the periodic table data from a file
    read_periodic_table();

    // Print the periodic table
    print_periodic_table();

    // Search for an element by name
    char *name = "Hydrogen";
    element *element = search_element_by_name(name);
    if (element) {
        printf("Found element by name: %s\n", element->name);
    } else {
        printf("Element not found by name: %s\n", name);
    }

    // Search for an element by symbol
    char *symbol = "H";
    element = search_element_by_symbol(symbol);
    if (element) {
        printf("Found element by symbol: %s\n", element->symbol);
    } else {
        printf("Element not found by symbol: %s\n", symbol);
    }

    // Search for an element by atomic number
    int atomic_number = 1;
    element = search_element_by_atomic_number(atomic_number);
    if (element) {
        printf("Found element by atomic number: %d\n", element->atomic_number);
    } else {
        printf("Element not found by atomic number: %d\n", atomic_number);
    }

    return 0;
}