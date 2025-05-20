//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, float atomic_mass, char* symbol)
{
    Element* element = (Element*)malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    strcpy(element->symbol, symbol);
    element->next = NULL;
    return element;
}

void printElement(Element* element)
{
    printf("%s (%c) - Atomic Number: %d, Atomic Mass: %.2f\n", element->name, element->symbol, element->atomic_number, element->atomic_mass);
}

int main()
{
    Element* periodicTable = NULL;

    // Create some elements
    Element* hydrogen = createElement("Hydrogen", 1, 1.008, "H");
    Element* helium = createElement("Helium", 2, 4.0026, "He");
    Element* sodium = createElement("Sodium", 11, 22.9898, "Na");
    Element* gold = createElement("Gold", 79, 196.966, "Au");

    // Add elements to the periodic table
    periodicTable = hydrogen;
    periodicTable->next = helium;
    periodicTable->next->next = sodium;
    periodicTable->next->next->next = gold;

    // Print the elements
    printElement(periodicTable);

    return 0;
}