//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

void insert(struct List* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(struct List* list, int data) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void display(struct List* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct List list;
    list.head = NULL;

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);

    display(&list);

    delete(&list, 20);

    display(&list);

    return 0;
}