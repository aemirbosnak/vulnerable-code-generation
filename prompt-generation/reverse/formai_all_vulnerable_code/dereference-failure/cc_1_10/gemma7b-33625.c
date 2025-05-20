//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 17
#define COLS 18

struct Element {
    char name[20];
    int atomicNumber;
    float atomicMass;
    char state;
    struct Element *next;
};

struct Element *head = NULL;

void addElement(char *name, int atomicNumber, float atomicMass, char state)
{
    struct Element *newElement = malloc(sizeof(struct Element));
    strcpy(newElement->name, name);
    newElement->atomicNumber = atomicNumber;
    newElement->atomicMass = atomicMass;
    newElement->state = state;
    newElement->next = NULL;

    if (head == NULL)
    {
        head = newElement;
    }
    else
    {
        struct Element *tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = newElement;
    }
}

void printTable()
{
    struct Element *current = head;
    printf("------------------------------------------------------------------------\n");
    printf("Element Table\n");
    printf("------------------------------------------------------------------------\n");
    printf("  # | Name | Atomic Number | Atomic Mass | State |\n");
    printf("------------------------------------------------------------------------\n");
    while (current)
    {
        printf("  %3d | %20s | %d | %.2f | %c |\n", current->atomicNumber, current->name, current->atomicNumber, current->atomicMass, current->state);
        current = current->next;
    }
    printf("------------------------------------------------------------------------\n");
}

int main()
{
    addElement("Hydrogen", 1, 1.008, 'G');
    addElement("Helium", 2, 4.0026, 'G');
    addElement("Lithium", 3, 6.940, 'S');
    addElement("Sodium", 11, 22.989, 'M');
    printTable();

    return 0;
}