//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 1024
#define MAX_EMAIL_LENGTH 1024

typedef struct email {
    char *subject;
    char *body;
    char *from;
    char *to;
    char *date;
} Email;

Email *parse_email(char *line) {
    Email *email = (Email *) malloc(sizeof(Email));
    char *subject = NULL;
    char *body = NULL;
    char *from = NULL;
    char *to = NULL;
    char *date = NULL;

    char *token = strtok(line, "\r\n");
    while (token!= NULL) {
        if (strcasecmp(token, "Subject:") == 0) {
            subject = strtok(NULL, "\r\n");
        } else if (strcasecmp(token, "From:") == 0) {
            from = strtok(NULL, "\r\n");
        } else if (strcasecmp(token, "To:") == 0) {
            to = strtok(NULL, "\r\n");
        } else if (strcasecmp(token, "Date:") == 0) {
            date = strtok(NULL, "\r\n");
        } else if (body == NULL) {
            body = strtok(NULL, "\r\n");
        }
        token = strtok(NULL, "\r\n");
    }

    email->subject = subject;
    email->body = body;
    email->from = from;
    email->to = to;
    email->date = date;

    return email;
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Date: %s\n", email->date);
    printf("\n%s\n", email->body);
}

int main() {
    char line[MAX_LINE_LENGTH];
    Email *email = NULL;

    FILE *fp = fopen("inbox", "r");
    if (fp == NULL) {
        printf("Error opening inbox\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (email!= NULL) {
            printf("\n");
        }
        email = parse_email(line);
        print_email(email);
    }

    fclose(fp);
    free(email);

    return 0;
}