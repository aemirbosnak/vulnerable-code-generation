//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createList() {
    Node *head = NULL;

    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    return head;
}

void insertNode(Node *head, int data) {
    Node *current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = (Node*)malloc(sizeof(Node));
    current->next->data = data;
    current->next->next = NULL;
}

void deleteNode(Node *head, int data) {
    Node *current = head;
    Node *previous = NULL;

    while(current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if(current == NULL) {
        printf("Node is not found!\n");
        return;
    }

    previous->next = current->next;
    free(current);
}

void displayList(Node *head) {
    Node *current = head->next;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int choice = 0;
    int data = 0;
    Node *head = NULL;

    head = createList();

    do {
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}