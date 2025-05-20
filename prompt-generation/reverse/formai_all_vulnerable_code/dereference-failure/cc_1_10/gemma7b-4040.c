//Gemma-7B DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Email {
    char* subject;
    char* sender;
    char* recipient;
    char* body;
    struct Email* next;
} Email;

Email* email_new() {
    Email* email = malloc(sizeof(Email));
    email->subject = malloc(MAX_BUFFER_SIZE);
    email->sender = malloc(MAX_BUFFER_SIZE);
    email->recipient = malloc(MAX_BUFFER_SIZE);
    email->body = malloc(MAX_BUFFER_SIZE);
    email->next = NULL;
    return email;
}

void email_free(Email* email) {
    free(email->subject);
    free(email->sender);
    free(email->recipient);
    free(email->body);
    free(email);
}

void email_add(Email* head, char* subject, char* sender, char* recipient, char* body) {
    Email* email = email_new();
    strcpy(email->subject, subject);
    strcpy(email->sender, sender);
    strcpy(email->recipient, recipient);
    strcpy(email->body, body);
    email->next = head;
    head = email;
}

void email_print(Email* head) {
    while (head) {
        printf("Subject: %s\n", head->subject);
        printf("From: %s\n", head->sender);
        printf("To: %s\n", head->recipient);
        printf("Body: %s\n", head->body);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Email* head = NULL;
    email_add(head, "Welcome to the Email Client!", "donald@knuth.com", "john.doe@gmail.com", "This is a sample email.");
    email_add(head, "Another Email!", "bill@gates.com", "jane.doe@yahoo.com", "Another sample email.");
    email_print(head);

    email_free(head);

    return 0;
}