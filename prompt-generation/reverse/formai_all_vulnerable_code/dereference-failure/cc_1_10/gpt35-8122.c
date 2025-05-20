//FormAI DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *head = NULL;

void insert(node **head_ptr) {
    int num;
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter the number: ");
    scanf("%d", &num);
    temp->data = num;
    if(*head_ptr == NULL) {
        *head_ptr = temp;
        (*head_ptr)->next = NULL;
    } else {
        temp->next = *head_ptr;
        *head_ptr = temp;
    }
}

void delete(node **head_ptr) {
    if(*head_ptr == NULL) {
        printf("List is empty\n");
        return;
    } else {
        *head_ptr = (*head_ptr)->next;
    }
}

void search(node **head_ptr) {
    if(*head_ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    int num, found = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    node *temp = *head_ptr;
    while(temp != NULL) {
        if(temp->data == num) {
            printf("Number Found!\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(!found) {
        printf("Number not found\n");
    }
}

void display(node **head_ptr) {
    node *temp = *head_ptr;
    if(*head_ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    do {
        printf("*** Linked List Menu ***\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert(&head);
                break;
            case 2:
                delete(&head);
                break;
            case 3:
                search(&head);
                break;
            case 4:
                display(&head);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);
    return 0;
}