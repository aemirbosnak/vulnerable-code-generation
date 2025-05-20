//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

//node structure for linked list
struct node{
    char name[30];
    int ph_no;
    struct node* next;
};

struct node* start=NULL; //initialize start pointer to NULL

void insert(){
    struct node* new_node=(struct node*)malloc(sizeof(struct node)); //dynamic memory allocation for new node
    printf("\nEnter name: ");
    scanf("%s",new_node->name);
    printf("Enter phone number: ");
    scanf("%d",&new_node->ph_no);
    new_node->next=NULL;
    if(start==NULL){
        start=new_node;
    }
    else{
        struct node* temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    printf("\nNode inserted successfully!");
}

void delete(){
    char name[30];
    printf("\nEnter name to be deleted: ");
    scanf("%s",name);
    struct node* temp=start;
    struct node* prev=NULL;
    while(temp!=NULL && strcmp(temp->name,name)!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("\nNode not found!");
    }
    else{
        if(prev==NULL){
            start=temp->next;
        }
        else{
            prev->next=temp->next;
        }
        free(temp);
        printf("\nNode deleted successfully!");
    }
}

void search(){
    char name[30];
    printf("\nEnter name to be searched: ");
    scanf("%s",name);
    struct node* temp=start;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0){
            printf("\nPhone number: %d",temp->ph_no);
        }
        temp=temp->next;
    }
}

void display(){
    struct node* temp=start;
    while(temp!=NULL){
        printf("\nName: %s, Phone number: %d",temp->name,temp->ph_no);
        temp=temp->next;
    }
}

int main(){
    int choice;
    do{
        printf("\n\nPhone Book\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=5);
    return 0;
}