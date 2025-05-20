//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Define the periodic table structure
typedef struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element* next;
} Element;

// Global variable to store the periodic table
Element* periodic_table = NULL;

void insert_element(char* name, int atomic_number, float atomic_mass, char* symbol)
{
    Element* new_element = malloc(sizeof(Element));
    strcpy(new_element->name, name);
    new_element->atomic_number = atomic_number;
    new_element->atomic_mass = atomic_mass;
    strcpy(new_element->symbol, symbol);
    new_element->next = NULL;

    if (periodic_table == NULL)
    {
        periodic_table = new_element;
    }
    else
    {
        Element* last_element = periodic_table;
        while (last_element->next != NULL)
        {
            last_element = last_element->next;
        }
        last_element->next = new_element;
    }
}

void print_periodic_table()
{
    Element* current_element = periodic_table;
    while (current_element)
    {
        printf("%-20s | %4d | %.2f | %-2s |\n", current_element->name, current_element->atomic_number, current_element->atomic_mass, current_element->symbol);
        current_element = current_element->next;
    }
}

int main()
{
    insert_element("Hydrogen", 1, 1.008, "H");
    insert_element("Helium", 2, 4.0026, "He");
    insert_element("Lithium", 3, 6.940, "Li");
    insert_element("Sodium", 11, 22.989, "Na");

    print_periodic_table();

    return 0;
}