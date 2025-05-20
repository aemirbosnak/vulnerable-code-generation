//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118

struct Element
{
    char name[20];
    int atomic_number;
    double atomic_mass;
    char symbol[2];
    struct Element* next;
};

void display_elements(struct Element* head)
{
    struct Element* current = head;
    while (current)
    {
        printf("%s (%d) - %f, %s\n", current->name, current->atomic_number, current->atomic_mass, current->symbol);
        current = current->next;
    }
}

int main()
{
    struct Element* head = NULL;

    // Create and insert elements
    struct Element* element1 = malloc(sizeof(struct Element));
    element1->name[0] = 'H';
    element1->atomic_number = 1;
    element1->atomic_mass = 1.00784;
    element1->symbol[0] = 'H';
    element1->next = head;
    head = element1;

    struct Element* element2 = malloc(sizeof(struct Element));
    element2->name[0] = 'He';
    element2->atomic_number = 2;
    element2->atomic_mass = 4.002602;
    element2->symbol[0] = 'He';
    element2->next = head;
    head = element2;

    // Display elements
    display_elements(head);

    return 0;
}