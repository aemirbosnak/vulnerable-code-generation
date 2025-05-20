//FormAI DATASET v1.0 Category: Email Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// function to handle user input
char* getUserInput(char* prompt) {
    printf("%s", prompt);
    char* input = (char*) malloc(MAX_BUFFER * sizeof(char));
    fgets(input, MAX_BUFFER, stdin);

    // remove trailing newline character
    input[strcspn(input, "\n")] = 0;

    return input;
}

// sample email structure
typedef struct Email {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
} Email;

// function to create a new email
Email* createEmail(char* sender, char* recipient, char* subject, char* body) {
    Email* email = (Email*) malloc(sizeof(Email));
    email->sender = sender;
    email->recipient = recipient;
    email->subject = subject;
    email->body = body;

    return email;
}

// function to print email details
void printEmail(Email* email) {
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    // get user input for email details
    char* sender = getUserInput("Enter sender email: ");
    char* recipient = getUserInput("Enter recipient email: ");
    char* subject = getUserInput("Enter email subject: ");
    char* body = getUserInput("Enter email body: ");

    // create new email
    Email* email = createEmail(sender, recipient, subject, body);

    // print email details
    printEmail(email);

    // free memory
    free(sender);
    free(recipient);
    free(subject);
    free(body);
    free(email);

    return 0;
}