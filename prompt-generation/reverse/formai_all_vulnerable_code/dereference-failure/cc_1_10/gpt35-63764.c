//FormAI DATASET v1.0 Category: Data structures visualization ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

struct node {   // defining a node structure for linked list
    int data;
    struct node *next;
};

void display(struct node *head) {   // function to display the linked list
    printf("Linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void push(struct node **head, int data) {   // function to add data to the beginning of the linked list
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
    display(*head);
}

void insert(struct node **head, int data, int pos) {   // function to insert data at a particular position in the linked list
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    struct node *temp = (*head);
    for(int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    display(*head);
}

void append(struct node **head, int data) {   // function to add data to the end of the linked list
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = (*head);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    display(*head);
}

void delete(struct node **head, int pos) {   // function to delete data from a particular position in the linked list
    struct node *temp = (*head);
    if(pos == 1) {
        (*head) = temp->next;
        free(temp);
    }
    else {
        for(int i = 1; i < pos-1; i++) {
            temp = temp->next;
        }
        struct node *del_node = temp->next;
        temp->next = del_node->next;
        free(del_node);
    }
    display(*head);
}

int main() {
    struct node *head = NULL;   // starting the linked list with NULL
    push(&head, 5);   // adding 5 to the beginning of the linked list
    append(&head, 10);   // adding 10 to the end of the linked list
    insert(&head, 8, 2);   // inserting 8 at position 2 in the linked list
    delete(&head, 2);   // deleting data at position 2 in the linked list
    return 0;
}