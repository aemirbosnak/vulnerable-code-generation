//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char email[50];
    struct Node* next;
};

struct List {
    struct Node* head;
    int size;
};

void addToList(struct List* list, char email[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void removeFromList(struct List* list, char email[]) {
    struct Node* current = list->head;
    struct Node* previous = NULL;

    while (current != NULL && strcmp(current->email, email)) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found in list!\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->size--;
}

void displayList(struct List* list) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = list->head;
    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    struct List* mailingList = (struct List*)malloc(sizeof(struct List));
    mailingList->head = NULL;
    mailingList->size = 0;

    addToList(mailingList, "john@example.com");
    addToList(mailingList, "mary@example.com");
    addToList(mailingList, "jane@example.com");

    displayList(mailingList);

    removeFromList(mailingList, "mary@example.com");
    removeFromList(mailingList, "peter@example.com");

    displayList(mailingList);

    return 0;
}