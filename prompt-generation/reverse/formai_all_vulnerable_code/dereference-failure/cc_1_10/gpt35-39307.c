//FormAI DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* current = head;
    printf("[");
    while (current != NULL) {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

void insertAtBeginning(struct node** head, int num) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
    printf("%d is inserted at the beginning of the list.\n", num);
}

void insertAtEnd(struct node** head, int num) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        printf("%d is inserted at the end of the list.\n", num);
    }
}

void deleteNode(struct node** head, int target) {
    bool found = false;
    struct node* current = *head;
    if (current == NULL) {
        printf("List is already empty.\n");
    } else if (current->data == target) {
        *head = current->next;
        free(current);
        printf("%d is deleted from the list.\n", target);
    } else {
        while (current->next != NULL) {
            if (current->next->data == target) {
                found = true;
                struct node* toDelete = current->next;
                current->next = toDelete->next;
                free(toDelete);
                printf("%d is deleted from the list.\n", target);
                break;
            }
            current = current->next;
        }
        if (!found) {
            printf("%d is not found in the list.\n", target);
        }
    }
}

void reverseList(struct node** head) {
    struct node* previous = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
    printf("The list is reversed.\n");
}

int main() {
    struct node* head = NULL;
    int choice, num;
    printf("Futuristic Linked List Operations\n");
    do {
        printf("\n1. Insert at the beginning");
        printf("\n2. Insert at the end");
        printf("\n3. Delete a node");
        printf("\n4. Print the list");
        printf("\n5. Reverse the list");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &num);
                insertAtBeginning(&head, num);
                break;
            case 2:
                printf("Enter a number to insert: ");
                scanf("%d", &num);
                insertAtEnd(&head, num);
                break;
            case 3:
                printf("Enter a number to delete: ");
                scanf("%d", &num);
                deleteNode(&head, num);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.");
        }
    } while (choice != 6);
    return 0;
}