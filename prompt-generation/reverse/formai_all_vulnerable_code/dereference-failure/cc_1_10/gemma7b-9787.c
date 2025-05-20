//Gemma-7B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
    char *subject;
    char *from;
    char *to;
    char *body;
    struct Email *next;
} Email;

Email *createEmail(char *subject, char *from, char *to, char *body) {
    Email *email = malloc(sizeof(Email));
    email->subject = strdup(subject);
    email->from = strdup(from);
    email->to = strdup(to);
    email->body = strdup(body);
    email->next = NULL;
    return email;
}

void addEmail(Email **head, Email *newEmail) {
    if (*head == NULL) {
        *head = newEmail;
    } else {
        (*head)->next = newEmail;
        *head = newEmail;
    }
}

void printEmails(Email *head) {
    Email *currentEmail = head;
    while (currentEmail) {
        printf("Subject: %s\n", currentEmail->subject);
        printf("From: %s\n", currentEmail->from);
        printf("To: %s\n", currentEmail->to);
        printf("Body: %s\n\n", currentEmail->body);
        currentEmail = currentEmail->next;
    }
}

int main() {
    Email *head = NULL;
    addEmail(&head, createEmail("Hello, world!", "john.doe@example.com", "jane.doe@example.com", "This is an email"));
    addEmail(&head, createEmail("Another email", "bill.smith@example.com", "jane.doe@example.com", "This is another email"));
    printEmails(head);

    return 0;
}