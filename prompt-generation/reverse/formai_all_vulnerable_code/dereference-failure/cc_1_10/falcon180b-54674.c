//Falcon-180B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAIL_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_RECIPIENTS 10
#define MAX_RECIPIENT_LENGTH 256

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_RECIPIENTS][MAX_RECIPIENT_LENGTH];
    int num_recipients;
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    time_t timestamp;
} Email;

Email* create_email() {
    Email* email = (Email*)malloc(sizeof(Email));
    email->num_recipients = 0;
    email->timestamp = time(NULL);
    return email;
}

void add_recipient(Email* email, const char* recipient) {
    if (email->num_recipients >= MAX_RECIPIENTS) {
        printf("Error: Too many recipients.\n");
        return;
    }
    strcpy(email->to[email->num_recipients], recipient);
    email->num_recipients++;
}

void set_subject(Email* email, const char* subject) {
    strcpy(email->subject, subject);
}

void set_body(Email* email, const char* body) {
    strcpy(email->body, body);
}

void send_email(Email* email) {
    printf("Sending email from %s to %d recipients:\n", email->from, email->num_recipients);
    for (int i = 0; i < email->num_recipients; i++) {
        printf("  %s\n", email->to[i]);
    }
    printf("  Subject: %s\n", email->subject);
    printf("  Body:\n%s\n", email->body);
}

int main() {
    Email* email = create_email();
    char from[MAX_EMAIL_LENGTH] = "sender@example.com";
    strcpy(email->from, from);

    add_recipient(email, "recipient1@example.com");
    add_recipient(email, "recipient2@example.com");

    set_subject(email, "Test Email");
    set_body(email, "Hello, world!");

    send_email(email);

    return 0;
}