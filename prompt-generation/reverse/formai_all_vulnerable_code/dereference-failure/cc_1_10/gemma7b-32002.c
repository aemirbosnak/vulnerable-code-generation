//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EMAIL_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNode(List* list, char* name, char* email) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printNodes(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%s - %s\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    List* list = createList();
    addNode(list, "John Doe", "john.doe@gmail.com");
    addNode(list, "Jane Doe", "jane.doe@gmail.com");
    addNode(list, "Peter Pan", "peter.pan@ Neverland.com");

    printNodes(list);

    return 0;
}