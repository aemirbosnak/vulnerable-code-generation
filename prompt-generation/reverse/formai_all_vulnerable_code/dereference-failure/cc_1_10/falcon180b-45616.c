//Falcon-180B DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_SUBJECT_LEN 1024
#define MAX_FROM_LEN 1024
#define MAX_TO_LEN 1024
#define MAX_BODY_LEN 10240

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *body;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    char *token;
    int count = 0;

    email->subject = malloc(MAX_SUBJECT_LEN);
    email->from = malloc(MAX_FROM_LEN);
    email->to = malloc(MAX_TO_LEN);
    email->body = malloc(MAX_BODY_LEN);

    token = strtok(line, ":");
    strncpy(email->subject, token, MAX_SUBJECT_LEN);
    count++;

    token = strtok(NULL, ":");
    strncpy(email->from, token, MAX_FROM_LEN);
    count++;

    token = strtok(NULL, ":");
    strncpy(email->to, token, MAX_TO_LEN);
    count++;

    token = strtok(NULL, "\r\n");
    strncpy(email->body, token, MAX_BODY_LEN);
    count++;

    return email;
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Body:\n%s\n", email->body);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    Email *email;

    fp = fopen("emails.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        email = parse_email(line);
        print_email(email);
        free(email->subject);
        free(email->from);
        free(email->to);
        free(email->body);
        free(email);
    }

    fclose(fp);

    return 0;
}