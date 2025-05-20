//Gemma-7B DATASET v1.0 Category: Email Client ; Style: scalable
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

void addEmail(Email **head, char *subject, char *from, char *to, char *body) {
    Email *email = createEmail(subject, from, to, body);
    if (*head == NULL) {
        *head = email;
    } else {
        (*head)->next = email;
    }
}

void printEmails(Email *head) {
    Email *current = head;
    while (current) {
        printf("Subject: %s\n", current->subject);
        printf("From: %s\n", current->from);
        printf("To: %s\n", current->to);
        printf("Body: %s\n", current->body);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Email *emails = NULL;
    addEmail(&emails, "Hello World!", "john.doe@gmail.com", "jane.doe@gmail.com", "This is a test email.");
    addEmail(&emails, "Another email", "bob.smith@gmail.com", "jane.doe@gmail.com", "This is another test email.");
    printEmails(emails);
    return 0;
}