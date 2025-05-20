//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element* next;
};

struct Element* create_element(char* name, int atomic_number, float atomic_mass, char* symbol)
{
    struct Element* element = malloc(sizeof(struct Element));
    strcpy(element->name, name);
    element->atomic_number = atomic_number;
    element->atomic_mass = atomic_mass;
    strcpy(element->symbol, symbol);
    element->next = NULL;
    return element;
}

void print_periodic_table(struct Element* head)
{
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("  #  Element  Atomic Number  Atomic Mass  Symbol\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    struct Element* current = head;
    while (current)
    {
        printf("  %-2d  %-15s  %-12d  %-10.2f  %-3s\n", current->atomic_number, current->name, current->atomic_number, current->atomic_mass, current->symbol);
        current = current->next;
    }

    printf("---------------------------------------------------------------------------------------------------------\n");
}

int main()
{
    struct Element* head = create_element("Hydrogen", 1, 1.008, "H");
    head = create_element("Helium", 2, 4.0026, "He");
    head = create_element("Lithium", 3, 6.940, "Li");

    print_periodic_table(head);

    return 0;
}