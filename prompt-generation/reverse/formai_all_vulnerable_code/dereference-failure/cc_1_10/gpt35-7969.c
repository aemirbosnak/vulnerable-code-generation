//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSG_LEN 1000
#define MAX_SUBJECT_LEN 100
#define MAX_EMAILS_COUNT 20

typedef struct {
    char* subject;
    char* message;
    char* recipient;
} Email;

Email* emails[MAX_EMAILS_COUNT];
int emails_count = 0;

int send_email(char* recipient, char* subject, char* message) {
    if(emails_count == MAX_EMAILS_COUNT) {
        return -1;
    }

    Email* email = (Email*)malloc(sizeof(Email));

    email->recipient = (char*)malloc(strlen(recipient) + 1);
    strcpy(email->recipient, recipient);

    email->subject = (char*)malloc(strlen(subject) + 1);
    strcpy(email->subject, subject);

    email->message = (char*)malloc(strlen(message) + 1);
    strcpy(email->message, message);

    emails[emails_count++] = email;

    return 0;
}

void print_email(Email* email) {
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Message:\n%s\n", email->message);
}

void print_inbox() {
    for(int i = 0; i < emails_count; i++) {
        printf("Email %d:\n", i + 1);
        print_email(emails[i]);
        printf("\n");
    }
}

int main() {
    // let's send some emails
    send_email("john@example.com", "Hello John", "Hey John, how are you?");
    send_email("jane@example.com", "Hi Jane", "Hi Jane, what's up?");
    send_email("jim@example.com", "Meeting Reminder", "Hi Jim, just a quick reminder that we have a meeting tomorrow at 3PM.");

    // let's print the inbox
    print_inbox();

    // let's free the memory we've allocated for the emails
    for(int i = 0; i < emails_count; i++) {
        free(emails[i]->recipient);
        free(emails[i]->subject);
        free(emails[i]->message);
        free(emails[i]);
    }

    return 0;
}