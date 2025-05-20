//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the C Periodic Table
#define PERIODIC_TABLE_SIZE 118

typedef struct Element {
    char name[20];
    int atomic_number;
    float atomic_mass;
    char symbol[2];
    struct Element* next;
} Element;

// Function to insert an element into the periodic table
void insertElement(Element* head, char* name, int atomicNumber, float atomicMass, char* symbol) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->atomic_number = atomicNumber;
    newElement->atomic_mass = atomicMass;
    strcpy(newElement->symbol, symbol);
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        Element* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newElement;
    }
}

// Function to print the periodic table
void printPeriodicTable(Element* head) {
    printf("-------------------------------------------------------------------------\n");
    printf("     Group\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Element\t\tAtomic Number\tAtomic Mass\tSymbol\n");
    printf("-------------------------------------------------------------------------\n");

    Element* temp = head;
    while (temp) {
        printf("%s\t\t%d\t\t%.2f\t%s\n", temp->name, temp->atomic_number, temp->atomic_mass, temp->symbol);
        temp = temp->next;
    }

    printf("-------------------------------------------------------------------------\n");
}

int main() {
    Element* periodicTable = NULL;

    // Insert elements into the periodic table
    insertElement(periodicTable, "Hydrogen", 1, 1.008, "H");
    insertElement(periodicTable, "Helium", 2, 4.0026, "He");
    insertElement(periodicTable, "Lithium", 3, 6.940, "Li");
    insertElement(periodicTable, "Sodium", 11, 22.989, "Na");

    // Print the periodic table
    printPeriodicTable(periodicTable);

    return 0;
}