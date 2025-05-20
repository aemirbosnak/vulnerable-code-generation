//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    struct Contact* next;
} Contact;

Contact* createContact(char* name, char* email, char* phone) {
    Contact* newContact = malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

void addContact(Contact* head, char* name, char* email, char* phone) {
    Contact* newContact = createContact(name, email, phone);
    if (head == NULL) {
        head = newContact;
    } else {
        Contact* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newContact;
    }
}

void searchContact(Contact* head, char* name) {
    Contact* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s\n", temp->name);
            printf("Email: %s\n", temp->email);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("No contact found.\n");
}

int main() {
    Contact* head = NULL;
    addContact(head, "Sherlock Holmes", "sherlock@bakerstreet.com", "221B Baker St.");
    addContact(head, "John Watson", "john@bakerstreet.com", "221B Baker St.");
    addContact(head, "Dr. Watson", "dr.watson@bakerstreet.com", "221B Baker St.");

    searchContact(head, "John Watson");

    return 0;
}