//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void add_contact(mailing_list *list, char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = (contact *)realloc(list->contacts, sizeof(contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void remove_contact(mailing_list *list, int index) {
    list->contacts = (contact *)realloc(list->contacts, sizeof(contact) * (list->num_contacts - 1));
}

void print_contacts(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        printf("Name: %s\nEmail: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

void send_email(mailing_list *list, int index, char *subject, char *body) {
    contact *contact = &list->contacts[index];
    printf("Sending email to %s (%s)\nSubject: %s\n", contact->name, contact->email, subject);
    printf("Body:\n%s\n", body);
}

int main() {
    mailing_list list;
    list.num_contacts = 0;
    list.contacts = NULL;

    add_contact(&list, "John Doe", "johndoe@example.com");
    add_contact(&list, "Jane Doe", "janedoe@example.com");

    print_contacts(&list);

    send_email(&list, 0, "Hello", "This is a test email.");
    send_email(&list, 1, "Hi", "How are you?");

    remove_contact(&list, 0);

    print_contacts(&list);

    return 0;
}