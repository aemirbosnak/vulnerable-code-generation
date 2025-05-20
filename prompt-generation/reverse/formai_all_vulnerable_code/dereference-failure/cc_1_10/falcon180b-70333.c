//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} mailing_list;

void add_contact(mailing_list *list, char *name, char *email) {
    contact *new_contact = (contact *) malloc(sizeof(contact));
    strncpy(new_contact->name, name, MAX_NAME_LENGTH);
    strncpy(new_contact->email, email, MAX_EMAIL_LENGTH);
    list->contacts = (contact *) realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            list->contacts = (contact *) realloc(list->contacts, sizeof(contact) * (list->num_contacts - 1));
            memmove(&list->contacts[i], &list->contacts[i + 1], sizeof(contact) * (list->num_contacts - i - 1));
            list->num_contacts--;
            break;
        }
    }
}

void send_email(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("Sending email to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    mailing_list list;
    list.contacts = NULL;
    list.num_contacts = 0;

    add_contact(&list, "John Doe", "john@example.com");
    add_contact(&list, "Jane Smith", "jane@example.com");

    send_email(&list);

    remove_contact(&list, "john@example.com");

    send_email(&list);

    return 0;
}