//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Message;

typedef struct {
    Contact *contacts;
    int num_contacts;
    Message *messages;
    int num_messages;
} MailingList;

void init_contact(Contact *contact) {
    strcpy(contact->name, "");
    strcpy(contact->email, "");
}

void init_message(Message *message) {
    strcpy(message->subject, "");
    strcpy(message->body, "");
}

void init_mailing_list(MailingList *mailing_list) {
    mailing_list->contacts = NULL;
    mailing_list->num_contacts = 0;
    mailing_list->messages = NULL;
    mailing_list->num_messages = 0;
}

void add_contact(MailingList *mailing_list, Contact *contact) {
    mailing_list->contacts = realloc(mailing_list->contacts, sizeof(Contact) * (mailing_list->num_contacts + 1));
    mailing_list->contacts[mailing_list->num_contacts] = *contact;
    mailing_list->num_contacts++;
}

void add_message(MailingList *mailing_list, Message *message) {
    mailing_list->messages = realloc(mailing_list->messages, sizeof(Message) * (mailing_list->num_messages + 1));
    mailing_list->messages[mailing_list->num_messages] = *message;
    mailing_list->num_messages++;
}

int send_message(MailingList *mailing_list, char *subject, char *body) {
    Message message;
    init_message(&message);
    strcpy(message.subject, subject);
    strcpy(message.body, body);
    add_message(mailing_list, &message);
    return 0;
}

int main() {
    MailingList mailing_list;
    init_mailing_list(&mailing_list);

    Contact contact;
    init_contact(&contact);
    strcpy(contact.name, "John Doe");
    strcpy(contact.email, "johndoe@example.com");
    add_contact(&mailing_list, &contact);

    send_message(&mailing_list, "Hello World!", "This is a test message.");

    return 0;
}