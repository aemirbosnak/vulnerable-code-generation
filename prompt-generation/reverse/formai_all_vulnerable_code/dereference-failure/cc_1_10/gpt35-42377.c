//FormAI DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define a structure to hold each email address and the next node
typedef struct email{
    char address[50];
    struct email* next;
}Email;

//function to add a new email to the mailing list
void add_email(Email** head, char* new_address){
    //allocate memory for new email node
    Email* new_email = (Email*)malloc(sizeof(Email));
    strcpy(new_email->address, new_address);
    new_email->next = NULL;

    //check if mailing list is empty
    if(*head == NULL){
        *head = new_email;
    }
    else{
        Email* current = *head;
        //iterate over the mailing list to add new email to the end
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_email;
    }
}

//function to remove an email from the mailing list
void remove_email(Email** head, char* address){
    //check if mailing list is empty
    if(*head == NULL){
        printf("Mailing list is empty!\n");
    }
    else{
        Email* current = *head;
        Email* previous = *head;
        //iterate over the mailing list to find the email to remove
        while(current != NULL && strcmp(current->address, address) != 0){
            previous = current;
            current = current->next;
        }
        //if email not found
        if(current == NULL){
            printf("Email address %s not found in mailing list!\n", address);
        }
        else{
            //if email found, update previous node's next pointer
            if(current == *head){
                *head = current->next;
            }
            else{
                previous->next = current->next;
            }
            printf("Email address %s removed from mailing list!\n", address);
            free(current);
        }
        
    }
}

//function to display the mailing list
void display_list(Email* head){
    //check if mailing list is empty
    if(head == NULL){
        printf("Mailing list is empty!\n");
    }
    else{
        printf("Mailing list:\n");
        Email* current = head;
        while(current != NULL){
            printf("%s\n", current->address);
            current = current->next;
        }
    }
}

int main(){
    int choice;
    char address[50];

    Email* head = NULL;

    do{
        printf("Mailing list manager\n");
        printf("--------------------\n");
        printf("1. Add email to mailing list\n");
        printf("2. Remove email from mailing list\n");
        printf("3. Display mailing list\n");
        printf("4. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter email address to add: ");
                scanf("%s", address);
                add_email(&head, address);
                break;
            case 2:
                printf("Enter email address to remove: ");
                scanf("%s", address);
                remove_email(&head, address);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                printf("Exiting program...Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    }while(choice != 4);

    return 0;
}