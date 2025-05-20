//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} MailingList;

void add_contact(MailingList *list, char *name, char *email) {
    Contact *contact = (Contact *) malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    list->contacts = (Contact *) realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *contact;
    list->num_contacts++;
}

void send_email(MailingList *list, int index) {
    char to[MAX_EMAIL_LENGTH];
    strcpy(to, list->contacts[index].email);
    char subject[MAX_SUBJECT_LENGTH];
    strcpy(subject, list->subject);
    char message[MAX_MESSAGE_LENGTH];
    strcpy(message, list->message);
    printf("Sending email to %s with subject '%s' and message:\n%s\n", to, subject, message);
}

int main() {
    MailingList list;
    list.num_contacts = 0;
    list.contacts = NULL;

    add_contact(&list, "John Doe", "john.doe@example.com");
    add_contact(&list, "Jane Smith", "jane.smith@example.com");

    strcpy(list.subject, "Hello!");
    strcpy(list.message, "Dear %s,\n\nThis is a test email to see if the mailing list manager works.\n\nBest regards,\nThe Mailing List Manager");

    int i;
    for (i = 0; i < list.num_contacts; i++) {
        send_email(&list, i);
    }

    return 0;
}