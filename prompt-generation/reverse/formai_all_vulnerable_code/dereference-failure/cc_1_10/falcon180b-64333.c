//Falcon-180B DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 2048
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 10240

typedef struct email {
    char sender[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    struct email* next;
} Email;

Email* create_email(char* sender, char* subject, char* body) {
    Email* email = (Email*) malloc(sizeof(Email));
    strcpy(email->sender, sender);
    strcpy(email->subject, subject);
    strcpy(email->body, body);
    email->timestamp = time(NULL);
    email->next = NULL;
    return email;
}

void add_email(Email** head, Email* email) {
    if (*head == NULL) {
        *head = email;
        return;
    }
    Email* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = email;
}

void print_email(Email* email) {
    printf("Sender: %s\n", email->sender);
    printf("Subject: %s\n", email->subject);
    printf("Timestamp: %s\n", ctime(&email->timestamp));
    printf("Body:\n%s\n", email->body);
}

int main() {
    Email* head = NULL;
    char input[MAX_EMAIL_LENGTH];
    while (fgets(input, MAX_EMAIL_LENGTH, stdin)!= NULL) {
        Email* email = create_email(input, "", "");
        add_email(&head, email);
    }
    Email* current = head;
    while (current!= NULL) {
        print_email(current);
        current = current->next;
    }
    return 0;
}