//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    int data;
    struct node* link;
};

struct node* start=NULL;

void insert(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->link=NULL;
    if(start==NULL){
        start=new_node;
    }
    else{
        struct node* last=start;
        while(last->link!=NULL){
            last=last->link;
        }
        last->link=new_node;
    }
}

void delete(int data){
    struct node* temp=start;
    struct node* prev=NULL;
    if(temp!=NULL && temp->data==data){
        start=temp->link;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data){
        prev=temp;
        temp=temp->link;
    }
    if(temp==NULL){
        return;
    }
    prev->link=temp->link;
    free(temp);
}

void search(int data){
    struct node* temp=start;
    if(temp==NULL || temp->data==data){
        printf("\nElement found in the list!");
    }
    else{
        while(temp!=NULL && temp->data!=data){
            temp=temp->link;
        }
        if(temp==NULL){
            printf("\nElement not found in the list!");
        }
        else{
            printf("\nElement found in the list!");
        }
    }
}

void display(){
    struct node* temp=start;
    if(temp==NULL){
        printf("\nList is empty!");
    }
    else{
        printf("\nList elements are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}

int main(){
    int choice,data;
    while(1){
        printf("\n\nLinked List Operations\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                printf("\nEnter the element to be deleted: ");
                scanf("%d",&data);
                delete(data);
                break;
            case 3:
                printf("\nEnter the element to be searched: ");
                scanf("%d",&data);
                search(data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}