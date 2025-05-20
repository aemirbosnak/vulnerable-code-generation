//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createLinkedList(struct node** head_ref) {
    struct node *new_node, *temp;
    int choice;

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    new_node->data = 0;
    new_node->next = NULL;

    temp = *head_ref;
    while (temp!= NULL) {
        new_node->next = temp;
        new_node = temp;
        temp = temp->next;
    }
    *head_ref = new_node;
}

void printList(struct node *head) {
    struct node *temp;

    temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void appendElement(struct node **head_ref, int new_data) {
    struct node *new_node, *temp;

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;

    temp = *head_ref;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void deleteElement(struct node **head_ref, int data_to_delete) {
    struct node *temp, *prev;

    temp = *head_ref;
    prev = NULL;
    while (temp!= NULL && temp->data!= data_to_delete) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found in the list\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

void main() {
    struct node *head = NULL;
    createLinkedList(&head);
    printList(head);
    printf("\n");

    appendElement(&head, 5);
    appendElement(&head, 10);
    appendElement(&head, 15);
    printList(head);
    printf("\n");

    deleteElement(&head, 5);
    printList(head);
    printf("\n");
}