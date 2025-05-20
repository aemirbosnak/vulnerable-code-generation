//FormAI DATASET v1.0 Category: Linked list operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void append(int data) {
    if (head == NULL) {
        head = malloc(sizeof(struct Node));
        head->data = data;
        head->next = NULL;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = malloc(sizeof(struct Node));
        current->next->data = data;
        current->next->next = NULL;
    }
}

void removeNode(int data) {
    if (head == NULL) {
        return;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Node* current = head;
        while (current->next != NULL && current->next->data != data) {
            current = current->next;
        }
        if (current->next != NULL) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

void printList() {
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    append(1);
    append(2);
    append(3);
    append(4);
    append(5);

    printf("Original List:\n");
    printList();

    removeNode(3);
    removeNode(1);

    printf("Updated list:\n");
    printList();

    return 0;
}