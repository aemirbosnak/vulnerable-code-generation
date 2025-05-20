//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct email {
    char emailId[50];
    struct email *next;
} Email;

typedef struct contact {
    char name[20];
    Email *emailList;
    struct contact *next;
} Contact;

Contact *head = NULL;

void addContact(char name[]) {
    Contact *temp = (Contact*)malloc(sizeof(Contact));
    strcpy(temp->name, name);
    temp->emailList = NULL;
    temp->next = head;
    head = temp;
}

void addEmail(char name[], char emailId[]) {
    Email *tempEmail = (Email*)malloc(sizeof(Email));
    strcpy(tempEmail->emailId, emailId);
    tempEmail->next = NULL;
    Contact *tempContact = head;
    while(tempContact != NULL && strcmp(tempContact->name, name) != 0) {
        tempContact = tempContact->next;
    }
    if(tempContact != NULL) {
        tempEmail->next = tempContact->emailList;
        tempContact->emailList = tempEmail;
    }
}

void printList() {
    printf("Contact List\n");
    Contact *tempContact = head;
    while(tempContact != NULL) {
        printf("Name: %s\n", tempContact->name);
        Email *tempEmail = tempContact->emailList;
        printf("Email: ");
        while(tempEmail != NULL) {
            printf("%s ", tempEmail->emailId);
            tempEmail = tempEmail->next;
        }
        printf("\n");
        tempContact = tempContact->next;
    }
}

int main() {
    addContact("Alice");
    addEmail("Alice", "alice@gmail.com");
    addEmail("Alice", "alice@outlook.com");
    addContact("Bob");
    addEmail("Bob", "bob@yahoo.com");
    printList();
    return 0;
}