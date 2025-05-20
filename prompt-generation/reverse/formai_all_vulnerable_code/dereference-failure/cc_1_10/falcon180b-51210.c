//Falcon-180B DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char *sender;
    char *subject;
    char *body;
    int is_read;
} Email;

Email emails[MAX_EMAILS];
int num_emails;

void add_email(char *sender, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Email inbox is full.\n");
        return;
    }
    Email *email = &emails[num_emails];
    email->sender = strdup(sender);
    email->subject = strdup(subject);
    email->body = strdup(body);
    email->is_read = 0;
    num_emails++;
}

void print_emails() {
    printf("Inbox:\n");
    for (int i = 0; i < num_emails; i++) {
        Email *email = &emails[i];
        printf("%d. From: %s\nSubject: %s\n", i+1, email->sender, email->subject);
    }
}

void read_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Error: Invalid email index.\n");
        return;
    }
    Email *email = &emails[index];
    email->is_read = 1;
    printf("Email #%d:\n", index+1);
    printf("From: %s\n", email->sender);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

int main() {
    add_email("johndoe@example.com", "Hello", "Hi, how are you?");
    add_email("janedoe@example.com", "Re: Meeting", "Let's meet at 2 PM tomorrow.");
    print_emails();
    read_email(0);
    print_emails();
    return 0;
}