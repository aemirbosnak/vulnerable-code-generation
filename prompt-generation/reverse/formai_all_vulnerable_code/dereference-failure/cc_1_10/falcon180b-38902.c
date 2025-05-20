//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

/* Node structure definition */
struct node{
    int data;
    struct node* next;
};

/* Function to create a new node with given data */
struct node* newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Function to add a node at the beginning of the list */
void push(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to add a node at the end of the list */
void append(struct node** head_ref, int new_data){
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

    if(*head_ref == NULL){
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while(last->next!= NULL){
        last = last->next;
    }

    last->next = new_node;
    return;
}

/* Function to add a node at a specific position in the list */
void insertNode(struct node* prev_node, int new_data){
    if(prev_node == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }

    struct node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return;
}

/* Function to delete a node from the list */
void deleteNode(struct node **head_ref, struct node* del){
    struct node* temp = *head_ref;

    if(temp == NULL || temp == del){
        *head_ref = del->next;
        free(del);
        return;
    }

    while(temp->next!= del){
        temp = temp->next;
    }

    temp->next = del->next;
    free(del);
    return;
}

/* Function to print the list */
void printList(struct node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct node* head = NULL;

    /* Adding nodes at the beginning */
    push(&head, 10);
    push(&head, 20);

    /* Adding nodes at the end */
    append(&head, 30);
    append(&head, 40);

    /* Adding nodes at a specific position */
    struct node* third = head->next->next;
    insertNode(third, 50);

    /* Printing the list */
    printf("Created Linked List: ");
    printList(head);

    return 0;
}