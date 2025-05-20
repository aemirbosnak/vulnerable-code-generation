//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAILS_PER_NAME 10
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char emails[MAX_EMAILS_PER_NAME][MAX_NAME_LEN];
    int num_emails;
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list *list, char *name) {
    contact *new_contact = malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    new_contact->num_emails = 0;
    list->contacts = realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void add_email(mailing_list *list, int contact_index, char *email) {
    contact *contact = &list->contacts[contact_index];
    if (contact->num_emails >= MAX_EMAILS_PER_NAME) {
        printf("Error: Contact already has %d emails.\n", MAX_EMAILS_PER_NAME);
        return;
    }
    strcpy(contact->emails[contact->num_emails], email);
    contact->num_emails++;
}

void send_email(mailing_list *list, int contact_index, char *subject, char *body) {
    contact *contact = &list->contacts[contact_index];
    int i;
    for (i = 0; i < contact->num_emails; i++) {
        printf("Sending email to %s...\n", contact->emails[i]);
    }
}

int main() {
    mailing_list list;
    list.num_contacts = 0;
    list.contacts = NULL;

    add_contact(&list, "John Doe");
    add_email(&list, 0, "john.doe@example.com");

    add_contact(&list, "Jane Doe");
    add_email(&list, 1, "jane.doe@example.com");

    send_email(&list, 0, "Hello", "Hi John!");
    send_email(&list, 1, "Hi", "Hello Jane!");

    return 0;
}