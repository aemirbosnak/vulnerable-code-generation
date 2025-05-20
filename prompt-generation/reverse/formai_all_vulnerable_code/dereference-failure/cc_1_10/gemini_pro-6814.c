//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENTS 10

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    char recipients[MAX_RECIPIENTS][MAX_EMAIL_LENGTH];
    int num_recipients;
} Email;

Email* create_email() {
    Email* email = malloc(sizeof(Email));
    email->num_recipients = 0;
    return email;
}

void set_email_address(Email* email, char* address) {
    strcpy(email->email, address);
}

void set_subject(Email* email, char* subject) {
    strcpy(email->subject, subject);
}

void set_body(Email* email, char* body) {
    strcpy(email->body, body);
}

void add_recipient(Email* email, char* address) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: too many recipients\n");
        return;
    }

    strcpy(email->recipients[email->num_recipients], address);
    email->num_recipients++;
}

void send_email(Email* email) {
    // Here we would actually send the email using an SMTP library or other mechanism
    printf("Sending email from %s to %d recipients:\n", email->email, email->num_recipients);
    for (int i = 0; i < email->num_recipients; i++) {
        printf("%s\n", email->recipients[i]);
    }
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    Email* email = create_email();
    set_email_address(email, "sender@example.com");
    set_subject(email, "Important update");
    set_body(email, "This is a very important update that you should read.");
    add_recipient(email, "recipient1@example.com");
    add_recipient(email, "recipient2@example.com");
    add_recipient(email, "recipient3@example.com");

    send_email(email);

    free(email);

    return 0;
}