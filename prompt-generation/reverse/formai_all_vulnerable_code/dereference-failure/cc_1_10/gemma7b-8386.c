//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
#define NUM_ELEMENTS 118

struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element* next;
};

// Global variables
struct Element* head = NULL;

void insertElement(char* name, int atomic_number, float atomic_mass, char* symbol)
{
    struct Element* newElement = malloc(sizeof(struct Element));

    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    strcpy(newElement->symbol, symbol);

    newElement->next = head;
    head = newElement;
}

void printElements()
{
    struct Element* currentElement = head;

    while (currentElement)
    {
        printf("%s (%c) - Atomic number: %d, Atomic mass: %.2f\n", currentElement->name, currentElement->symbol, currentElement->atomic_number, currentElement->atomic_mass);
        currentElement = currentElement->next;
    }
}

int main()
{
    insertElement("Hydrogen", 1, 1.008, "H");
    insertElement("Helium", 2, 4.0026, "He");
    insertElement("Lithium", 3, 6.940, "Li");
    insertElement("Sodium", 11, 22.989, "Na");

    printElements();

    return 0;
}