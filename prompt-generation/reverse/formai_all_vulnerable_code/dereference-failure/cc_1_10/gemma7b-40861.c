//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element *next;
} Element;

Element *create_element(char *name, int atomic_number, float atomic_mass, char *symbol)
{
    Element *new_element = malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    strcpy(new_element->symbol, symbol);
    new_element->next = NULL;
    return new_element;
}

void print_periodic_table(Element *elements)
{
    int i = 0;
    printf("----------------------------------------------------------------------------------------\n");
    printf("   | Name | Atomic Number | Atomic Mass | Symbol |\n");
    printf("----------------------------------------------------------------------------------------\n");
    for (elements = elements; elements; elements = elements->next)
    {
        printf("   | %s | %d | %.2f | %s |\n", elements->name, elements->atomic_number, elements->atomic_mass, elements->symbol);
        i++;
    }
    printf("----------------------------------------------------------------------------------------\n");
    printf("Total number of elements: %d\n", i);
}

int main()
{
    Element *elements = create_element("Hydrogen", 1, 1.008, "H");
    elements = create_element("Helium", 2, 4.0026, "He");
    elements = create_element("Lithium", 3, 6.940, "Li");
    elements = create_element("Sodium", 11, 22.9898, "Na");

    print_periodic_table(elements);

    return 0;
}