//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the periodic table structure
typedef struct PeriodicTable
{
    char name[20];
    int atomicNumber;
    float atomicMass;
    char block[20];
    char type[20];
    struct PeriodicTable* next;
} PeriodicTable;

// Create a new periodic table element
PeriodicTable* createElement(char* name, int atomicNumber, float atomicMass, char* block, char* type)
{
    PeriodicTable* element = (PeriodicTable*)malloc(sizeof(PeriodicTable));
    strcpy(element->name, name);
    element->atomicNumber = atomicNumber;
    element->atomicMass = atomicMass;
    strcpy(element->block, block);
    strcpy(element->type, type);
    element->next = NULL;
    return element;
}

// Print the periodic table
void printTable(PeriodicTable* head)
{
    while (head)
    {
        printf("%s (%d) - %.2f, %s, %s\n", head->name, head->atomicNumber, head->atomicMass, head->block, head->type);
        head = head->next;
    }
}

int main()
{
    // Create the periodic table
    PeriodicTable* table = createElement("Hydrogen", 1, 1.008, "I", "Gas");
    table = createElement("Helium", 2, 4.0026, "I", "Gas");
    table = createElement("Lithium", 3, 6.940, "I", " alkali metal");
    table = createElement("Sodium", 11, 22.989, "I", "alkali metal");

    // Print the periodic table
    printTable(table);

    return 0;
}