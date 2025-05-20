//FormAI DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

/* Function to create a new node */
struct node * newNode(int data){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/* Function to insert a node at the end of the linked list */
void append(struct node **head_ref, int data){
    struct node *new_node = newNode(data);

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    struct node *tail = *head_ref;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new_node;
}

/* Function to insert a node at the beginning of the linked list */
void push(struct node **head_ref, int data){
    struct node *new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to insert a node after a given node */
void insertAfter(struct node *prev_node, int data){
    if(prev_node == NULL){
        printf("Previous node cannot be null");
        return;
    }

    struct node *new_node = newNode(data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

/* Function to delete a node with given data */
void delete(struct node **head_ref, int data){
    struct node *temp = *head_ref, *prev;

    if(temp != NULL && temp->data == data){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        printf("Data not found");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

/* Function to print the linked list */
void printList(struct node *node){
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

/* Main function to test the above functions */
int main(){
    struct node *head = NULL;

    printf("Inserting 10, 20, 30 in the linked list\n");
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printList(head);
    printf("\n\n");

    printf("Inserting 40 at the beginning of the linked list\n");
    push(&head, 40);
    printList(head);
    printf("\n\n");

    printf("Inserting 50 after node 20 in the linked list\n");
    insertAfter(head->next, 50);
    printList(head);
    printf("\n\n");

    printf("Deleting node with data 40 from the linked list\n");
    delete(&head, 40);
    printList(head);
    printf("\n\n");

    printf("Deleting node with data 30 from the linked list\n");
    delete(&head, 30);
    printList(head);
    printf("\n\n");

    printf("Deleting node with data 60 from the linked list\n");
    delete(&head, 60);
    printList(head);
    printf("\n\n");

    return 0;
}