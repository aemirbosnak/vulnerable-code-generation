//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
/* Program to visualize the Linked List data structure */

#include<stdio.h>
#include<stdlib.h>

//defining the node structure
struct node{
    int data;
    struct node *next;
};

// Function to display the Linked List
void display(struct node *head){
    printf("Linked List: ");
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the Linked List
struct node *insert_at_beginning(struct node *head, int data){
    printf("Inserting %d at the beginning\n", data);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the Linked List
struct node *insert_at_end(struct node *head, int data){
    printf("Inserting %d at the end\n", data);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        return newNode;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Driver Code
int main(){
    struct node *head = NULL;
    printf("Initial Linked List:\n");
    display(head);

    head = insert_at_beginning(head, 35);
    display(head);

    head = insert_at_end(head, 22);
    display(head);

    head = insert_at_beginning(head, 16);
    display(head);

    return 0;
}