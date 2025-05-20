//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    int atomic_mass;
    char block_number;
    char type;
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, int atomic_mass, char block_number, char type)
{
    Element* newElement = (Element*)malloc(sizeof(Element));

    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    newElement->block_number = block_number;
    newElement->type = type;
    newElement->next = NULL;

    return newElement;
}

void printElement(Element* element)
{
    printf("%s (%d) - %d, Block %c, Type: %c\n", element->name, element->atomic_number, element->atomic_mass, element->block_number, element->type);
}

int main()
{
    Element* table = NULL;

    // Create a few elements
    Element* hydrogen = createElement("Hydrogen", 1, 1, 'I', ' alkali metal');
    Element* oxygen = createElement("Oxygen", 8, 16, 'II', 'noble gas');
    Element* sodium = createElement("Sodium", 11, 23, 'I', ' alkali metal');

    // Add the elements to the table
    table = hydrogen;
    table->next = oxygen;
    table->next->next = sodium;

    // Print the elements
    printElement(table);

    return 0;
}