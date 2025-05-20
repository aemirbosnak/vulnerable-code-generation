//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to store periodic table data
typedef struct {
    int atomic_number;
    char *name;
    char *symbol;
    float atomic_weight;
} element_t;

// Array of periodic table elements
element_t elements[] = {
    { 1, "Hydrogen", "H", 1.00794 },
    { 2, "Helium", "He", 4.002602 },
    { 3, "Lithium", "Li", 6.941 },
    { 4, "Beryllium", "Be", 9.012182 },
    { 5, "Boron", "B", 10.811 },
    { 6, "Carbon", "C", 12.011 },
    { 7, "Nitrogen", "N", 14.007 },
    { 8, "Oxygen", "O", 15.9994 },
    { 9, "Fluorine", "F", 18.9984032 },
    { 10, "Neon", "Ne", 20.1797 }
};

// Number of elements in the periodic table
#define NUM_ELEMENTS (sizeof(elements) / sizeof(element_t))

// Thread function to print element data
void *print_element(void *arg) {
    // Get the element index from the argument
    int index = *(int *)arg;

    // Print the element data
    printf("Element %d: %s (%s, %.4f)\n", elements[index].atomic_number, elements[index].name, elements[index].symbol, elements[index].atomic_weight);

    // Free the allocated memory
    free(arg);

    return NULL;
}

int main() {
    // Create a thread for each element
    pthread_t threads[NUM_ELEMENTS];
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        // Allocate memory for the thread argument
        int *index = malloc(sizeof(int));
        *index = i;

        // Create the thread
        pthread_create(&threads[i], NULL, print_element, index);
    }

    // Join all threads
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}