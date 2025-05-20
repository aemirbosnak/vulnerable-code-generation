//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_SENDER_LENGTH 50
#define MAX_RECIPIENTS 10

typedef struct email {
    char* subject;
    char* body;
    char* sender;
    char* recipients[MAX_RECIPIENTS];
} Email;

Email* inbox[MAX_EMAILS];
int num_emails = 0;

void send_email(char* subject, char* body, char* sender, char* recipients[]) {
    // Create a new email
    Email* new_email = (Email*)malloc(sizeof(Email));
    new_email->subject = (char*)malloc(MAX_SUBJECT_LENGTH * sizeof(char));
    strncpy(new_email->subject, subject, MAX_SUBJECT_LENGTH);
    new_email->body = (char*)malloc(MAX_BODY_LENGTH * sizeof(char));
    strncpy(new_email->body, body, MAX_BODY_LENGTH);
    new_email->sender = (char*)malloc(MAX_SENDER_LENGTH * sizeof(char));
    strncpy(new_email->sender, sender, MAX_SENDER_LENGTH);

    // Copy the recipients array
    for (int i = 0; i < MAX_RECIPIENTS; i++) {
        if (recipients[i] != NULL) {
            new_email->recipients[i] = (char*)malloc(MAX_SENDER_LENGTH * sizeof(char));
            strncpy(new_email->recipients[i], recipients[i], MAX_SENDER_LENGTH);
        } else {
            new_email->recipients[i] = NULL;
        }
    }

    // Add the email to the inbox
    inbox[num_emails] = new_email;
    num_emails++;
}

void view_inbox() {
    if (num_emails == 0) {
        printf("No emails in inbox.\n");
    } else {
        printf("Viewing inbox (%d emails):\n", num_emails);
        for (int i = 0; i < num_emails; i++) {
            printf("Email %d:\n", i + 1);
            printf("Subject: %s\n", inbox[i]->subject);
            printf("Body: %s\n", inbox[i]->body);
            printf("Sender: %s\n", inbox[i]->sender);
            printf("Recipients:");
            for (int j = 0; j < MAX_RECIPIENTS; j++) {
                if (inbox[i]->recipients[j] != NULL) {
                    printf(" %s", inbox[i]->recipients[j]);
                }
            }
            printf("\n");
        }
    }
}

int main() {
    // Sample usage
    char* sender = "johndoe@email.com";
    char* recipients[MAX_RECIPIENTS] = {"janedoe@email.com", NULL};
    send_email("Hello", "This is a test email.", sender, recipients);
    view_inbox();
    return 0;
}