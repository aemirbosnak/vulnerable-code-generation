//Gemma-7B DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store email information
typedef struct Email {
    char *subject;
    char *from;
    char *to;
    char *body;
    struct Email *next;
} Email;

// Function to insert an email into the list
void insertEmail(Email **head, char *subject, char *from, char *to, char *body) {
    Email *newEmail = malloc(sizeof(Email));
    newEmail->subject = strdup(subject);
    newEmail->from = strdup(from);
    newEmail->to = strdup(to);
    newEmail->body = strdup(body);
    newEmail->next = NULL;

    if (*head == NULL) {
        *head = newEmail;
    } else {
        (*head)->next = newEmail;
    }
}

// Function to print all emails
void printEmails(Email *head) {
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

    // Insert some emails into the list
    insertEmail(&head, "Hello, world!", "john.doe@example.com", "jane.doe@example.com", "This is an email.");
    insertEmail(&head, "Greetings, from the East!", "bill.smith@example.com", "mary.jones@example.com", "How are you?");

    // Print all emails
    printEmails(head);

    return 0;
}