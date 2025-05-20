//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    double atomic_mass;
    struct Element* next;
} Element;

Element* CreateElement(char* name, int atomic_number, double atomic_mass)
{
    Element* newElement = malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    newElement->next = NULL;

    return newElement;
}

void PrintElement(Element* element)
{
    printf("Name: %s\n", element->name);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Atomic Mass: %.2lf\n", element->atomic_mass);
    printf("\n");
}

int main()
{
    Element* periodicTable = NULL;

    // Create some elements
    Element* hydrogen = CreateElement("Hydrogen", 1, 1.008);
    Element* helium = CreateElement("Helium", 2, 4.0026);
    Element* sodium = CreateElement("Sodium", 11, 22.9897);
    Element* gold = CreateElement("Gold", 79, 196.966);

    // Link the elements together
    periodicTable = hydrogen;
    hydrogen->next = helium;
    helium->next = sodium;
    sodium->next = gold;

    // Print the elements
    PrintElement(periodicTable);

    return 0;
}