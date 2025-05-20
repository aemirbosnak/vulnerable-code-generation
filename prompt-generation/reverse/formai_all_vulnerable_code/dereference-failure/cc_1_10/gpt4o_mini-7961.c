//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}

void deleteNode(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted node with value %d from the list.\n", key);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node with value %d from the list.\n", key);
}

void searchNode(int key) {
    struct Node* temp = head;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == key) {
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (found) {
        printf("Node with value %d found in the list.\n", key);
    } else {
        printf("Node with value %d not found in the list.\n", key);
    }
}

void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void menu() {
    printf("\nLinked List Operations:\n");
    printf("1. Insert at End\n");
    printf("2. Delete Node\n");
    printf("3. Search Node\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, data;
    
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchNode(data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                free(head);  // Free the memory (simple way, to be improved)
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}