//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;
Node* temp = NULL;

void invasiveInsert(int data, int position) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        current = head;
        for (int i = 0; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void invasiveDelete(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == data) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Data not found\n");
        return;
    }

    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void printList() {
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    invasiveInsert(3, 0);
    invasiveInsert(5, 1);
    invasiveInsert(2, 0);
    invasiveInsert(7, 3);
    invasiveInsert(4, 2);

    printf("Linked List: ");
    printList();

    invasiveDelete(5);
    printf("After deleting 5: ");
    printList();

    invasiveDelete(2);
    printf("After deleting 2: ");
    printList();

    return 0;
}