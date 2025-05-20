//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
    printf("%d inserted successfully.\n", data);
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("%d deleted successfully.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("%d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully.\n", key);
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(Node** head) {
    Node* current = *head, *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("List deleted successfully.\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key;
    while (1) {
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Delete the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                deleteList(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}