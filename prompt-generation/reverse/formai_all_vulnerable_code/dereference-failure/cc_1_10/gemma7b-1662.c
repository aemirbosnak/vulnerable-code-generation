//Gemma-7B DATASET v1.0 Category: Email Client ; Style: expert-level
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

void addEmail(Email *emailList, Email *newEmail) {
    if (emailList == NULL) {
        emailList = newEmail;
    } else {
        Email *currentEmail = emailList;
        while (currentEmail->next) {
            currentEmail = currentEmail->next;
        }
        currentEmail->next = newEmail;
    }
}

void printEmails(Email *emailList) {
    Email *currentEmail = emailList;
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
    Email *emailList = NULL;
    Email *newEmail = createEmail("Hello, world!", "john.doe@example.com", "jane.doe@example.com", "This is a test email.");
    addEmail(emailList, newEmail);

    newEmail = createEmail("Another email", "bob.smith@example.com", "jane.doe@example.com", "This is another test email.");
    addEmail(emailList, newEmail);

    printEmails(emailList);

    return 0;
}