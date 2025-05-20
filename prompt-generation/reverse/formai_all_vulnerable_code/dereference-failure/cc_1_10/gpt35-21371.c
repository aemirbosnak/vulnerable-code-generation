//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    } else {
        struct node *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void delete(struct node **head, int key) {
    if(*head == NULL) {
        return;
    } 

    if((*head)->data == key) {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = NULL;
    struct node *current = *head;
    while(current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if(current == NULL) {
        return;
    }

    prev->next = current->next;
    free(current);
}

int main() {
    struct node *head = NULL;
    int choice = 0;
    int data;

    printf("Hi there, I am a Linked List program created just for you!\n\n");

    while(choice != 4) {
        printf("Please select your operation:\n");
        printf("1. Insert element\n2. Delete element\n3. Display list\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Inserted successfully!\n\n");
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &data);
                delete(&head, data);
                printf("Deleted successfully!\n\n");
                break;
            case 3:
                printf("The list is: ");
                display(head);
                printf("\n");
                break;
            case 4:
                printf("Goodbye my love! See you soon.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}