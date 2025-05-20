//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node //node structure for the linked list
{
    char email[50];
    struct node* next;
}node;

node* head=NULL; //creating head pointer

//Function to add email to the list
void addEmail(char email[])
{
    node* temp= (node*) malloc(sizeof(node)); //creating new node
    strcpy(temp->email, email); //copying email to temp node
    temp->next=NULL; //initializing next pointer
    if(head==NULL)
    {
        head=temp; //if list is empty, head = temp
    }
    else
    {
        node* traverse=head;
        while(traverse->next!=NULL) //traversing to the last node
        {
            traverse=traverse->next;
        }
        traverse->next=temp; //adding temp node at the end
    }
    printf("Email added successfully!\n");
}

//Function to delete email from the list
void deleteEmail(char email[])
{
    if(head==NULL) //if list is empty
    {
        printf("The list is empty!\n");
        return;
    }
    node* traverse=head;
    node* prev=NULL;
    while(traverse!=NULL) //traversing through the list to find the email
    {
        if(strcmp(traverse->email,email)==0) //if email found
        {
            if(traverse==head) //if email is the first element
            {
                head=traverse->next;
            }
            else //if email is in the middle or end
            {
                prev->next=traverse->next;
            }
            free(traverse); //freeing the memory
            printf("Email deleted successfully!\n");
            return;
        }
        else
        {
            prev=traverse;
            traverse=traverse->next;
        }
    }
    printf("The email is not found in the list!\n"); //if email not found
}

//Function to display the list
void displayList()
{
    if(head==NULL) //if list is empty
    {
        printf("The list is empty!\n");
        return;
    }
    printf("The email list is:\n");
    node* traverse=head;
    while(traverse!=NULL) //traversing through the list to display the email
    {
        printf("%s\n", traverse->email);
        traverse=traverse->next;
    }
}

//main function
int main()
{
    int choice;
    char email[50];
    while(1) //menu for the mailing list manager
    {
        printf("Enter your choice:\n");
        printf("1. Add email to the list\n2. Delete email from the list\n3. Display email list\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Enter the email to be added: ");
                    scanf("%s", email);
                    addEmail(email);
                    break;
            case 2: printf("Enter the email to be deleted: ");
                    scanf("%s", email);
                    deleteEmail(email);
                    break;
            case 3: displayList();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}