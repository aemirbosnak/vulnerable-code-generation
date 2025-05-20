//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>

struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
};

struct LinkedList {
    struct LinkedListNode* head;
    int size;
};

void addElement(struct LinkedList* list, int value) {
    struct LinkedListNode* newNode = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct LinkedListNode* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void deleteElement(struct LinkedList* list, int value) {
    struct LinkedListNode* current = list->head;
    struct LinkedListNode* previous = NULL;

    while (current!= NULL && current->value!= value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found in the list.\n");
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

void printList(struct LinkedList* list) {
    struct LinkedListNode* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int searchElement(struct LinkedList* list, int value) {
    struct LinkedListNode* current = list->head;
    while (current!= NULL && current->value!= value) {
        current = current->next;
    }
    if (current == NULL) {
        return -1;
    } else {
        return current - list->head;
    }
}

int main() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;

    addElement(list, 10);
    addElement(list, 20);
    addElement(list, 30);
    addElement(list, 40);

    printf("List before deletion: ");
    printList(list);

    deleteElement(list, 10);

    printf("\nList after deletion: ");
    printList(list);

    int index = searchElement(list, 20);
    if (index == -1) {
        printf("Element not found in the list.\n");
    } else {
        printf("Element found at index %d.\n", index);
    }

    return 0;
}