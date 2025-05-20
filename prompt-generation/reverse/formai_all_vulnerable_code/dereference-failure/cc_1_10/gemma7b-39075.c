//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    int atomic_mass;
    char symbol[2];
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, int atomic_mass, char* symbol)
{
    Element* element = malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    strcpy(element->symbol, symbol);
    element->next = NULL;
    return element;
}

void printElement(Element* element)
{
    printf("%s (%c) - Atomic Number: %d, Atomic Mass: %d\n", element->name, element->symbol, element->atomic_number, element->atomic_mass);
}

int main()
{
    Element* periodic_table = NULL;

    // Create a few elements
    Element* hydrogen = createElement("Hydrogen", 1, 1, "H");
    Element* oxygen = createElement("Oxygen", 8, 16, "O");
    Element* carbon = createElement("Carbon", 6, 12, "C");
    Element* sodium = createElement("Sodium", 11, 23, "Na");

    // Link the elements together
    periodic_table = hydrogen;
    hydrogen->next = oxygen;
    oxygen->next = carbon;
    carbon->next = sodium;

    // Print the elements
    printElement(periodic_table);

    return 0;
}