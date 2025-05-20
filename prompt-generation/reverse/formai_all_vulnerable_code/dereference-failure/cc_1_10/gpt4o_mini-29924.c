//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->data, data, sizeof(newNode->data));
    newNode->next = NULL;
    return newNode;
}

void append(LinkedList* list, const char* data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    free(list);
}

Node* search(LinkedList* list, const char* key) {
    Node* current = list->head;
    while (current != NULL) {
        if (strcmp(current->data, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteNode(LinkedList* list, const char* key) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->data, key) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Node with data '%s' not found.\n", key);
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Node with data '%s' deleted.\n", key);
}

void insertAfter(LinkedList* list, const char* target, const char* newData) {
    Node* newNode = createNode(newData);
    Node* current = search(list, target);
    if (current == NULL) {
        printf("Node with data '%s' not found.\n", target);
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("Inserted node with data '%s' after '%s'.\n", newData, target);
}

int main() {
    LinkedList* list = createLinkedList();

    append(list, "Node 1");
    append(list, "Node 2");
    append(list, "Node 3");
    
    printList(list);

    printf("\nSearching for 'Node 2':\n");
    Node* foundNode = search(list, "Node 2");
    if (foundNode != NULL) {
        printf("Found node with data: %s\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    printf("\nInserting 'Node 1.5' after 'Node 1':\n");
    insertAfter(list, "Node 1", "Node 1.5");
    printList(list);

    printf("\nDeleting 'Node 2':\n");
    deleteNode(list, "Node 2");
    printList(list);

    printf("\nDeleting 'Node 3':\n");
    deleteNode(list, "Node 3");
    printList(list);

    freeList(list);
    return 0;
}