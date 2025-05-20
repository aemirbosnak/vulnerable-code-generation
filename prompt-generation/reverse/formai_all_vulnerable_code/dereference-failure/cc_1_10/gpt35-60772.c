//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>

struct node {     // define the structure for the nodes
    int data;
    struct node* next;
};

void printList(struct node* head) {      // function to print the linked list
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insert(struct node** head, int value) {       // function to insert a node at the beginning of the linked list
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("\nAdded %d to the beginning of the list.\n", value);
}

void deleteNode(struct node** head, int key) {     // function to delete a node from the linked list
    struct node* temp = *head, *prev;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("\nDeleted %d from the list.\n", key);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\n%d not found.\n", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nDeleted %d from the list.\n", key);
}

int main() {
    struct node* head = NULL;     // create the head pointer, initially pointing to NULL
    int choice, value;
    while (1) {     // infinite loop for menu-driven program
        printf("\nLinked List Visualization\n");
        printf("1. Insert a new node at the beginning of the list\n");
        printf("2. Delete a node from the list\n");
        printf("3. Print the list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {     // switch case for various choices
            case 1: 
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("\nCurrent List: ");
                printList(head);
                printf("\n");
                break;
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}