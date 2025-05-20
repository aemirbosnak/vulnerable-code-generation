//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list structure
Node* createLinkedList() {
    Node* head = NULL;
    Node* current = NULL;
    int size = 0;
    int choice;

    do {
        printf("Enter 1 to add an element, 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int element;
            printf("Enter the element: ");
            scanf("%d", &element);

            if (size == 0) {
                head = (Node*) malloc(sizeof(Node));
                head->data = element;
                head->next = NULL;
            } else {
                current = head;
                while (current->next!= NULL) {
                    current = current->next;
                }
                current->next = (Node*) malloc(sizeof(Node));
                current->next->data = element;
                current->next->next = NULL;
            }

            size++;
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    } while (1);

    return head;
}

// Function to search for an element in the linked list
int search(Node* head, int element) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == element) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Main function
int main() {
    Node* linkedList = createLinkedList();
    int elementToSearch;

    printf("Enter the element to search: ");
    scanf("%d", &elementToSearch);

    if (search(linkedList, elementToSearch)) {
        printf("Element found!\n");
    } else {
        printf("Element not found.\n");
    }

    return 0;
}