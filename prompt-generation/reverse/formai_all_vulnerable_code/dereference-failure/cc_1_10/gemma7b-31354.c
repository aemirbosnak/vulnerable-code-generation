//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_LIST_SIZE 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

List* createList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addToList(List* list, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void printList(List* list) {
    Node* current = list->head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List* myList = createList();
    addToList(myList, "John Doe");
    addToList(myList, "Jane Doe");
    addToList(myList, "Peter Pan");
    printList(myList);

    return 0;
}