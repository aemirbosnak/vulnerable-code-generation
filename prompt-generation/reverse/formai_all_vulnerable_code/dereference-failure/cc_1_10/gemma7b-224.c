//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

struct Element {
    char name[20];
    int atomicNumber;
    float atomicMass;
    char symbol[2];
    struct Element* next;
};

void createElement(struct Element** head) {
    struct Element* newNode = (struct Element*)malloc(sizeof(struct Element));
    (*head) = newNode;
    newNode->next = NULL;
}

void addElement(struct Element* head, char* name, int atomicNumber, float atomicMass, char* symbol) {
    struct Element* newNode = (struct Element*)malloc(sizeof(struct Element));
    newNode->name[0] = '\0';
    strcpy(newNode->name, name);
    newNode->atomicNumber = atomicNumber;
    newNode->atomicMass = atomicMass;
    newNode->symbol[0] = '\0';
    strcpy(newNode->symbol, symbol);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void printElement(struct Element* head) {
    struct Element* current = head;
    while (current) {
        printf("%s (%d) - %f, %s\n", current->name, current->atomicNumber, current->atomicMass, current->symbol);
        current = current->next;
    }
}

int main() {
    struct Element* head = NULL;

    createElement(&head);
    addElement(head, "Hydrogen", 1, 1.008, "H");
    addElement(head, "Helium", 2, 4.0026, "He");
    addElement(head, "Lithium", 3, 6.940, "Li");

    printElement(head);

    return 0;
}