//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    int atomic_mass;
    struct Element* next;
} Element;

Element* createElement(char* name, int atomic_number, int atomic_mass)
{
    Element* element = (Element*)malloc(sizeof(Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    element->next = NULL;
    return element;
}

void printElement(Element* element)
{
    printf("%s (%d) - Mass: %d\n", element->name, element->atomic_number, element->atomic_mass);
}

void printPeriodicTable(Element* head)
{
    Element* current = head;
    printf("--------------------------------------------------------\n");
    printf("  | Name | Atomic Number | Atomic Mass |\n");
    printf("--------------------------------------------------------\n");
    while (current)
    {
        printElement(current);
        current = current->next;
    }
    printf("--------------------------------------------------------\n");
}

int main()
{
    Element* head = createElement("Hydrogen", 1, 1);
    head = createElement("Helium", 2, 4);
    head = createElement("Lithium", 3, 6.940);
    head = createElement("Sodium", 11, 22.989);
    head = createElement("Silver", 47, 107.868);

    printPeriodicTable(head);

    return 0;
}