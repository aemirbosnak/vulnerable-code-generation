//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Email structure
typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
    time_t timestamp;
} Email;

// Email client functions
Email *create_email(char *sender, char *recipient, char *subject, char *body);
void send_email(Email *email);
void receive_email(char *recipient);
void delete_email(Email *email);

// Main function
int main() {
    // Create an email
    Email *email = create_email("john@example.com", "jane@example.com", "Hello", "How are you?");

    // Send the email
    send_email(email);

    // Receive an email
    receive_email("jane@example.com");

    // Delete the email
    delete_email(email);

    return 0;
}

// Create an email
Email *create_email(char *sender, char *recipient, char *subject, char *body) {
    // Allocate memory for the email
    Email *email = malloc(sizeof(Email));

    // Copy the sender, recipient, subject, and body into the email
    email->sender = malloc(strlen(sender) + 1);
    strcpy(email->sender, sender);
    email->recipient = malloc(strlen(recipient) + 1);
    strcpy(email->recipient, recipient);
    email->subject = malloc(strlen(subject) + 1);
    strcpy(email->subject, subject);
    email->body = malloc(strlen(body) + 1);
    strcpy(email->body, body);

    // Get the current timestamp
    email->timestamp = time(NULL);

    // Return the email
    return email;
}

// Send an email
void send_email(Email *email) {
    // Print the email to the console
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);

    // Get confirmation from the user
    char confirmation;
    printf("Do you want to send this email? (y/n) ");
    scanf(" %c", &confirmation);

    // If the user confirms, send the email
    if (confirmation == 'y') {
        printf("Email sent.\n");
    } else {
        printf("Email not sent.\n");
    }
}

// Receive an email
void receive_email(char *recipient) {
    // Print a message to the console
    printf("Checking for new emails for %s...\n", recipient);

    // Sleep for 1 second
    sleep(1);

    // Create a fake email
    Email *email = create_email("jane@example.com", recipient, "Hello", "How are you?");

    // Print the email to the console
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);

    // Delete the email
    delete_email(email);
}

// Delete an email
void delete_email(Email *email) {
    // Free the memory allocated for the email
    free(email->sender);
    free(email->recipient);
    free(email->subject);
    free(email->body);
    free(email);

    // Print a message to the console
    printf("Email deleted.\n");
}