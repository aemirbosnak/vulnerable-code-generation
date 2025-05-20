//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the periodic table structure
typedef struct element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct element* next;
} element;

// Create a linked list of elements
element* create_element_list() {
    element* head = malloc(sizeof(element));
    head->name[0] = '\0';
    head->atomic_number = 0;
    head->atomic_mass = 0.0f;
    head->symbol[0] = '\0';
    head->next = NULL;
    return head;
}

// Add an element to the list
void add_element(element* head, char* name, int atomic_number, float atomic_mass, char* symbol) {
    element* new_element = malloc(sizeof(element));
    new_element->name[0] = '\0';
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->symbol[0] = '\0';
    new_element->next = NULL;

    if (head->name[0] == '\0') {
        head = new_element;
    } else {
        element* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_element;
    }
}

// Print the elements in the list
void print_elements(element* head) {
    element* current = head;
    while (current) {
        printf("%s (%d) - %.2f, %s\n", current->name, current->atomic_number, current->atomic_mass, current->symbol);
        current = current->next;
    }
}

int main() {
    // Create an element list
    element* head = create_element_list();

    // Add some elements
    add_element(head, "Hydrogen", 1, 1.008, "H");
    add_element(head, "Helium", 2, 4.0026, "He");
    add_element(head, "Lithium", 3, 6.940, "Li");
    add_element(head, "Sodium", 11, 22.989, "Na");

    // Print the elements
    print_elements(head);

    return 0;
}