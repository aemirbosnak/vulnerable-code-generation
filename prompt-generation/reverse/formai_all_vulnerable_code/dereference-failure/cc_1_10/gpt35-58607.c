//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 100

// Define the structure for a mailing list contact
typedef struct contact {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    struct contact* next;
} Contact;

// Function to create a new contact
Contact* createContact(char* name, char* email) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->email, email);
    newContact->next = NULL;
    return newContact;
}

// Function to add a new contact to the mailing list
void addContact(Contact** head, char* name, char* email) {
    Contact* newContact = createContact(name, email);

    if (*head == NULL) {
        *head = newContact;
    } else {
        Contact* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newContact;
    }
}

// Function to print the mailing list
void printMailingList(Contact* head) {
    printf("Mailing list:\n");
    Contact* current = head;
    while (current != NULL) {
        printf("%s <%s>\n", current->name, current->email);
        current = current->next;
    }
}

// Function to free the memory used by the mailing list
void deleteMailingList(Contact** head) {
    Contact* current = *head;
    while (current != NULL) {
        Contact* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Contact* mailingList = NULL;

    addContact(&mailingList, "John Doe", "john@example.com");
    addContact(&mailingList, "Jane Doe", "jane@example.com");
    addContact(&mailingList, "Bob Smith", "bob@example.com");

    printMailingList(mailingList);

    deleteMailingList(&mailingList);

    return 0;
}