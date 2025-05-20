//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 500

typedef struct Email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH + 1];
    char message[MAX_MESSAGE_LENGTH + 1];
    bool read;
} Email;

typedef struct EmailClient {
    Email *inbox;
    int num_emails;
} EmailClient;

void print_menu() {
    printf("Welcome to EmailClient!\n"
           "1. Compose email\n"
           "2. View inbox\n"
           "3. Exit\n");
}

void compose_email(EmailClient *client) {
    Email email;
    printf("Enter sender: ");
    scanf("%s", email.sender);
    printf("Enter receiver: ");
    scanf("%s", email.receiver);
    printf("Enter subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%s", email.subject);
    printf("Enter message (max %d characters): ", MAX_MESSAGE_LENGTH);
    scanf("%s", email.message);
    email.read = false;
    
    client->inbox = realloc(client->inbox, (client->num_emails + 1) * sizeof(Email));
    client->inbox[client->num_emails++] = email;
    printf("Email sent!\n");
}

void view_inbox(EmailClient *client) {
    printf("INBOX:\n");
    for (int i=0; i<client->num_emails; i++) {
        if (!client->inbox[i].read) {
            printf("NEW ");
        }
        printf("From: %s\n"
               "Subject: %s\n"
               "Message: %s\n",
               client->inbox[i].sender,
               client->inbox[i].subject,
               client->inbox[i].message);
        client->inbox[i].read = true;
    }
}

int main() {
    EmailClient client;
    client.inbox = NULL;
    client.num_emails = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                compose_email(&client);
                break;
            case 2:
                view_inbox(&client);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    free(client.inbox);
    return 0;
}