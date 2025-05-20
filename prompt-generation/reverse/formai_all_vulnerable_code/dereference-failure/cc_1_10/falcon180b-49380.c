//Falcon-180B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH (1024 * 10)

typedef struct {
    char* from;
    char* subject;
    char* body;
} Email;

Email* email_new() {
    Email* email = (Email*)malloc(sizeof(Email));
    email->from = NULL;
    email->subject = NULL;
    email->body = NULL;
    return email;
}

void email_free(Email* email) {
    free(email->from);
    free(email->subject);
    free(email->body);
    free(email);
}

int email_parse(Email* email, char* line) {
    char* value = strchr(line, ':');
    if (value == NULL) {
        return 0;
    }

    *value = '\0';
    value++;

    if (strcmp(line, "From") == 0) {
        email->from = strdup(value);
    } else if (strcmp(line, "Subject") == 0) {
        email->subject = strdup(value);
    } else if (strcmp(line, "Content-Type") == 0 &&
               strstr(value, "text/plain")!= NULL) {
        email->body = strdup("");
    } else if (strcmp(line, "") == 0) {
        char* body_line = strdup(value);
        int body_length = strlen(email->body) + strlen(body_line) + 2;
        if (body_length > MAX_BODY_LENGTH) {
            fprintf(stderr, "Email body is too long.\n");
            return 0;
        }

        email->body = realloc(email->body, body_length);
        strcat(email->body, "\r\n");
        strcat(email->body, body_line);
        strcat(email->body, "\r\n");

        free(body_line);
    }

    return 1;
}

int main() {
    FILE* fp = fopen("email.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Could not open email file.\n");
        return 1;
    }

    Email* email = email_new();
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (!email_parse(email, line)) {
            email_free(email);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    printf("From: %s\nSubject: %s\n\n%s", email->from, email->subject, email->body);

    email_free(email);

    return 0;
}