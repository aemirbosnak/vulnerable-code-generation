//FormAI DATASET v1.0 Category: Linked list operations ; Style: mathematical
// Linked List Operations in a Mathematical Style

#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* create(int data);
void insert(Node** head, int data);
void display(Node* head);
int search(Node* head, int key);
void delete(Node** head, int data);

// Main function
int main() {
    Node* head = NULL;
    int choice = 0;

    printf("\n========================================");
    printf("\n       Linked List Operations in        ");
    printf("\n              Mathematical Style        ");
    printf("\n========================================");

    while (choice != 5) {
        printf("\n\nChoose an operation:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter value to be inserted: ");
            int value;
            scanf("%d", &value);
            insert(&head, value);
            break;

        case 2:
            printf("\nEnter value to be deleted: ");
            int val;
            scanf("%d", &val);
            delete(&head, val);
            break;

        case 3:
            printf("\nEnter value to be searched: ");
            int key;
            scanf("%d", &key);
            int pos = search(head, key);

            if (pos == -1) {
                printf("\n%d is not in the list.\n", key);
            } else {
                printf("\n%d found at position %d.\n", key, pos);
            }
            break;

        case 4:
            display(head);
            break;

        case 5:
            printf("\nExiting Linked List Operations...\n");
            break;

        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return 0;
}

// Create a new node
Node* create(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a new node at the end of the list
void insert(Node** head, int data) {
    Node* node = create(data);

    if (*head == NULL) {
        *head = node;
    } else {
        Node* temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = node;
    }

    printf("\n%d inserted successfully.\n", data);
}

// Display the list
void display(Node* head) {
    printf("\nThe list is:");

    if (head == NULL) {
        printf(" empty.\n");
    } else {
        while (head != NULL) {
            printf(" %d", head->data);
            head = head->next;
        }

        printf("\n");
    }
}

// Search for a value in the list
int search(Node* head, int key) {
    int pos = -1;
    int count = 0;

    while (head != NULL) {
        count++;

        if (head->data == key) {
            pos = count;
            break;
        }

        head = head->next;
    }

    return pos;
}

// Delete a node with a given value from the list
void delete(Node** head, int data) {
    Node* current = *head;
    Node* prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (current->data == data) {
            found = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    if (found) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
        printf("\n%d deleted successfully.\n", data);
    } else {
        printf("\n%d not found in the list.\n", data);
    }
}