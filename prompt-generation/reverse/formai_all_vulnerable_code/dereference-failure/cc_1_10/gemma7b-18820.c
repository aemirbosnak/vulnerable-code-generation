//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the C Periodic Table
struct Element {
    char name[20];
    int atomicNumber;
    float atomicMass;
    char state;
    char symbol[2];
    struct Element *next;
};

// Create the table
struct Element *head = NULL;

// Function to add an element to the table
void addElement(char *name, int atomicNumber, float atomicMass, char state, char symbol) {
    struct Element *newElement = (struct Element *)malloc(sizeof(struct Element));
    strcpy(newElement->name, name);
    newElement->atomicNumber = atomicNumber;
    newElement->atomicMass = atomicMass;
    newElement->state = state;
    strcpy(newElement->symbol, symbol);
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        struct Element *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

// Function to display the table
void displayTable() {
    struct Element *current = head;
    printf("------------------------------------------------------------------------\n");
    printf("   Element Name | Atomic Number | Atomic Mass | State | Symbol |\n");
    printf("------------------------------------------------------------------------\n");
    while (current) {
        printf("   %-20s | %d | %.2f | %c | %s |\n", current->name, current->atomicNumber, current->atomicMass, current->state, current->symbol);
        current = current->next;
    }
    printf("------------------------------------------------------------------------\n");
}

int main() {
    // Add some elements to the table
    addElement("Hydrogen", 1, 1.008, 'G', "H");
    addElement("Helium", 2, 4.0026, 'G', "He");
    addElement("Lithium", 3, 6.940, 'S', "Li");
    addElement("Sodium", 11, 22.989, 'S', "Na");

    // Display the table
    displayTable();

    return 0;
}