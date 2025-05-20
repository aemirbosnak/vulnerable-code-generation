//FormAI DATASET v1.0 Category: Phone Book ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//node struct for storing phonebook data
struct node{
    char name[30];
    char number[15];
    char email[50];
    struct node *next;
};

//function to create new node for phonebook
struct node* createNode(char name[], char number[], char email[]){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

//function to add a new contact to phonebook
struct node* addContact(struct node *head, char name[], char number[], char email[]){
    if(head == NULL){
        head = createNode(name, number, email);
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = createNode(name, number, email);
    }
    return head;
}

//function to search for a contact in phonebook
void searchContact(struct node *head, char *name){
    struct node *temp = head;
    int found = 0;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0){
            found = 1;
            printf("Name: %s\n", temp->name);
            printf("Phone Number: %s\n", temp->number);
            printf("Email: %s\n", temp->email);
            break;
        }
        temp = temp->next;
    }
    if(found == 0){
        printf("Contact not found.\n");
    }
}

//function to display all contacts in phonebook
void displayContacts(struct node *head){
    if(head == NULL){
        printf("Phonebook is empty.\n");
    }
    else{
        struct node *temp = head;
        printf("List of Contacts:\n");
        while(temp != NULL){
            printf("Name: %s\n", temp->name);
            printf("Phone Number: %s\n", temp->number);
            printf("Email: %s\n", temp->email);
            printf("--------------------------------\n");
            temp = temp->next;
        }
    }
}

int main(){
    struct node *head = NULL;
    int choice;
    char name[30], number[15], email[50];
    while(1){
        printf("\n---------------------\n");
        printf("What do you want to do?\n");
        printf("---------------------\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("---------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%s", number);
                printf("Enter Email: ");
                scanf("%s", email);
                head = addContact(head, name, number, email);
                printf("\nContact Added.\n");
                break;
            case 2:
                printf("\nEnter Name to search: ");
                scanf("%s", name);
                searchContact(head, name);
                break;
            case 3:
                displayContacts(head);
                break;
            case 4:
                printf("\nExiting Phonebook.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Try Again.\n");
                break;
        }
    }
    return 0;
}