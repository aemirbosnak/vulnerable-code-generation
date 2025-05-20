//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct email {
    char message[500];
    struct email *next;
}Email;

typedef struct mail_list{
    char name[50];
    Email *head;
}MailList;

MailList* createList(char name[]){ //create a new mailing list 
    MailList *newList = (MailList*)malloc(sizeof(MailList));
    strcpy(newList->name, name);
    newList->head = NULL;
    return newList;
}

void addEmail(MailList *list, char message[]){ //add a new email to the mailing list 
    Email *newEmail = (Email*)malloc(sizeof(Email));
    strcpy(newEmail->message, message);
    newEmail->next = NULL;
    if(list->head == NULL) {
        list->head = newEmail;
    } else {
        Email *temp = list->head;
        while(temp->next != NULL) {
            temp=temp->next;
        }
        temp->next=newEmail;
    }
}

void displayList(MailList *list) { //display the mailing list with all its emails
    if(list == NULL){
        printf("The mailing list does not exist.");
        return;
    }
    printf(" The mailing list name is: %s\n",list->name);
    Email *temp=list->head;
    int i=1;
    if(temp == NULL){
        printf(" This list is empty, no messages to display.");
        return;
    }
    while(temp!=NULL){
        printf(" Email %d content: %s\n",i,temp->message);
        temp=temp->next;
        i++;
    }
    printf("Total number of emails: %d",i-1);
}

Email* searchEmail(MailList *list, char message[]){ //check if an email with certain content exists in the mailing list 
    if(list == NULL){
        printf("The mailing list does not exist.");
        return NULL;
    }
    Email *temp=list->head;
    while(temp!=NULL){
        if(strcmp(temp->message, message)==0){
            printf(" Email found!\n");
            return temp;
        }
        temp=temp->next;
    }
    printf(" Email not found.\n");
    return NULL;
}

int main(){
    //sample code to demonstrate the implementation of mailing list manager 
    printf("Welcome to the mailing list manager!\n");    
    printf("Creating a mailing list named 'Friends'...\n");
    MailList *Friends = createList("Friends"); //create a new mailing list named 'Friends' 
    
    printf("Adding an email 'Hello from the other side' to the 'Friends' mailing list...\n");
    addEmail(Friends, "Hello from the other side"); //add a new email to the 'Friends' mailing list 
    
    printf("Adding an email 'How's your day going?' to the 'Friends' mailing list...\n");    
    addEmail(Friends, "How's your day going?"); //add another email to the 'Friends' mailing list
    
    printf("Displaying the 'Friends' mailing list with all its emails...\n");
    displayList(Friends); //display the 'Friends' mailing list with all its emails 
    
    printf("Searching for an email with the content 'Hey there' in the 'Friends' mailing list...\n");
    Email *foundEmail = searchEmail(Friends, "Hey there"); //search for an email with certain content in the 'Friends' mailing list 
    
    printf("Searching for an email with the content 'How's your day going?' in the 'Friends' mailing list...\n");
    foundEmail = searchEmail(Friends, "How's your day going?"); //search for another email with certain content in the 'Friends' mailing list 
    
    return 0;
}