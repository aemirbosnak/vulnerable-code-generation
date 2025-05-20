//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, float atomic_mass)
{
    Element* element = malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    element->next = NULL;

    return element;
}

void printElement(Element* element)
{
    printf("Name: %s\n", element->name);
    printf("Atomic number: %d\n", element->atomic_number);
    printf("Atomic mass: %.2f\n", element->atomic_mass);
    printf("\n");
}

int main()
{
    Element* table = NULL;

    // Create some elements
    Element* hydrogen = createElement("Hydrogen", 1, 1.007);
    Element* helium = createElement("Helium", 2, 4.0026);
    Element* sodium = createElement("Sodium", 11, 22.989);
    Element* gold = createElement("Gold", 79, 196.966);

    // Add elements to the table
    table = hydrogen;
    table->next = helium;
    table->next->next = sodium;
    table->next->next->next = gold;

    // Print the elements
    printElement(table);

    return 0;
}