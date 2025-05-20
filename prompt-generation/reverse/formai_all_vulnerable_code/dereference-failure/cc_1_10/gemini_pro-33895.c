//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store email data
typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
} email_t;

void compose_email(email_t *email) {
    char *s, *r, *sub, *body;

    printf("Enter sender email address: ");
    s = malloc(256);
    fgets(s, 256, stdin);
    email->sender = s;

    printf("Enter recipient email address: ");
    r = malloc(256);
    fgets(r, 256, stdin);
    email->recipient = r;

    printf("Enter email subject: ");
    sub = malloc(256);
    fgets(sub, 256, stdin);
    email->subject = sub;

    printf("Enter email body: ");
    body = malloc(1024);
    fgets(body, 1024, stdin);
    email->body = body;
}

void send_email(email_t *email) {
    // Placeholder function, actual sending logic would go here
    printf("Sending email from %s to %s with subject \"%s\":\n", email->sender, email->recipient, email->subject);
    printf("%s\n", email->body);
}

int main() {
    email_t email;

    printf("Welcome to the email client!\n");
    compose_email(&email);
    send_email(&email);

    // Free dynamically allocated memory
    free(email.sender);
    free(email.recipient);
    free(email.subject);
    free(email.body);

    return 0;
}