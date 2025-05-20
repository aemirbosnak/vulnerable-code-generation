//Falcon-180B DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_SUBJECT_SIZE 1024
#define MAX_BODY_SIZE 1024 * 100
#define MAX_TO_SIZE 1024
#define MAX_CC_SIZE 1024
#define MAX_BCC_SIZE 1024
#define MAX_HEADER_SIZE 1024 * 10

typedef struct {
    char *to;
    char *cc;
    char *bcc;
    char *subject;
    char *body;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    memset(email, 0, sizeof(Email));

    char *ptr = strchr(line, ':');
    if (ptr == NULL) {
        free(email);
        return NULL;
    }

    *ptr = '\0';
    email->to = strdup(line);

    line = ptr + 1;
    while (isspace(*line)) line++;

    ptr = strchr(line, ':');
    if (ptr == NULL) {
        free(email->to);
        free(email);
        return NULL;
    }

    *ptr = '\0';
    email->subject = strdup(line);

    line = ptr + 1;
    while (isspace(*line)) line++;

    ptr = strchr(line, '\n');
    if (ptr == NULL) {
        free(email->to);
        free(email->subject);
        free(email);
        return NULL;
    }

    *ptr = '\0';
    email->body = strdup(line);

    return email;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    Email *email = NULL;

    fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        email = parse_email(line);
        if (email == NULL) continue;

        printf("To: %s\n", email->to);
        printf("Subject: %s\n", email->subject);
        printf("Body:\n%s\n\n", email->body);

        free(email->to);
        free(email->subject);
        free(email->body);
        free(email);
    }

    fclose(fp);
    return 0;
}