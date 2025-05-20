//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECTS 100
#define MAX_BODY 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECTS];
    char body[MAX_BODY];
    contact sender;
    int num_recipients;
    contact *recipients;
} message;

contact *contacts = NULL;
int num_contacts = 0;

void add_contact(char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    contacts = (contact *)realloc(contacts, sizeof(contact) * ++num_contacts);
    contacts[num_contacts - 1] = *new_contact;
    free(new_contact);
}

int find_contact_index(char *email) {
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

void send_message(char *subject, char *body, char *sender_email, int num_recipients, char **recipient_emails) {
    message *new_message = (message *)malloc(sizeof(message));
    strcpy(new_message->subject, subject);
    strcpy(new_message->body, body);
    strcpy(new_message->sender.name, "");
    strcpy(new_message->sender.email, sender_email);
    new_message->num_recipients = num_recipients;
    new_message->recipients = (contact *)malloc(sizeof(contact) * num_recipients);
    int i;
    for (i = 0; i < num_recipients; i++) {
        int contact_index = find_contact_index(recipient_emails[i]);
        if (contact_index == -1) {
            printf("Recipient not found: %s\n", recipient_emails[i]);
            continue;
        }
        new_message->recipients[i] = contacts[contact_index];
    }
    printf("Message sent to %d recipients.\n", num_recipients);
}

void print_contacts() {
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }
}

int main() {
    add_contact("John Doe", "john@example.com");
    add_contact("Jane Smith", "jane@example.com");
    print_contacts();
    send_message("Test Message", "Hello, World!", "john@example.com", 2, (char **){"jane@example.com", "invalid@example.com"});
    return 0;
}