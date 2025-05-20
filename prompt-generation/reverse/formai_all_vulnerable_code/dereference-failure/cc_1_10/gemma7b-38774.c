//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char state;
    struct Element* next;
};

typedef struct Element Element;

Element* createElement(char* name, int atomic_number, float atomic_mass, char state) {
    Element* element = (Element*)malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    element->state = state;
    element->next = NULL;
    return element;
}

void printElement(Element* element) {
    printf("Name: %s\n", element->name);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Atomic Mass: %.2f\n", element->atomic_mass);
    printf("State: %c\n", element->state);
    printf("\n");
}

int main() {
    Element* periodic_table = NULL;

    // Create a few elements
    Element* hydrogen = createElement("Hydrogen", 1, 1.008, 'G');
    Element* oxygen = createElement("Oxygen", 8, 15.999, 'L');
    Element* carbon = createElement("Carbon", 6, 12.011, 'S');
    Element* sodium = createElement("Sodium", 11, 22.989, 'M');

    // Add the elements to the periodic table
    periodic_table = hydrogen;
    periodic_table->next = oxygen;
    periodic_table->next->next = carbon;
    periodic_table->next->next->next = sodium;

    // Print the elements
    printElement(periodic_table);

    return 0;
}