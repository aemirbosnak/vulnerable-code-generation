//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char block_number;
    char group_number;
    char state;
    struct Element* next;
} Element;

Element* head = NULL;

void insert_element(char* name, int atomic_number, float atomic_mass, char block_number, char group_number, char state) {
    Element* new_element = malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->block_number = block_number;
    new_element->group_number = group_number;
    new_element->state = state;
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        Element* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_elements() {
    Element* current = head;
    while (current) {
        printf("%s (%d) - %f, %c, %c, %c\n", current->name, current->atomic_number, current->atomic_mass, current->block_number, current->group_number, current->state);
        current = current->next;
    }
}

int main() {
    insert_element("Hydrogen", 1, 1.00784, 'I', 1, 'Gas');
    insert_element("Helium", 2, 4.002602, 'I', 1, 'Gas');
    insert_element("Lithium", 3, 6.94099, 'II', 1, 'Solid');
    insert_element("Sodium", 11, 22.98976, 'II', 1, 'Solid');

    print_elements();

    return 0;
}