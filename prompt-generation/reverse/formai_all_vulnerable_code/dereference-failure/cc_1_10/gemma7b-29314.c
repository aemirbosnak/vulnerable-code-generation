//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define PERIOD_TABLE_SIZE 118

struct PeriodicTable {
    char name[20];
    int atomicNumber;
    float atomicMass;
    char block;
    char type;
    struct PeriodicTable* next;
};

void createPeriodicTable(struct PeriodicTable** head) {
    *head = (struct PeriodicTable*)malloc(sizeof(struct PeriodicTable));
    (*head)->name[0] = '\0';
    (*head)->atomicNumber = 0;
    (*head)->atomicMass = 0.0f;
    (*head)->block = 'a';
    (*head)->type = 'n';
    (*head)->next = NULL;
}

void addPeriodicTableEntry(struct PeriodicTable** head, char* name, int atomicNumber, float atomicMass, char block, char type) {
    struct PeriodicTable* newNode = (struct PeriodicTable*)malloc(sizeof(struct PeriodicTable));
    newNode->name[0] = '\0';
    strcpy(newNode->name, name);
    newNode->atomicNumber = atomicNumber;
    newNode->atomicMass = atomicMass;
    newNode->block = block;
    newNode->type = type;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct PeriodicTable* tempNode = *head;
        while (tempNode->next) {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

int main() {
    struct PeriodicTable* head = NULL;
    createPeriodicTable(&head);
    addPeriodicTableEntry(&head, "Hydrogen", 1, 1.0f, 'I', 'S');
    addPeriodicTableEntry(&head, "Helium", 2, 4.0f, 'I', 'S');
    addPeriodicTableEntry(&head, "Lithium", 3, 6.940f, 'I', ' alkali metals');

    struct PeriodicTable* currentTable = head;
    while (currentTable) {
        printf("%s (%d) - %f, Block: %c, Type: %c\n", currentTable->name, currentTable->atomicNumber, currentTable->atomicMass, currentTable->block, currentTable->type);
        currentTable = currentTable->next;
    }

    return 0;
}