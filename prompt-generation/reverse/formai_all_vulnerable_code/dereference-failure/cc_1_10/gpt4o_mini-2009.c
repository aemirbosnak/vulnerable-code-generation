//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* head = NULL;

void insertNode(const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(const char* value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->data, value) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value '%s' not found!\n", value);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Node with value '%s' deleted.\n", value);
}

void displayList() {
    Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main() {
    int choice;
    char value[100];

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after the integer input

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove newline
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0; // Remove newline
                deleteNode(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                freeList();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}