//FormAI DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

//Global Variables
struct node *head=NULL;
struct node *tail=NULL;

//Functions
void createNode(int data) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL) {
        head=temp;
        tail=temp;
        temp=NULL;
    } else {
        tail->next=temp;
        tail=temp;
    }
}

void displayNodes() {
    struct node *temp=head;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insertAtStart(int data) {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}

int length(){
    int length=0;
    struct node *temp=head;

    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    return length;
}

void deleteAtIndex(int index) {
    int i;
    struct node *current=head;
    struct node *prev=NULL;

    if(index > length()) {
        printf("Invalid Index. Please try again!");
        return;
    }

    if(index==1) {
        head=current->next;
        free(current);
        return;
    } else {
        for(i=1;i<index;i++) {
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        free(current);
    }
}

void reverse() {
    struct node *current=head;
    struct node *prev=NULL;
    struct node *temp=NULL;

    while(current!=NULL) {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
}

// Driver Function
int main() {
    createNode(5);
    createNode(8);
    insertAtStart(2);
    insertAtStart(1);
    deleteAtIndex(3);
    reverse();
    displayNodes();
    return 0;
}