//FormAI DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100

// Email struct to hold message data
typedef struct {
    char* sender;
    char* recipient;
    char* subject;
    char* text;
} Email;

// Email client struct to hold account and emails
typedef struct {
    char* username;
    char* password;
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailClient;

// Function to create a new email
Email create_email(char* sender, char* recipient, char* subject, char* text) {
    Email new_email;
    new_email.sender = strdup(sender);
    new_email.recipient = strdup(recipient);
    new_email.subject = strdup(subject);
    new_email.text = strdup(text);
    return new_email;
}

// Function to add an email to the client's email array
void add_email(EmailClient* client, Email email) {
    if (client->num_emails >= MAX_EMAILS) {
        printf("Maximum number of emails reached.\n");
        return;
    }
    client->emails[client->num_emails++] = email;
}

// Function to print the details of an email
void print_email(Email email) {
    printf("From: %s\nTo: %s\nSubject: %s\n\n%s\n", 
            email.sender, email.recipient, email.subject, email.text);
}

// Function to print all emails in the client's email array
void print_emails(EmailClient* client) {
    printf("Your Inbox:\n");
    for (int i = 0; i < client->num_emails; i++) {
        printf("Email %d:\n", i+1);
        print_email(client->emails[i]);
        printf("-------------------\n");
    }
}

int main() {
    // Create a new email client
    EmailClient* client = malloc(sizeof(EmailClient));
    client->username = strdup("example@gmail.com");
    client->password = strdup("password");

    // Create and add some emails to the client's email array
    Email email1 = create_email("someone@mail.com", client->username, "Thanks!", "Thank you for your help yesterday.");
    add_email(client, email1);
    Email email2 = create_email(client->username, "person@company.com", "Meeting tomorrow", "Let's meet tomorrow at 2 PM.");
    add_email(client, email2);
    Email email3 = create_email(client->username, "friend@somewhere.com", "Long time no talk", "How have you been? It's been ages since we last spoke.");
    add_email(client, email3);

    // Print all emails in the client's email array
    print_emails(client);

    // Free allocated memory
    free(client->username);
    free(client->password);
    for (int i = 0; i < client->num_emails; i++) {
        free(client->emails[i].sender);
        free(client->emails[i].recipient);
        free(client->emails[i].subject);
        free(client->emails[i].text);
    }
    free(client);
    return 0;
}