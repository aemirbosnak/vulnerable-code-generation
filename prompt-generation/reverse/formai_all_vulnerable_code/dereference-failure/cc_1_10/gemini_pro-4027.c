//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[20];
    char room_no[5];
    char arrival_date[11];
    char departure_date[11];
    struct node *next;
}node;

node *head=NULL;

void insert_guest(){
    node *temp=(node*)malloc(sizeof(node));
    printf("Enter name: ");
    scanf(" %[^\n]%*c",temp->name);
    printf("Enter room no: ");
    scanf(" %s%*c",temp->room_no);
    printf("Enter arrival date (dd/mm/yyyy): ");
    scanf(" %s%*c",temp->arrival_date);
    printf("Enter departure date (dd/mm/yyyy): ");
    scanf(" %s%*c",temp->departure_date);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }else{
        node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
    printf("\nGuest added successfully.\n");
}

void display_guests(){
    if(head==NULL){
        printf("\nNo guests found.\n");
    }else{
        node *ptr=head;
        printf("\nGuests:\n");
        printf("%-20s%-5s%-11s%-11s\n","Name","Room No.","Arrival Date","Departure Date");
        while(ptr!=NULL){
            printf("%-20s%-5s%-11s%-11s\n",ptr->name,ptr->room_no,ptr->arrival_date,ptr->departure_date);
            ptr=ptr->next;
        }
    }
}

void search_guest(){
    char name[20];
    printf("Enter name: ");
    scanf(" %[^\n]%*c",name);
    node *ptr=head;
    int found=0;
    while(ptr!=NULL){
        if(strcmp(ptr->name,name)==0){
            printf("\nGuest found:\n");
            printf("%-20s%-5s%-11s%-11s\n","Name","Room No.","Arrival Date","Departure Date");
            printf("%-20s%-5s%-11s%-11s\n",ptr->name,ptr->room_no,ptr->arrival_date,ptr->departure_date);
            found=1;
            break;
        }
        ptr=ptr->next;
    }
    if(found==0){
        printf("\nGuest not found.\n");
    }
}

void update_guest(){
    char name[20];
    printf("Enter name: ");
    scanf(" %[^\n]%*c",name);
    node *ptr=head;
    int found=0;
    while(ptr!=NULL){
        if(strcmp(ptr->name,name)==0){
            printf("\nEnter new arrival date (dd/mm/yyyy): ");
            scanf(" %s%*c",ptr->arrival_date);
            printf("Enter new departure date (dd/mm/yyyy): ");
            scanf(" %s%*c",ptr->departure_date);
            printf("\nGuest updated successfully.\n");
            found=1;
            break;
        }
        ptr=ptr->next;
    }
    if(found==0){
        printf("\nGuest not found.\n");
    }
}

void delete_guest(){
    char name[20];
    printf("Enter name: ");
    scanf(" %[^\n]%*c",name);
    node *ptr=head;
    node *prev=NULL;
    int found=0;
    while(ptr!=NULL){
        if(strcmp(ptr->name,name)==0){
            if(prev==NULL){
                head=ptr->next;
            }else{
                prev->next=ptr->next;
            }
            free(ptr);
            printf("\nGuest deleted successfully.\n");
            found=1;
            break;
        }
        prev=ptr;
        ptr=ptr->next;
    }
    if(found==0){
        printf("\nGuest not found.\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1. Insert guest\n2. Display guests\n3. Search guest\n4. Update guest\n5. Delete guest\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                update_guest();
                break;
            case 5:
                delete_guest();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}