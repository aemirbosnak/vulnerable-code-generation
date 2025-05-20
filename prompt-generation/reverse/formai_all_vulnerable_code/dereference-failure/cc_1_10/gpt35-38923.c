//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    int count;
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->count = 0;
    list->head = NULL;
    return list;
}

void deleteLinkedList(LinkedList* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}

void addNode(LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->count++;
}

void* removeNode(LinkedList* list, int index) {
    if (index < 0 || index >= list->count) {
        return NULL;
    }
    void* data;
    Node* current = list->head;
    if (index == 0) {
        list->head = current->next;
        data = current->data;
        free(current);
        list->count--;
        return data;
    }
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    data = temp->data;
    free(temp);
    list->count--;
    return data;
}

int main() {
    // Create a LinkedList that stores integers
    LinkedList* intList = createLinkedList();

    // Add some integers
    int* num1 = (int*)malloc(sizeof(int));
    *num1 = 10;
    addNode(intList, num1);

    int* num2 = (int*)malloc(sizeof(int));
    *num2 = 20;
    addNode(intList, num2);

    int* num3 = (int*)malloc(sizeof(int));
    *num3 = 30;
    addNode(intList, num3);

    // Remove an integer
    int* removed = (int*)removeNode(intList, 1);
    if (removed != NULL) {
        printf("Removed: %d\n", *removed);
        free(removed);
    }

    // Print the remaining integers
    Node* current = intList->head;
    while (current != NULL) {
        printf("%d\n", *(int*)current->data);
        current = current->next;
    }

    // Clean up memory
    deleteLinkedList(intList);

    return 0;
}