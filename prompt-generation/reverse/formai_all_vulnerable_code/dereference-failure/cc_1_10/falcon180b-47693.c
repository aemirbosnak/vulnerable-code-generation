//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118 // Maximum number of elements in the periodic table

// Structure to store element information
typedef struct {
    char symbol[3];
    char name;
    int atomic_number;
    float atomic_weight;
} Element;

// Function to generate a random element from the periodic table
Element get_random_element() {
    Element element;
    int random_index = rand() % MAX_ELEMENTS; // Generate a random index between 0 and MAX_ELEMENTS - 1

    switch (random_index) {
        case 0:
            strcpy(element.symbol, "H");
            strcpy(element.name, "Hydrogen");
            element.atomic_number = 1;
            element.atomic_weight = 1.008;
            break;
        case 1:
            strcpy(element.symbol, "He");
            strcpy(element.name, "Helium");
            element.atomic_number = 2;
            element.atomic_weight = 4.003;
            break;
        // Add more cases for each element in the periodic table
    }

    return element;
}

// Function to print the periodic table
void print_periodic_table() {
    printf("+----+----------------+--------+--------------------+\n");
    printf("| #  | Symbol          | Name   | Atomic Weight     |\n");
    printf("+----+----------------+--------+--------------------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        Element element = get_random_element();
        printf("| %2d | %-3s | %-14s | %-10.2f |\n", i+1, element.symbol, element.name, element.atomic_weight);
    }

    printf("+----+----------------+--------+--------------------+\n");
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    print_periodic_table();

    return 0;
}