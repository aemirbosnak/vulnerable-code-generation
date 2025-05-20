//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char block;
    struct Element* next;
} Element;

Element* create_element(char* name, int atomic_number, float atomic_mass, char block) {
    Element* new_element = malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->block = block;
    new_element->next = NULL;

    return new_element;
}

void print_element(Element* element) {
    printf("Name: %s\n", element->name);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Atomic Mass: %.2f\n", element->atomic_mass);
    printf("Block: %c\n", element->block);
    printf("\n");
}

int main() {
    Element* head = NULL;

    // Create a few elements
    Element* copper = create_element("Copper", 29, 63.54, 'd');
    Element* sodium = create_element("Sodium", 11, 22.989, 's');
    Element* oxygen = create_element("Oxygen", 8, 15.999, 'p');

    // Link the elements together
    head = copper;
    copper->next = sodium;
    sodium->next = oxygen;

    // Print the elements
    print_element(head);

    return 0;
}