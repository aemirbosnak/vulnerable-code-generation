//FormAI DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 4096

typedef struct Email {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
} Email;

typedef struct EmailClient {
    Email* emails[MAX_EMAILS];
    int numEmails;
} EmailClient;

Email* createEmail(char* sender, char* receiver, char* subject, char* body) {
    Email* email = (Email*) malloc(sizeof(Email));
    email->sender = (char*) malloc(strlen(sender) + 1);
    strcpy(email->sender, sender);
    email->receiver = (char*) malloc(strlen(receiver) + 1);
    strcpy(email->receiver, receiver);
    email->subject = (char*) malloc(MAX_SUBJECT_LENGTH);
    strncpy(email->subject, subject, MAX_SUBJECT_LENGTH);
    email->body = (char*) malloc(MAX_BODY_LENGTH);
    strncpy(email->body, body, MAX_BODY_LENGTH);
    return email;
}

void deleteEmail(Email* email) {
    free(email->sender);
    free(email->receiver);
    free(email->subject);
    free(email->body);
    free(email);
}

EmailClient* createEmailClient() {
    EmailClient* client = (EmailClient*) malloc(sizeof(EmailClient));
    client->numEmails = 0;
    return client;
}

void deleteEmailClient(EmailClient *client) {
    int i;
    for (i = 0; i < client->numEmails; i++) {
        deleteEmail(client->emails[i]);
    }
    free(client);
}

void sendEmail(EmailClient* client, char* sender, char* receiver, char* subject, char* body) {
    Email* email = createEmail(sender, receiver, subject, body);
    if (client->numEmails < MAX_EMAILS) {
        client->emails[client->numEmails++] = email;
    } else {
        printf("Error: maximum number of emails reached\n");
        deleteEmail(email);
    }
}

void listEmails(EmailClient* client) {
    int i;
    for (i = 0; i < client->numEmails; i++) {
        Email* email = client->emails[i];
        printf("Email %d:\n", i+1);
        printf("Sender: %s\n", email->sender);
        printf("Receiver: %s\n", email->receiver);
        printf("Subject: %s\n", email->subject);
        printf("Body: %s\n", email->body);
        printf("\n");
    }
}

int main() {
    EmailClient* client = createEmailClient();
    sendEmail(client, "Alice", "Bob", "Greetings!", "Hello Bob, how are you doing?");
    sendEmail(client, "Bob", "Alice", "Re: Greetings!", "Hi Alice, I'm doing great thanks for asking.");
    listEmails(client);
    deleteEmailClient(client);
    return 0;
}