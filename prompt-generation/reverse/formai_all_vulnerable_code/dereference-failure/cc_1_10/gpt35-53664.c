//FormAI DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head;

void insert(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void removeNode(int x) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* current = head;
    Node* previous = NULL;
    while (current != NULL && current->data != x) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

void printList() {
    Node* current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    printf("Welcome to the futuristic linked list program!\n");
    while (1) {
        printf("Please enter an option:\n");
        printf("1. Insert a node\n");
        printf("2. Remove a node\n");
        printf("3. Print the list\n");
        int choice, value;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Please enter the value to insert:\n");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Please enter the value to remove:\n");
                scanf("%d", &value);
                removeNode(value);
                break;
            case 3:
                printList();
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}