//FormAI DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for an email
typedef struct Email {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
} Email;

// Define struct for an email client
typedef struct EmailClient {
    char* username;
    char* password;
    Email* inbox;
    int num_emails;
} EmailClient;

// Function to create a new email
Email* create_email(char* sender, char* recipient, char* subject, char* body) {
    Email* new_email = (Email*) malloc(sizeof(Email));
    new_email->sender = strdup(sender);
    new_email->recipient = strdup(recipient);
    new_email->subject = strdup(subject);
    new_email->body = strdup(body);

    return new_email;
} 

// Function to send an email
void send_email(Email* email) {
    printf("Sending email...\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Email sent.\n\n");
}

// Function to receive an email
void receive_email(EmailClient* client, Email* email) {
    client->inbox = (Email*) realloc(client->inbox, sizeof(Email) * (client->num_emails + 1));
    client->inbox[client->num_emails] = *email;
    client->num_emails++;
    printf("New email received.\n\n");
}

// Function to print out inbox
void print_inbox(EmailClient* client) {
    printf("Inbox: \n");
    for(int i = 0; i < client->num_emails; i++) {
        printf("From: %s\n", client->inbox[i].sender);
        printf("To: %s\n", client->inbox[i].recipient);
        printf("Subject: %s\n", client->inbox[i].subject);
        printf("Body: %s\n", client->inbox[i].body);
        printf("\n");
    }
}

int main() {
    // Create email client
    EmailClient* client = (EmailClient*) malloc(sizeof(EmailClient));
    client->username = strdup("myemail@gmail.com");
    client->password = strdup("mypassword");
    client->inbox = NULL;
    client->num_emails = 0;

    // Send email 1
    Email* email1 = create_email("myemail@gmail.com", "myfriend@gmail.com", "Hello!", "How are you doing?");
    send_email(email1);

    // Receive email 1
    receive_email(client, email1);

    // Send email 2
    Email* email2 = create_email("myemail@gmail.com", "boss@gmail.com", "Important meeting", "Just a reminder that there is a meeting at 2pm today.");
    send_email(email2);

    // Receive email 2
    receive_email(client, email2);

    // Print inbox
    print_inbox(client);

    return 0;
}