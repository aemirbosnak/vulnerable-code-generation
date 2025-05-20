//FormAI DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_NUMBER_LENGTH 20
#define MAX_LIST_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_NUMBER_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_LIST_LENGTH];
    int size;
} MailingList;

MailingList* createMailingList() {
    MailingList* newList = (MailingList*) malloc(sizeof(MailingList));
    newList->size = 0;
    return newList;
}

void addContact(MailingList* list, char* name, char* email, char* phone) {
    if (list->size < MAX_LIST_LENGTH) {
        Contact newContact;
        strncpy(newContact.name, name, MAX_NAME_LENGTH);
        strncpy(newContact.email, email, MAX_EMAIL_LENGTH);
        strncpy(newContact.phone, phone, MAX_NUMBER_LENGTH);
        list->contacts[list->size++] = newContact;
        printf("Contact added successfully!\n");
    } else {
        printf("Mailing list is full!\n");
    }
}

void removeContact(MailingList* list, char* email) {
    int i, j;
    for (i = 0; i < list->size; i++) {
        if (!strcmp(list->contacts[i].email, email)) {
            for (j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            list->size--;
            printf("Contact removed successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void searchContact(MailingList* list, char* name) {
    int found = 0, i;
    for (i = 0; i < list->size; i++) {
        if (!strcmp(list->contacts[i].name, name)) {
            printf("Name: %s\n", list->contacts[i].name);
            printf("Email: %s\n", list->contacts[i].email);
            printf("Phone: %s\n", list->contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

void listContacts(MailingList* list) {
    int i;
    for (i = 0; i < list->size; i++) {
        printf("Name: %s\n", list->contacts[i].name);
        printf("Email: %s\n", list->contacts[i].email);
        printf("Phone: %s\n", list->contacts[i].phone);
        printf("\n");
    }
}

int main() {
    MailingList* myList = createMailingList();
    printf("Please select an action:\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Search contact\n");
    printf("4. List contacts\n");
    printf("5. Exit\n");
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_NUMBER_LENGTH];
    while (choice != 5) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addContact(myList, name, email, phone);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                removeContact(myList, email);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                searchContact(myList, name);
                break;
            case 4:
                listContacts(myList);
                break;
            case 5:
                printf("Exiting Mailing List Manager...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    free(myList);
    return 0;
}