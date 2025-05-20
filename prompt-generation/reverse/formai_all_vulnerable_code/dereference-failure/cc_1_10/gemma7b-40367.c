//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of emails that can be stored
#define MAX_EMAIL_NUM 100

// Define the structure of an email
typedef struct Email {
    char *subject;
    char *from;
    char *to;
    char *body;
    struct Email *next;
} Email;

// Create a new email
Email *new_email() {
    Email *email = malloc(sizeof(Email));
    email->subject = malloc(256);
    email->from = malloc(256);
    email->to = malloc(256);
    email->body = malloc(256);
    email->next = NULL;
    return email;
}

// Add an email to the list
void add_email(Email **head, Email *email) {
    if (*head == NULL) {
        *head = email;
    } else {
        (*head)->next = email;
        *head = email;
    }
}

// Print all emails
void print_emails(Email *head) {
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
    Email *head = NULL;

    // Create a few emails
    Email *email1 = new_email();
    email1->subject = "Love Letter";
    email1->from = "Romeo";
    email1->to = "Juliet";
    email1->body = "My dearest Juliet, I write to you with a heart full of love.";

    Email *email2 = new_email();
    email2->subject = "Secret Admiration";
    email2->from = "Anonymous";
    email2->to = "Juliet";
    email2->body = "You are my secret muse, my hidden gem.";

    Email *email3 = new_email();
    email3->subject = "Open Heart";
    email3->from = "Romeo";
    email3->to = "Juliet";
    email3->body = "I am yours, forever and always.";

    // Add the emails to the list
    add_email(&head, email1);
    add_email(&head, email2);
    add_email(&head, email3);

    // Print the emails
    print_emails(head);

    return 0;
}