//FormAI DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertAtFront(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    struct node *temp = *head;
    if(temp == NULL) {
        *head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtFront(struct node **head) {
    if(*head == NULL) {
        printf("Linked list is empty");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct node **head) {
    if(*head == NULL) {
        printf("Linked list is empty");
        return;
    } else if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        struct node *temp = *head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void display(struct node *head) {
    if(head == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, data;

    while(1) {
        printf("1. Insert at front\n2. Insert at end\n3. Delete at front\n4. Delete at end\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                deleteAtFront(&head);
                break;
            case 4:
                deleteAtEnd(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}