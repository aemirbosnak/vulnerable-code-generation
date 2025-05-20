//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomicNumber;
    double atomicMass;
    char symbol[2];
    struct Element* next;
} Element;

Element* insertElement(Element* head, char* name, int atomicNumber, double atomicMass, char* symbol)
{
    Element* newNode = malloc(sizeof(Element));
    strcpy(newNode->name, name);
    newNode->atomicNumber = atomicNumber;
    newNode->atomicMass = atomicMass;
    strcpy(newNode->symbol, symbol);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Element* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void printElement(Element* head)
{
    Element* temp = head;
    while (temp)
    {
        printf("%s (%d) - %.2lf, %s\n", temp->name, temp->atomicNumber, temp->atomicMass, temp->symbol);
        temp = temp->next;
    }
}

int main()
{
    Element* head = NULL;

    insertElement(head, "Hydrogen", 1, 1.008, "H");
    insertElement(head, "Helium", 2, 4.0026, "He");
    insertElement(head, "Lithium", 3, 6.940, "Li");
    insertElement(head, "Sodium", 11, 22.989, "Na");

    printElement(head);

    return 0;
}