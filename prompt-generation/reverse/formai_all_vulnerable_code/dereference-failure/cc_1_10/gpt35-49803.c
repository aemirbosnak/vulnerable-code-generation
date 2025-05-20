//FormAI DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

void printList(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtBeginning(struct Node **head, int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*head);
    (*head) = newnode;
}

void insertAtEnd(struct Node **head, int data){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct Node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

int main(){

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtEnd(&head, 50);

    printf("Linked List: ");
    printList(head);

    return 0;
}