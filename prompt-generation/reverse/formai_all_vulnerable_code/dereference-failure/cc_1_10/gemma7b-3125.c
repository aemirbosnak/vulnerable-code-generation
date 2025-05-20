//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
#define MAX_ELEMENTS 118

struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    char block_number;
    char type;
    struct Element* next;
};

// Create a linked list of elements
struct Element* head = NULL;

void insert_element(char* name, int atomic_number, float atomic_mass, char* symbol, char block_number, char type) {
    struct Element* new_element = (struct Element*)malloc(sizeof(struct Element));

    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    strcpy(new_element->symbol, symbol);
    new_element->block_number = block_number;
    new_element->type = type;
    new_element->next = NULL;

    if (head == NULL) {
        head = new_element;
    } else {
        struct Element* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_elements() {
    struct Element* current = head;
    printf("Printing all elements...\n");
    while (current) {
        printf("%s (%d) - %f, %s, Block %c, Type: %c\n", current->name, current->atomic_number, current->atomic_mass, current->symbol, current->block_number, current->type);
        current = current->next;
    }
}

int main() {
    insert_element("Hydrogen", 1, 1.00784, "H", '1', 'S');
    insert_element("Helium", 2, 4.002602, "He", '2', 'S');
    insert_element("Lithium", 3, 6.94092, "Li", '1', ' alkali metals');

    print_elements();

    return 0;
}