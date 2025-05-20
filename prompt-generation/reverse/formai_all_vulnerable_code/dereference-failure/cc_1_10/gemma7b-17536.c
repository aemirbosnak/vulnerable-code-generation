//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
struct Element
{
    char name[20];
    int atomic_number;
    float atomic_mass;
    char state;
    struct Element* next;
};

// Create a linked list of elements
struct Element* head = NULL;

// Function to add an element to the table
void addElement(char* name, int atomic_number, float atomic_mass, char state)
{
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    strcpy(newElement->name, name);
    newElement->atomic_number = atomic_number;
    newElement->atomic_mass = atomic_mass;
    newElement->state = state;
    newElement->next = NULL;

    if (head == NULL)
    {
        head = newElement;
    }
    else
    {
        struct Element* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newElement;
    }
}

// Function to print the elements of the table
void printElements()
{
    struct Element* temp = head;
    printf("--------------------------------------------------------\n");
    printf("  Name\t\tAtomic Number\tAtomic Mass\tState\n");
    printf("--------------------------------------------------------\n");
    while (temp)
    {
        printf("%s\t\t%d\t\t%.2f\t%c\n", temp->name, temp->atomic_number, temp->atomic_mass, temp->state);
        temp = temp->next;
    }
    printf("--------------------------------------------------------\n");
}

int main()
{
    addElement("Hydrogen", 1, 1.008, 'G');
    addElement("Helium", 2, 4.0026, 'G');
    addElement("Lithium", 3, 6.940, 'S');
    addElement("Sodium", 11, 22.989, 'S');

    printElements();

    return 0;
}