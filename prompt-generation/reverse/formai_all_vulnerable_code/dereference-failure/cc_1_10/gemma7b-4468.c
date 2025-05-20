//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
    int data;
    struct Node* next;
};

void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverseList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Multiplayer interaction
    int choice, data;
    printf("Enter your choice: (1) Insert at tail, (2) Traverse list\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtTail(&head, data);
            break;
        case 2:
            traverseList(head);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}