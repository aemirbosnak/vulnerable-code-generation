//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct email {
    char* subject;
    char* body;
    struct email* next;
} email;

// Global variable to store the head of the linked list of emails
email* head = NULL;

void add_email(char* subject, char* body) {
    // Create a new email struct
    email* new_email = (email*)malloc(sizeof(email));
    new_email->subject = (char*)malloc(strlen(subject) + 1);
    new_email->body = (char*)malloc(strlen(body) + 1);
    strcpy(new_email->subject, subject);
    strcpy(new_email->body, body);
    new_email->next = NULL;

    // Add the new email to the linked list
    if (head == NULL) {
        head = new_email;
    } else {
        email* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_email;
    }
}

void print_emails() {
    // Iterate over the linked list of emails and print each email
    email* current = head;
    while (current != NULL) {
        printf("Subject: %s\n", current->subject);
        printf("Body: %s\n", current->body);
        current = current->next;
    }
}

void delete_email(char* subject) {
    // Iterate over the linked list of emails and delete the email with the specified subject
    email* current = head;
    email* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->subject, subject) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->subject);
            free(current->body);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    // Add some emails to the linked list
    add_email("Test Email 1", "This is the body of the first test email.");
    add_email("Test Email 2", "This is the body of the second test email.");
    add_email("Test Email 3", "This is the body of the third test email.");

    // Print the emails
    print_emails();

    // Delete an email
    delete_email("Test Email 2");

    // Print the emails again
    print_emails();

    return 0;
}