//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 100

typedef struct Email {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
} Email;

typedef struct Email_Client {
    Email* emails[MAX_EMAILS];
    int num_emails;
} Email_Client;

Email* create_email(char* sender, char* receiver, char* subject, char* body) {
    Email* email = malloc(sizeof(Email));
    email->sender = strdup(sender);
    email->receiver = strdup(receiver);
    email->subject = strdup(subject);
    email->body = strdup(body);
    return email;
}

void add_email(Email_Client* client, char* sender, char* receiver, char* subject, char* body) {
    Email* email = create_email(sender, receiver, subject, body);
    if (client->num_emails < MAX_EMAILS) {
        client->emails[client->num_emails++] = email;
        printf("Email added successfully\n");
    } else {
        printf("Limit of %d emails reached\n", MAX_EMAILS);
        free(email);
    }
}

void print_email(Email* email) {
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

void print_emails(Email_Client* client) {
    int i;
    for (i = 0; i < client->num_emails; i++) {
        printf("Email %d:\n", i + 1);
        print_email(client->emails[i]);
        printf("\n");
    }
}

int main() {
    Email_Client client;
    client.num_emails = 0;
    char sender[50], receiver[50], subject[100], body[1000];
    int choice = 0;
    while (choice != 4) {
        printf("Enter your choice:\n");
        printf("1. Add an email\n");
        printf("2. View all emails\n");
        printf("3. Clear all emails\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Sender: ");
                scanf("%s", sender);
                printf("Enter Receiver: ");
                scanf("%s", receiver);
                printf("Enter Subject: ");
                scanf("%s", subject);
                printf("Enter Body: ");
                scanf("%s", body);
                add_email(&client, sender, receiver, subject, body);
                break;
            case 2:
                print_emails(&client);
                break;
            case 3:
                client.num_emails = 0;
                printf("All emails cleared.\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}