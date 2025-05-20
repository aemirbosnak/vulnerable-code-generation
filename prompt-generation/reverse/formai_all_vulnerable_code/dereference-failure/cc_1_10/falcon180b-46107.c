//Falcon-180B DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 80
#define MAX_BODY_LENGTH 1024
#define EMAIL_SEPARATOR '\n\n'

typedef struct {
    char from[MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char *from, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached\n");
        return;
    }
    strcpy(emails[num_emails].from, from);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    time(&emails[num_emails].timestamp);
    num_emails++;
}

void print_emails() {
    int i;
    printf("Number of emails: %d\n", num_emails);
    for (i = 0; i < num_emails; i++) {
        printf("From: %s\nSubject: %s\nBody:\n%s\n\n", emails[i].from, emails[i].subject, emails[i].body);
    }
}

void search_emails(char *search_term) {
    int i;
    for (i = 0; i < num_emails; i++) {
        if (strstr(emails[i].subject, search_term) || strstr(emails[i].body, search_term)) {
            printf("Matching email found:\n");
            printf("From: %s\nSubject: %s\nBody:\n%s\n\n", emails[i].from, emails[i].subject, emails[i].body);
        }
    }
}

int main() {
    char input[MAX_BODY_LENGTH];
    char search_term[MAX_SUBJECT_LENGTH];
    while (true) {
        printf("Enter an email (type'search' to search for emails):\n");
        fgets(input, MAX_BODY_LENGTH, stdin);
        if (strcmp(input, "search") == 0) {
            printf("Enter search term:\n");
            fgets(search_term, MAX_SUBJECT_LENGTH, stdin);
            search_emails(search_term);
        } else {
            char *from = strtok(input, EMAIL_SEPARATOR);
            char *subject = strtok(NULL, EMAIL_SEPARATOR);
            char *body = strtok(NULL, EMAIL_SEPARATOR);
            add_email(from, subject, body);
        }
    }
    return 0;
}