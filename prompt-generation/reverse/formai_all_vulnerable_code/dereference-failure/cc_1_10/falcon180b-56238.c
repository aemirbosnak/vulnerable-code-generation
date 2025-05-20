//Falcon-180B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJECT 1024
#define MAX_FROM 1024
#define MAX_TO 1024
#define MAX_BODY 1024 * 10
#define DELIM ":"

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *body;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    email->subject = malloc(MAX_SUBJECT);
    email->from = malloc(MAX_FROM);
    email->to = malloc(MAX_TO);
    email->body = malloc(MAX_BODY);

    char *subject = strtok(line, DELIM);
    strcpy(email->subject, subject);

    char *from_to = strtok(NULL, DELIM);
    char *from = strtok(from_to, ",");
    char *to = strtok(NULL, ",");
    strcpy(email->from, from);
    strcpy(email->to, to);

    char *body = strtok(NULL, "\r\n");
    strcat(email->body, body);

    return email;
}

void print_email(Email *email) {
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Body:\n%s", email->body);
}

int main() {
    char line[MAX_LINE];
    Email *email = NULL;

    FILE *fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (email!= NULL) {
            print_email(email);
        }
        email = parse_email(line);
    }

    if (email!= NULL) {
        print_email(email);
    }

    fclose(fp);
    return 0;
}