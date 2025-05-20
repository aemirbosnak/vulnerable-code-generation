//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 64
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 1024
#define MAX_MESSAGE_LENGTH 4096

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int num_contacts;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *mailing_list = malloc(sizeof(MailingList));
    mailing_list->contacts = NULL;
    mailing_list->num_contacts = 0;
    return mailing_list;
}

void add_contact(MailingList *mailing_list, const char *name, const char *email) {
    Contact *contact = malloc(sizeof(Contact));
    strncpy(contact->name, name, MAX_NAME_LENGTH);
    strncpy(contact->email, email, MAX_EMAIL_LENGTH);
    mailing_list->contacts = realloc(mailing_list->contacts, sizeof(Contact) * (mailing_list->num_contacts + 1));
    mailing_list->contacts[mailing_list->num_contacts] = *contact;
    mailing_list->num_contacts++;
}

void send_email(const char *to, const char *subject, const char *message) {
    printf("Sending email to %s with subject '%s' and message:\n%s\n", to, subject, message);
}

void send_emails(MailingList *mailing_list, const char *subject, const char *message) {
    for (int i = 0; i < mailing_list->num_contacts; i++) {
        send_email(mailing_list->contacts[i].email, subject, message);
    }
}

int main() {
    MailingList *mailing_list = create_mailing_list();

    add_contact(mailing_list, "Ada Lovelace", "ada@example.com");
    add_contact(mailing_list, "Charles Babbage", "charles@example.com");

    send_emails(mailing_list, "Hello from the Mailing List Manager!", "This is a test email to demonstrate the functionality of the mailing list manager. Thank you for your attention.");

    free(mailing_list->contacts);
    free(mailing_list);

    return 0;
}