//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->data!= data) {
            temp = temp->next;
        }
        if (temp!= NULL) {
            Node* prev = temp->next;
            temp->next = prev->next;
            free(prev);
        }
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add node\n2. Delete node\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add:\n");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to delete:\n");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}