//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

contact* create_contact(char* name, char* email) {
    contact* new_contact = (contact*) malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    return new_contact;
}

email* create_email(char* subject, char* message) {
    email* new_email = (email*) malloc(sizeof(email));
    strcpy(new_email->subject, subject);
    strcpy(new_email->message, message);
    return new_email;
}

void send_email(contact* recipient, email* email_to_send) {
    printf("Sending email to %s (%s)\nSubject: %s\nMessage:\n%s\n", recipient->name, recipient->email, email_to_send->subject, email_to_send->message);
}

int main() {
    // Create contacts
    contact* john = create_contact("John Doe", "john@example.com");
    contact* jane = create_contact("Jane Smith", "jane@example.com");

    // Create emails
    email* welcome_email = create_email("Welcome!", "Hello and welcome to our mailing list!");
    email* update_email = create_email("Important Update", "We have some exciting news to share with you!");

    // Send emails
    send_email(john, welcome_email);
    send_email(jane, welcome_email);

    send_email(john, update_email);
    send_email(jane, update_email);

    return 0;
}