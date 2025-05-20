//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char block_number;
    char type;
    struct Element* next;
} Element;

Element* create_element(char* name, int atomic_number, float atomic_mass, char block_number, char type)
{
    Element* new_element = malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    new_element->block_number = block_number;
    new_element->type = type;
    new_element->next = NULL;

    return new_element;
}

void print_element(Element* element)
{
    printf("%-20s (%d) - %.2f, Block %c, Type: %c\n", element->name, element->atomic_number, element->atomic_mass, element->block_number, element->type);
}

int main()
{
    Element* periodic_table = NULL;

    // Create a few elements
    Element* hydrogen = create_element("Hydrogen", 1, 1.008, '1', 'Gas');
    Element* helium = create_element("Helium", 2, 4.0026, '2', 'Gas');
    Element* sodium = create_element("Sodium", 11, 22.9897, '1', 'Metal');
    Element* gold = create_element("Gold", 79, 196.966, '6', 'Transition Metal');

    // Link the elements together
    periodic_table = hydrogen;
    hydrogen->next = helium;
    helium->next = sodium;
    sodium->next = gold;

    // Print the elements
    print_element(periodic_table);

    return 0;
}