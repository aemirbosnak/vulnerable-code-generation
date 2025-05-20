//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int search(struct Node* head, int data) {
    struct Node* curr = head;
    while (curr!= NULL) {
        if (curr->data == data) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void deleteNode(struct Node** head, int data) {
    struct Node* prev = NULL;
    struct Node* curr = *head;

    if (curr!= NULL && curr->data == data) {
        *head = curr->next;
        free(curr);
        return;
    }

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        return;
    }

    prev->next = curr->next;
    free(curr);
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice:\n1. Add a node\n2. Search for a node\n3. Delete a node\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Node found!\n");
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}