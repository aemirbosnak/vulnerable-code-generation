//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

struct Element {
    char name[20];
    int atomicNumber;
    float atomicMass;
    char symbol[2];
    struct Element* next;
};

struct Element* createElement(char* name, int atomicNumber, float atomicMass, char* symbol) {
    struct Element* element = malloc(sizeof(struct Element));
    strcpy(element->name, name);
    element->atomicNumber = atomicNumber;
    element->atomicMass = atomicMass;
    strcpy(element->symbol, symbol);
    element->next = NULL;
    return element;
}

struct Element* insertElement(struct Element* head, char* name, int atomicNumber, float atomicMass, char* symbol) {
    struct Element* element = createElement(name, atomicNumber, atomicMass, symbol);
    if (head == NULL) {
        head = element;
    } else {
        struct Element* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = element;
    }
    return head;
}

void printElement(struct Element* head) {
    while (head) {
        printf("%s (%c) - Atomic Number: %d, Atomic Mass: %.2f\n", head->name, head->symbol, head->atomicNumber, head->atomicMass);
        head = head->next;
    }
}

int main() {
    struct Element* head = insertElement(NULL, "Hydrogen", 1, 1.008, "H");
    insertElement(head, "Helium", 2, 4.0026, "He");
    insertElement(head, "Lithium", 3, 6.9409, "Li");
    printElement(head);
    return 0;
}