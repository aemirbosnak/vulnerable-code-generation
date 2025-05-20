//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int val){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    } else{
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void printList(struct node *head){
    if(head == NULL){
        printf("List is empty\n");
    } else{
        struct node *temp = head;
        printf("List: ");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct node *head = NULL;
    
    //Inserting cells with values 1, 2 and 3
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    //Printing the list
    printList(head);

    return 0;
}