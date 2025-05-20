//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN]; 
} Contact; 

Contact *contacts;
int contactCount = 0;

void addContact(char *name, char *email) {
    contacts = realloc(contacts, (contactCount + 1) * sizeof(Contact));
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);
    contacts[contactCount] = newContact;
    contactCount++;
}

void removeContact(char *email) {
    int indexToRemove = -1;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            indexToRemove = i;
            break; 
        }
    }
    if (indexToRemove != -1) {
        for (int i = indexToRemove + 1; i < contactCount; i++) {
            contacts[i - 1] = contacts[i];
        }
        contactCount--;
        contacts = realloc(contacts, contactCount * sizeof(Contact));
    }
}

void printContacts() {
    for (int i = 0; i < contactCount; i++) {
        printf("Name: %s\nEmail: %s\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    char option;
    do {
        printf("Enter option: (a)dd / (r)emove / (p)rint / (q)uit\n");
        scanf(" %c", &option);
        
        switch(option) {
            case 'a': {
                char name[MAX_NAME_LEN];
                char email[MAX_EMAIL_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                addContact(name, email);
                printf("Contact added\n");
                break;
            }
            case 'r': {
                char email[MAX_EMAIL_LEN];
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeContact(email);
                printf("Contact removed\n");
                break;
            }
            case 'p': {
                printContacts();
                break;
            }
        }
    } while (option != 'q');
    free(contacts);
    return 0;
}