//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of emails that can be stored
#define MAX_EMAIL_NUM 100

// Define the structure of an email
typedef struct Email {
    char *name;
    char *subject;
    char *message;
    struct Email *next;
} Email;

// Function to insert an email into the list
void insertEmail(Email **head, char *name, char *subject, char *message) {
    Email *newEmail = malloc(sizeof(Email));
    newEmail->name = strdup(name);
    newEmail->subject = strdup(subject);
    newEmail->message = strdup(message);
    newEmail->next = NULL;

    if (*head == NULL) {
        *head = newEmail;
    } else {
        (*head)->next = newEmail;
    }
}

// Function to print all emails in the list
void printEmails(Email *head) {
    Email *currentEmail = head;
    while (currentEmail) {
        printf("Name: %s\n", currentEmail->name);
        printf("Subject: %s\n", currentEmail->subject);
        printf("Message: %s\n", currentEmail->message);
        printf("\n");
        currentEmail = currentEmail->next;
    }
}

int main() {
    Email *head = NULL;

    // Insert some emails
    insertEmail(&head, "John Doe", "Subject 1", "This is email 1");
    insertEmail(&head, "Jane Doe", "Subject 2", "This is email 2");
    insertEmail(&head, "Bill Smith", "Subject 3", "This is email 3");

    // Print all emails
    printEmails(head);

    return 0;
}