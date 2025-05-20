//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECTS 50
#define MAX_BODY 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
} Message;

typedef struct {
    Contact* contacts;
    int num_contacts;
    Message* messages;
    int num_messages;
} MailingList;

void create_contact(MailingList* list, char* name, char* email) {
    Contact* new_contact = (Contact*)malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    list->contacts = (Contact*)realloc(list->contacts, sizeof(Contact) * (list->num_contacts + 1));
    list->contacts[list->num_contacts] = *new_contact;
    list->num_contacts++;
}

void create_message(MailingList* list, char* subject, char* body) {
    Message* new_message = (Message*)malloc(sizeof(Message));
    strcpy(new_message->subject, subject);
    strcpy(new_message->body, body);
    list->messages = (Message*)realloc(list->messages, sizeof(Message) * (list->num_messages + 1));
    list->messages[list->num_messages] = *new_message;
    list->num_messages++;
}

void send_message(MailingList* list) {
    for (int i = 0; i < list->num_contacts; i++) {
        printf("Sending message to %s (%s)\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList list = {0};

    create_contact(&list, "John Doe", "johndoe@example.com");
    create_contact(&list, "Jane Doe", "janedoe@example.com");

    create_message(&list, "Hello World!", "This is a test message.");
    create_message(&list, "Test Message", "Testing the mailing list manager.");

    send_message(&list);

    return 0;
}