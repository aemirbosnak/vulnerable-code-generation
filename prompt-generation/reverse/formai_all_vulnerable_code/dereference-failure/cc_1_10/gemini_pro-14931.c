//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to represent an element in the periodic table
typedef struct {
    char *name;
    char *symbol;
    int atomic_number;
    double atomic_weight;
} element;

// Create an array of elements
element elements[] = {
    {"Hydrogen", "H", 1, 1.00794},
    {"Helium", "He", 2, 4.002602},
    {"Lithium", "Li", 3, 6.941},
    {"Beryllium", "Be", 4, 9.012182},
    {"Boron", "B", 5, 10.811},
    {"Carbon", "C", 6, 12.0107},
    {"Nitrogen", "N", 7, 14.0067},
    {"Oxygen", "O", 8, 15.9994},
    {"Fluorine", "F", 9, 18.9984032},
    {"Neon", "Ne", 10, 20.1797}
};

// Get the number of elements in the array
int num_elements = sizeof(elements) / sizeof(elements[0]);

// Create a function to print the periodic table
void print_periodic_table() {
    // Print the header
    printf("Periodic Table\n");
    printf("===================================================================================\n");
    printf("Name\tSymbol\tAtomic Number\tAtomic Weight\n");
    printf("-----------------------------------------------------------------------------------\n");

    // Print each element in the table
    for (int i = 0; i < num_elements; i++) {
        printf("%s\t%s\t%d\t\t%.4f\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_weight);
    }
}

// Get the user's input
char *get_user_input(char *prompt) {
    char *input = NULL;
    size_t len = 0;

    printf("%s", prompt);
    getline(&input, &len, stdin);

    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    return input;
}

// Main function
int main() {
    // Print the periodic table
    print_periodic_table();

    // Get the user's input
    char *element_name = get_user_input("Enter the name of an element: ");

    // Find the element in the array
    int index = -1;
    for (int i = 0; i < num_elements; i++) {
        if (strcmp(element_name, elements[i].name) == 0) {
            index = i;
            break;
        }
    }

    // Print the element's information
    if (index != -1) {
        printf("Element Name: %s\n", elements[index].name);
        printf("Symbol: %s\n", elements[index].symbol);
        printf("Atomic Number: %d\n", elements[index].atomic_number);
        printf("Atomic Weight: %.4f\n", elements[index].atomic_weight);
    } else {
        printf("Element not found!\n");
    }

    // Free the memory allocated for the user's input
    free(element_name);

    return 0;
}