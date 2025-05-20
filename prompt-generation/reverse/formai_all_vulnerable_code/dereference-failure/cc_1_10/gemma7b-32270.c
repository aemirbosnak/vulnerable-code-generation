//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 17
#define COLS 18

typedef struct Element {
    char name[20];
    int atomicNumber;
    float mass;
    char symbol[2];
    struct Element *next;
} Element;

Element *head = NULL;

void insertElement(char *name, int atomicNumber, float mass, char *symbol) {
    Element *newElement = (Element *)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    newElement->atomicNumber = atomicNumber;
    newElement->mass = mass;
    strcpy(newElement->symbol, symbol);
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        Element *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void printTable() {
    Element *current = head;
    printf("------------------------------------------------------------------------\n");
    printf("    | Name | Atomic Number | Mass | Symbol |\n");
    printf("------------------------------------------------------------------------\n");
    while (current) {
        printf("    | %s | %d | %.2f | %s |\n", current->name, current->atomicNumber, current->mass, current->symbol);
        current = current->next;
    }
    printf("------------------------------------------------------------------------\n");
}

int main() {
    insertElement("Hydrogen", 1, 1.008, "H");
    insertElement("Helium", 2, 4.0026, "He");
    insertElement("Lithium", 3, 6.940, "Li");
    insertElement("Sodium", 11, 22.989, "Na");
    insertElement("Gold", 79, 196.966, "Au");

    printTable();

    return 0;
}