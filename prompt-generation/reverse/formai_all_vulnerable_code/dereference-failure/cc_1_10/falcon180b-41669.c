//Falcon-180B DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 256

typedef struct {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
} Email;

Email *create_email() {
    Email *email = (Email *)malloc(sizeof(Email));
    email->sender = NULL;
    email->recipient = NULL;
    email->subject = NULL;
    email->body = NULL;
    return email;
}

void delete_email(Email *email) {
    free(email->sender);
    free(email->recipient);
    free(email->subject);
    free(email->body);
    free(email);
}

int parse_email(char *line, Email *email) {
    char *token = strtok(line, ":");
    if (token == NULL) {
        return 0;
    }
    if (strcasecmp(token, "From") == 0) {
        email->sender = strdup(strtok(NULL, ":"));
    } else if (strcasecmp(token, "To") == 0) {
        email->recipient = strdup(strtok(NULL, ":"));
    } else if (strcasecmp(token, "Subject") == 0) {
        email->subject = strdup(strtok(NULL, ":"));
    } else if (strcasecmp(token, "Content-Type") == 0) {
        char *content_type = strtok(NULL, ":");
        if (strcasecmp(content_type, "text/plain") == 0) {
            email->body = strdup(strtok(NULL, "\r\n"));
        }
    }
    return 1;
}

int main() {
    FILE *inbox;
    char line[MAX_LINE_LENGTH];
    Email email = {NULL, NULL, NULL, NULL};

    inbox = fopen("inbox.txt", "r");
    if (inbox == NULL) {
        printf("Error: Inbox file not found.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, inbox)!= NULL) {
        parse_email(line, &email);
        if (email.sender!= NULL && email.recipient!= NULL && email.subject!= NULL && email.body!= NULL) {
            printf("Sender: %s\n", email.sender);
            printf("Recipient: %s\n", email.recipient);
            printf("Subject: %s\n", email.subject);
            printf("Body:\n%s\n\n", email.body);
        }
        delete_email(&email);
    }

    fclose(inbox);
    return 0;
}