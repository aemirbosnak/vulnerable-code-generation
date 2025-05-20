//FormAI DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void display(struct node *head){
    struct node *temp=NULL;
    temp=head;
    printf("List:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insert_at_beginning(struct node **head,int value){
    struct node *new_node=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(*head==NULL){
        new_node->data=value;
        new_node->next=NULL;
        *head=new_node;
    }
    else{
        new_node->data=value;
        new_node->next=*head;
        *head=new_node;
    }
}

void delete_from_beginning(struct node **head){
    struct node *temp=NULL;
    temp=*head;
    if(*head==NULL){
        printf("List is Empty\n");
        return;
    }
    else{
        *head=temp->next;
        temp->next=NULL;
        free(temp);
    }
}

void insert_at_end(struct node **head,int value){
    struct node *new_node=NULL;
    struct node *temp=NULL;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(*head==NULL){
        new_node->data=value;
        new_node->next=NULL;
        *head=new_node;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        new_node->data=value;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void delete_from_end(struct node **head){
    struct node *temp=NULL;
    struct node *prev=NULL;
    temp=*head;
    if(*head==NULL){
        printf("List is Empty\n");
        return;
    }
    else{
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

void insert_at_n_position(struct node **head,int value,int position){
    struct node *new_node=NULL;
    struct node *temp=NULL;
    int count=1;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(*head==NULL){
        printf("List is Empty\n");
        return;
    }
    else{
        temp=*head;
        while(count<position-1 && temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        new_node->data=value;
        new_node->next=temp->next;
        temp->next=new_node;
    }
}

void delete_from_n_position(struct node **head,int position){
    struct node *temp=NULL;
    struct node *prev=NULL;
    int count=1;
    temp=*head;
    if(*head==NULL){
        printf("List is Empty\n");
        return;
    }
    if(position==1){
        *head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else{
        while(count<position && temp->next!=NULL){
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(count==position){
            prev->next=temp->next;
            temp->next=NULL;
            free(temp);
        }
    }
}

void main(){
    struct node *head=NULL;
    int option,value,position;

    while(1){
        printf("Enter the option:\n");
        printf("1.Insert at beginning\n");
        printf("2.Delete from beginning\n");
        printf("3.Insert at end\n");
        printf("4.Delete from end\n");
        printf("5.Insert at n position\n");
        printf("6.Delete from n position\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        scanf("%d",&option);

        switch(option){
            case 1: printf("Insert the value to be added at beginning:");
                    scanf("%d",&value);
                    insert_at_beginning(&head,value);
                    break;
            case 2: delete_from_beginning(&head);
                    break;
            case 3: printf("Insert the value to be added at end:");
                    scanf("%d",&value);
                    insert_at_end(&head,value);
                    break;
            case 4: delete_from_end(&head);
                    break;
            case 5: printf("Insert the value to be added:");
                    scanf("%d",&value);
                    printf("Insert the position to be inserted:");
                    scanf("%d",&position);
                    insert_at_n_position(&head,value,position);
                    break;
            case 6: printf("Insert the position to be deleted:");
                    scanf("%d",&position);
                    delete_from_n_position(&head,position);
                    break;
            case 7: display(head);
                    break;
            case 8: exit(0);
        }
    }
}