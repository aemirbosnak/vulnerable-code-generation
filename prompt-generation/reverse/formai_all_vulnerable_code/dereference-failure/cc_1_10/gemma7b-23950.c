//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_LIST_SIZE 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

void insert(List* list, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    List* myList = malloc(sizeof(List));
    myList->head = NULL;
    myList->tail = NULL;

    insert(myList, "John Doe");
    insert(myList, "Jane Doe");
    insert(myList, "Bill Smith");
    insert(myList, "Mary Johnson");

    printList(myList);

    return 0;
}