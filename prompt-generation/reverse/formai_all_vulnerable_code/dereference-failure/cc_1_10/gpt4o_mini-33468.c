//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtEnd(struct Node** head_ref, int new_data);
void deleteNode(struct Node** head_ref, int key);
void printList(struct Node* node);
void sortList(struct Node** head_ref);
void freeList(struct Node** head_ref);

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, data;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete a Node\n");
        printf("3. Print List\n");
        printf("4. Sort List\n");
        printf("5. Free List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter integer data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Linked List contents: ");
                printList(head);
                break;
            case 4:
                sortList(&head);
                printf("List sorted.\n");
                break;
            case 5:
                freeList(&head);
                printf("List freed.\n");
                head = NULL;
                break;
            case 6:
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to insert a new node with given data at the end of the list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to delete the first occurrence of a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Node with data %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", key);
}

// Function to print the contents of the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to sort the linked list using bubble sort
void sortList(struct Node** head_ref) {
    if (*head_ref == NULL) return;

    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to free the linked list
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head_ref = NULL;
}