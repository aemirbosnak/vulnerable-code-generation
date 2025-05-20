//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: modular
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
} Contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Message;

Contact* create_contact(char* name, char* email) {
    Contact* contact = (Contact*) malloc(sizeof(Contact));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    return contact;
}

void print_contact(Contact* contact) {
    printf("Name: %s\nEmail: %s\n", contact->name, contact->email);
}

Message* create_message(char* subject, char* message) {
    Message* msg = (Message*) malloc(sizeof(Message));
    strcpy(msg->subject, subject);
    strcpy(msg->message, message);
    return msg;
}

void print_message(Message* msg) {
    printf("Subject: %s\nMessage:\n%s\n", msg->subject, msg->message);
}

void send_message(Contact* contact, Message* msg) {
    printf("Sending message to %s...\n", contact->email);
    printf("Subject: %s\n", msg->subject);
    printf("Message:\n%s\n", msg->message);
}

int main() {
    // Create contacts
    Contact* contact1 = create_contact("John Doe", "john.doe@example.com");
    Contact* contact2 = create_contact("Jane Smith", "jane.smith@example.com");

    // Create messages
    Message* msg1 = create_message("Hello", "How are you?");
    Message* msg2 = create_message("Reminder", "Don't forget our meeting tomorrow.");

    // Send messages to contacts
    send_message(contact1, msg1);
    send_message(contact2, msg2);

    return 0;
}