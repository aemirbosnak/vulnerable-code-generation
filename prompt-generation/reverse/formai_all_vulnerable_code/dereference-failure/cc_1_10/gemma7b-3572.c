//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
#define MAX_ELEMENTS 118

typedef struct Element {
    char name[20];
    int atomic_number;
    int atomic_mass;
    char symbol[2];
    struct Element* next;
} Element;

// Create the periodic table
Element* create_periodic_table() {
    Element* head = malloc(sizeof(Element));
    head->name[0] = '\0';
    head->atomic_number = 0;
    head->atomic_mass = 0;
    head->symbol[0] = '\0';
    head->next = NULL;

    return head;
}

// Insert an element into the periodic table
void insert_element(Element* head, char* name, int atomic_number, int atomic_mass, char* symbol) {
    Element* new_element = malloc(sizeof(Element));
    new_element->name[0] = '\0';
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->symbol[0] = '\0';
    new_element->next = NULL;

    if (head->name[0] == '\0') {
        head = new_element;
    } else {
        Element* current_element = head;
        while (current_element->next) {
            current_element = current_element->next;
        }
        current_element->next = new_element;
    }
}

// Print the periodic table
void print_periodic_table(Element* head) {
    Element* current_element = head;
    printf("------------------------------------------------------------\n");
    printf("  #   Name   Atomic Number   Atomic Mass  Symbol\n");
    printf("------------------------------------------------------------\n");
    while (current_element) {
        printf("  %-2d  %-15s  %-13d  %-10d  %-2s\n", current_element->atomic_number, current_element->name, current_element->atomic_mass, current_element->symbol);
        current_element = current_element->next;
    }
    printf("------------------------------------------------------------\n");
}

int main() {
    Element* head = create_periodic_table();

    // Insert elements into the periodic table
    insert_element(head, "Hydrogen", 1, 1.00784, "H");
    insert_element(head, "Helium", 2, 4.002602, "He");
    insert_element(head, "Lithium", 3, 6.94099, "Li");
    insert_element(head, "Sodium", 11, 22.98976, "Na");

    // Print the periodic table
    print_periodic_table(head);

    return 0;
}