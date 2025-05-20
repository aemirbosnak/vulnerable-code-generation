//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head=NULL;//global head variable to keep track of linked list

void display(){
    printf("The linked list is: ");
    Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertAtBeginning(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    printf("%d inserted at the beginning of the list\n",data);
}

void insertAtEnd(int data){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        printf("%d inserted at the end of the empty list\n",data);
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    printf("%d inserted at the end of the list\n",data);
}

void deleteFromBeginning(){
    if(head==NULL){
        printf("Cannot delete from an empty list\n");
        return;
    }
    int dataToDelete=head->data;
    Node *temp=head;
    head=head->next;
    free(temp);//freeing the memory of the Node deleted
    printf("%d deleted from the beginning of the list\n",dataToDelete);
}

void deleteFromEnd(){
    if(head==NULL){
        printf("Cannot delete from an empty list\n");
        return;
    }
    int dataToDelete;
    if(head->next==NULL){//if there is only one Node in the list
        dataToDelete=head->data;
        free(head);
        head=NULL;
    }
    else{
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        dataToDelete=temp->next->data;
        free(temp->next);
        temp->next=NULL;
    }
    printf("%d deleted from the end of the list\n",dataToDelete);
}

int main(){
    printf("Welcome to the Linked List Operations program\n");
    printf("Let's insert some elements into the Linked list\n");
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display();
    printf("Now let's delete some elements from the Linked List\n");
    deleteFromBeginning();
    display();
    deleteFromEnd();
    display();
    printf("Thank you for using the Linked List Operations program\n");
    return 0;
}