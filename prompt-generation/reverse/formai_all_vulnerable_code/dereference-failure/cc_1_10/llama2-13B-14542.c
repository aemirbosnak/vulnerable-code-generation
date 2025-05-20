//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Brave knight struct to represent nodes in the linked list
typedef struct BraveNode {
    int value; // The brave knight's treasure
    struct BraveNode *next; // The next node in the list
} BraveNode;

// Brave linked list functions
BraveNode* createList(int size) {
    BraveNode* list = malloc(size * sizeof(BraveNode));
    for (int i = 0; i < size; i++) {
        list[i].value = i + 1; // Initialize with consecutive integers
        list[i].next = NULL; // No next node by default
    }
    return list;
}

void printList(BraveNode* list) {
    for (BraveNode* curr = list; curr != NULL; curr = curr->next) {
        printf("%d ", curr->value);
    }
    printf("\n");
}

BraveNode* insertAtStart(BraveNode* list, int value) {
    BraveNode* newNode = malloc(sizeof(BraveNode));
    newNode->value = value;
    newNode->next = list;
    list = newNode;
    return list;
}

BraveNode* insertAtEnd(BraveNode* list, int value) {
    BraveNode* newNode = malloc(sizeof(BraveNode));
    newNode->value = value;
    newNode->next = NULL;
    if (list == NULL) {
        return newNode;
    }
    list->next = newNode;
    list = newNode;
    return list;
}

BraveNode* removeAtStart(BraveNode* list) {
    if (list == NULL) {
        return NULL;
    }
    BraveNode* removedNode = list->next;
    list->next = removedNode->next;
    free(removedNode);
    return list;
}

BraveNode* removeAtEnd(BraveNode* list) {
    if (list == NULL) {
        return NULL;
    }
    BraveNode* removedNode = list;
    list = list->next;
    free(removedNode);
    return list;
}

int main() {
    int size = 5;
    BraveNode* list = createList(size);
    for (int i = 0; i < size; i++) {
        list = insertAtEnd(list, i + 1);
    }
    printList(list);

    list = removeAtStart(list);
    printList(list);

    list = removeAtEnd(list);
    printList(list);

    return 0;
}