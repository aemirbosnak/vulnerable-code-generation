//FormAI DATASET v1.0 Category: Data structures visualization ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

//creating a linked list structure
struct node{
    int data;
    struct node* link;
};

//function to create a new node
struct node* create(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    return temp;
}

//function to insert element at the beginning of the linked list
void insert_at_beginning(struct node** head, int x){
    struct node* temp = create(x);
    temp->link = *head;
    *head = temp;
}

//function to insert element at the end of the linked list
void insert_at_end(struct node** head, int x){
    if(*head==NULL){
        insert_at_beginning(head, x);
        return;
    }
    struct node* temp = *head;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = create(x);
}

//function to delete the first occurrence of the given element in the linked list
void delete_element(struct node** head, int x){
    struct node* temp = *head;
    if(temp==NULL){
        return;
    }
    if(temp->data==x){
        *head = (*head)->link;
        free(temp);
        return;
    }
    while(temp->link!=NULL && temp->link->data!=x){
        temp = temp->link;
    }
    if(temp->link==NULL){
        return;
    }
    struct node* del = temp->link;
    temp->link = del->link;
    free(del);
}

//function to display the linked list
void display(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main(){
    //creating an empty linked list
    struct node* head = NULL;
    printf("Initial Linked List: ");
    display(head);

    printf("\nInserting elements...\n");
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_end(&head, 40);
    printf("Linked List after insertion: ");
    display(head);

    printf("\nDeleting an element...\n");
    delete_element(&head, 20);
    printf("Linked List after deletion: ");
    display(head);

    return 0;
}