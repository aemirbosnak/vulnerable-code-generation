//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct CrimeScene {
    char name[50];
    char crimeType[20];
    struct CrimeScene *next;
} CrimeScene;

CrimeScene *createNode(char *name, char *crimeType) {
    CrimeScene *newNode = (CrimeScene *) malloc(sizeof(CrimeScene));
    strcpy(newNode->name, name);
    strcpy(newNode->crimeType, crimeType);
    newNode->next = NULL;
    return newNode;
}

void addNode(CrimeScene **head, CrimeScene *newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        CrimeScene *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(CrimeScene *head) {
    CrimeScene *current = head;
    printf("Crime Scene Details:\n");
    while (current != NULL) {
        printf("Name: %s, Crime Type: %s\n", current->name, current->crimeType);
        current = current->next;
    }
}

int main() {
    CrimeScene *head = NULL;

    addNode(&head, createNode("Dr. Roylott", "Murder"));
    addNode(&head, createNode("Mrs. Hudson", "Theft"));
    addNode(&head, createNode("Professor Moriarty", "Conspiracy"));
    addNode(&head, createNode("Sherlock Holmes", "Consultation"));

    printList(head);

    return 0;
}