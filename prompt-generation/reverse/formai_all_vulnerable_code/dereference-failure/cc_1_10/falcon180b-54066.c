//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 200
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
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
    printf("Sending email to %s: %s\n", recipient->name, email_to_send->subject);
    printf("Message:\n%s\n", email_to_send->message);
}

int main() {
    contact* john = create_contact("John Doe", "john@example.com");
    contact* jane = create_contact("Jane Smith", "jane@example.com");

    email* welcome_email = create_email("Welcome to our mailing list!", "Hello John,\n\nThank you for subscribing to our mailing list. We will keep you updated with our latest news and promotions.\n\nBest regards,\nThe Team");
    send_email(john, welcome_email);

    email* update_email = create_email("Latest news and promotions", "Hello Jane,\n\nWe wanted to update you on our latest news and promotions. Check out our website for more information.\n\nBest regards,\nThe Team");
    send_email(jane, update_email);

    free(john->name);
    free(john->email);
    free(john);

    free(jane->name);
    free(jane->email);
    free(jane);

    free(welcome_email->subject);
    free(welcome_email->message);
    free(welcome_email);

    free(update_email->subject);
    free(update_email->message);
    free(update_email);

    return 0;
}