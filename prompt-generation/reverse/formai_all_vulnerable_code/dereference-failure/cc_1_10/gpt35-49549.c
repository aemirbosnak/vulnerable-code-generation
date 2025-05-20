//FormAI DATASET v1.0 Category: Data structures visualization ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    int count;
} List;

// Function to initialize the list
void initialize(List* list) {
    list->count = 0;
    list->head = NULL;
}

// Function to add a node to the list
void add(List* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    }
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    list->count++;
}

// Function to remove a node from the list
void removeNode(List* list, int data) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            list->count--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the list
void print(List* list) {
    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List list;
    initialize(&list);
    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    print(&list);
    removeNode(&list, 2);
    print(&list);
    return 0;
}