//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    if (*head == NULL) return;
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current) {
        if (current->data == key) return current;
        current = current->next;
    }
    return NULL;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert at end\n2. Delete node\n3. Search node\n4. Display list\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                Node* found = searchNode(head, data);
                if (found) {
                    printf("Node with data %d found.\n", found->data);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}