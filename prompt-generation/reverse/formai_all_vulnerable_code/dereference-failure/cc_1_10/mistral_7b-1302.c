//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IntelligentPerson {
    int iq_score;
    char name[50];
    struct IntelligentPerson *next;
} IntelligentPerson;

IntelligentPerson *head = NULL;

void addIntelligentPerson(int iq, const char *name) {
    IntelligentPerson *newNode = (IntelligentPerson *)malloc(sizeof(IntelligentPerson));
    newNode->iq_score = iq;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

IntelligentPerson *searchIntelligentPerson(int iq) {
    IntelligentPerson *current = head;
    while (current != NULL) {
        if (current->iq_score == iq)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeIntelligentPerson(int iq) {
    IntelligentPerson *current = head, *previous = NULL;
    while (current != NULL) {
        if (current->iq_score == iq) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayIntelligentPeople() {
    IntelligentPerson *current = head;
    printf("Intelligent People:\n");
    while (current != NULL) {
        printf("IQ: %d, Name: %s -> ", current->iq_score, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    addIntelligentPerson(150, "Albert Einstein");
    addIntelligentPerson(160, "Stephen Hawking");
    addIntelligentPerson(145, "Marie Curie");
    addIntelligentPerson(170, "Isaac Newton");
    addIntelligentPerson(125, "Galileo Galilei");

    printf("Linked List Initially:\n");
    displayIntelligentPeople();

    printf("Searching for person with IQ 170:\n");
    IntelligentPerson *person = searchIntelligentPerson(170);
    if (person != NULL)
        printf("Found: IQ: %d, Name: %s\n", person->iq_score, person->name);
    else
        printf("Not Found\n");

    printf("Removing person with IQ 145:\n");
    removeIntelligentPerson(145);
    displayIntelligentPeople();

    return 0;
}