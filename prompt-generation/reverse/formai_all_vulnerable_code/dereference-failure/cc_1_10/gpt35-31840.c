//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of element names and symbols
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 3

// Define the maximum number of elements in the periodic table
#define MAX_NUM_ELEMENTS 118

// Define a struct for an element
typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomic_number;
} element;

// Define a function to create a new element
element* create_element(char* name, char* symbol, int atomic_number) {
    element* new_element = malloc(sizeof(element));
    strcpy(new_element->name, name);
    strcpy(new_element->symbol, symbol);
    new_element->atomic_number = atomic_number;
    return new_element;
}

// Define the periodic table as a global array of element pointers
element* periodic_table[MAX_NUM_ELEMENTS];

// Define a function to add an element to the periodic table
void add_element_to_periodic_table(element* new_element) {
    periodic_table[new_element->atomic_number - 1] = new_element;
}

// Define a function to print an element
void print_element(element* elem) {
    printf("%d. %s (%s)\n", elem->atomic_number, elem->symbol, elem->name);
}

// Define the main function
int main() {
    // Create some elements
    element* hydrogen = create_element("Hydrogen", "H", 1);
    element* helium = create_element("Helium", "He", 2);
    element* lithium = create_element("Lithium", "Li", 3);
    element* beryllium = create_element("Beryllium", "Be", 4);
    
    // Add the elements to the periodic table
    add_element_to_periodic_table(hydrogen);
    add_element_to_periodic_table(helium);
    add_element_to_periodic_table(lithium);
    add_element_to_periodic_table(beryllium);
    
    // Print all elements in the periodic table
    printf("Periodic Table:\n");
    for (int i = 0; i < MAX_NUM_ELEMENTS; i++) {
        if (periodic_table[i] != NULL) {
            print_element(periodic_table[i]);
        }
    }
    
    // Free memory used by the elements
    free(hydrogen);
    free(helium);
    free(lithium);
    free(beryllium);
    
    return 0;
}