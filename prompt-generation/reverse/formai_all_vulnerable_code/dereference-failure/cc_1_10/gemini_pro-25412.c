//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Structure to represent an email
typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
} Email;

// Function to create a new email
Email *create_email(char *sender, char *recipient, char *subject, char *body) {
    Email *email = malloc(sizeof(Email));
    email->sender = malloc(strlen(sender) + 1);
    email->recipient = malloc(strlen(recipient) + 1);
    email->subject = malloc(strlen(subject) + 1);
    email->body = malloc(strlen(body) + 1);
    strcpy(email->sender, sender);
    strcpy(email->recipient, recipient);
    strcpy(email->subject, subject);
    strcpy(email->body, body);
    return email;
}

// Function to send an email
bool send_email(Email *email) {
    // Simulate sending an email by printing it to the console
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n\n", email->body);
    return true;
}

// Function to free the memory allocated for an email
void free_email(Email *email) {
    free(email->sender);
    free(email->recipient);
    free(email->subject);
    free(email->body);
    free(email);
}

// Main function
int main() {
    // Create an email
    Email *email = create_email("John Doe", "Jane Doe", "Hello from C", "This is an email sent from a C program.");

    // Send the email
    if (send_email(email)) {
        printf("Email sent successfully.\n");
    } else {
        printf("Error sending email.\n");
    }

    // Free the memory allocated for the email
    free_email(email);

    return 0;
}