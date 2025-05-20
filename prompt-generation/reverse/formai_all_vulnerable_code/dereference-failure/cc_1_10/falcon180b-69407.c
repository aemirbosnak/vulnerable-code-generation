//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NAME_SIZE 64
#define MAX_EMAIL_SIZE 128
#define MAX_PHONE_SIZE 32

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    char phone[MAX_PHONE_SIZE];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} ContactList;

void add_contact(ContactList *list, const char *name, const char *email, const char *phone) {
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    strncpy(contact->name, name, MAX_NAME_SIZE);
    strncpy(contact->email, email, MAX_EMAIL_SIZE);
    strncpy(contact->phone, phone, MAX_PHONE_SIZE);
    list->contacts = (Contact *) realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts++] = *contact;
}

void print_contacts(ContactList *list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Name: %s\n", list->contacts[i].name);
        printf("Email: %s\n", list->contacts[i].email);
        printf("Phone: %s\n\n", list->contacts[i].phone);
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    ContactList list = { 0 };

    if ((file = fopen("contacts.txt", "r")) == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");

        if (name == NULL || email == NULL || phone == NULL) {
            printf("Error: Invalid contact information.\n");
            exit(1);
        }

        add_contact(&list, name, email, phone);
    }

    fclose(file);
    print_contacts(&list);
    return 0;
}