//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
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
    struct Element *next;
} Element;

Element *head = NULL;

void insertElement(char *name, int atomic_number, float atomic_mass, char *symbol)
{
    Element *newElement = (Element *)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    strcpy(newElement->symbol, symbol);
    newElement->next = NULL;

    if (head == NULL)
    {
        head = newElement;
    }
    else
    {
        Element *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newElement;
    }
}

void printElement(Element *element)
{
    printf("Name: %s\n", element->name);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Atomic Mass: %.2f\n", element->atomic_mass);
    printf("Symbol: %s\n", element->symbol);
    printf("\n");
}

int main()
{
    insertElement("Hydrogen", 1, 1.008, "H");
    insertElement("Helium", 2, 4.0026, "He");
    insertElement("Lithium", 3, 6.940, "Li");
    insertElement("Sodium", 11, 22.989, "Na");

    Element *element = head;
    while (element)
    {
        printElement(element);
        element = element->next;
    }

    return 0;
}