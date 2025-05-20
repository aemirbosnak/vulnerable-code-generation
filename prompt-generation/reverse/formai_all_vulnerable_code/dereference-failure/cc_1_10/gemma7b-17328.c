//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[20];
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};

void insert(struct List* list, char name[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void printList(struct List* list) {
    struct Node* current = list->head;
    while (current) {
        printf("%s ", current->name);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    insert(list, "John Doe");
    insert(list, "Jane Doe");
    insert(list, "Peter Pan");

    printList(list);

    return 0;
}