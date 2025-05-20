//FormAI DATASET v1.0 Category: Email Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_RECIPIENTS 10

typedef struct Email {
    char* subject;
    char* body;
    char** recipients;
    int num_recipients;
} Email;

Email create_email(char* subject, char* body) {
    Email email;
    email.subject = (char*) malloc(MAX_SUBJECT_LENGTH * sizeof(char));
    email.body = (char*) malloc(MAX_BODY_LENGTH * sizeof(char));
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    email.recipients = (char**) malloc(MAX_RECIPIENTS * sizeof(char*));
    email.num_recipients = 0;
    return email;
}

void add_recipient(Email* email, char* recipient) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Max number of recipients reached!\n");
        return;
    }
    email->recipients[email->num_recipients++] = recipient;
}

void print_email(Email email) {
    printf("Subject: %s\nBody: %s\nRecipients: ", email.subject, email.body);
    for (int i = 0; i < email.num_recipients; i++) {
        printf("%s ", email.recipients[i]);
    }
    printf("\n");
}

int main() {
    printf("Welcome to our amazing C Email Client program!\n\n");

    Email email = create_email("Hello world", "This is a test email");
    add_recipient(&email, "recipient1@example.com");
    add_recipient(&email, "recipient2@example.com");

    printf("Here is the email information:\n\n");
    print_email(email);

    printf("\nThanks for using our program!\n");
    return 0;
}