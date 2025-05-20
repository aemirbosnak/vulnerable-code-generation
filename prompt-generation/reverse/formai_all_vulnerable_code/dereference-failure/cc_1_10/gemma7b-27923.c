//Gemma-7B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
    char *subject;
    char *from;
    char *to;
    char *body;
    struct Email *next;
} Email;

Email *insertEmail(Email *head, char *subject, char *from, char *to, char *body) {
    Email *newEmail = malloc(sizeof(Email));
    newEmail->subject = strdup(subject);
    newEmail->from = strdup(from);
    newEmail->to = strdup(to);
    newEmail->body = strdup(body);
    newEmail->next = NULL;

    if (head == NULL) {
        head = newEmail;
    } else {
        head->next = newEmail;
    }

    return head;
}

void displayEmails(Email *head) {
    Email *currentEmail = head;

    while (currentEmail) {
        printf("Subject: %s\n", currentEmail->subject);
        printf("From: %s\n", currentEmail->from);
        printf("To: %s\n", currentEmail->to);
        printf("Body: %s\n", currentEmail->body);
        printf("\n");
        currentEmail = currentEmail->next;
    }
}

int main() {
    Email *head = NULL;

    insertEmail(head, "Hello, world!", "john.doe@example.com", "jane.doe@example.com", "This is a test email.");

    insertEmail(head, "Another email", "bob.smith@example.com", "jane.doe@example.com", "This is another email.");

    displayEmails(head);

    return 0;
}