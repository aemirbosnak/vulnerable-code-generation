//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char block_number;
    char type;
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, float atomic_mass, char block_number, char type)
{
    Element* element = (Element*)malloc(sizeof(Element));

    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    element->block_number = block_number;
    element->type = type;
    element->next = NULL;

    return element;
}

void printElement(Element* element)
{
    printf("Name: %s\n", element->name);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Atomic Mass: %.2f\n", element->atomic_mass);
    printf("Block Number: %c\n", element->block_number);
    printf("Type: %c\n", element->type);
    printf("\n");
}

int main()
{
    Element* periodic_table = NULL;

    // Create a few elements
    Element* hydrogen = createElement("Hydrogen", 1, 1.008, 'I', 'Gas');
    Element* oxygen = createElement("Oxygen", 8, 15.999, 'II', 'Gas');
    Element* carbon = createElement("Carbon", 6, 12.011, 'II', 'Solid');

    // Add elements to the periodic table
    periodic_table = hydrogen;
    periodic_table->next = oxygen;
    periodic_table->next->next = carbon;

    // Print the elements in the periodic table
    printElement(periodic_table);

    return 0;
}