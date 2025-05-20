//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char *sender;
    char *receiver;
    char *subject;
    char *body;
};

// Create a new email
struct email *create_email(char *sender, char *receiver, char *subject, char *body) {
    struct email *email = malloc(sizeof(struct email));
    email->sender = malloc(strlen(sender) + 1);
    email->receiver = malloc(strlen(receiver) + 1);
    email->subject = malloc(strlen(subject) + 1);
    email->body = malloc(strlen(body) + 1);
    strcpy(email->sender, sender);
    strcpy(email->receiver, receiver);
    strcpy(email->subject, subject);
    strcpy(email->body, body);
    return email;
}

// Send an email
void send_email(struct email *email) {
    printf("Sending email from %s to %s with subject %s:\n\n", email->sender, email->receiver, email->subject);
    printf("%s\n", email->body);
}

// Free an email
void free_email(struct email *email) {
    free(email->sender);
    free(email->receiver);
    free(email->subject);
    free(email->body);
    free(email);
}

// Main function
int main() {
    // Create an email
    struct email *email = create_email("sender@example.com", "receiver@example.com", "Hello, world!", "This is an email.");

    // Send the email
    send_email(email);

    // Free the email
    free_email(email);

    return 0;
}