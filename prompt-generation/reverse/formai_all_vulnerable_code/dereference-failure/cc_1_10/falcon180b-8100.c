//Falcon-180B DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char* from;
    char* to;
    char* subject;
    char* body;
} Email;

Email* create_email() {
    Email* email = (Email*)malloc(sizeof(Email));
    email->from = NULL;
    email->to = NULL;
    email->subject = NULL;
    email->body = NULL;
    return email;
}

void free_email(Email* email) {
    if (email!= NULL) {
        if (email->from!= NULL) {
            free(email->from);
        }
        if (email->to!= NULL) {
            free(email->to);
        }
        if (email->subject!= NULL) {
            free(email->subject);
        }
        if (email->body!= NULL) {
            free(email->body);
        }
        free(email);
    }
}

int is_valid_email(char* email) {
    int len = strlen(email);
    if (len < 6 || len > MAX_EMAIL_LENGTH) {
        return 0;
    }
    if (email[0]!= '@') {
        return 0;
    }
    for (int i = 1; i < len; i++) {
        if (!isalnum(email[i]) && email[i]!= '.' && email[i]!= '_') {
            return 0;
        }
    }
    return 1;
}

int is_valid_subject(char* subject) {
    int len = strlen(subject);
    if (len < 1 || len > MAX_SUBJECT_LENGTH) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isprint(subject[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Email* email = create_email();
    char* from = "example@example.com";
    char* to = "recipient@example.com";
    char* subject = "Hello, world!";
    char* body = "This is a test email. ";
    email->from = strdup(from);
    email->to = strdup(to);
    email->subject = strdup(subject);
    email->body = strdup(body);

    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);

    free_email(email);
    return 0;
}