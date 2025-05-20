//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_EMAIL_BODY_LEN 1048576

typedef struct {
    char *from;
    char *to;
    char *date;
    char *subject;
    char *body;
} email_t;

int read_email(email_t *email, FILE *fp) {
    char line[MAX_LINE_LEN];

    // Read the "From" line.
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
        return -1;
    }
    email->from = strdup(line);

    // Read the "To" line.
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
        return -1;
    }
    email->to = strdup(line);

    // Read the "Date" line.
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
        return -1;
    }
    email->date = strdup(line);

    // Read the "Subject" line.
    if (fgets(line, MAX_LINE_LEN, fp) == NULL) {
        return -1;
    }
    email->subject = strdup(line);

    // Read the body of the email.
    email->body = malloc(MAX_EMAIL_BODY_LEN);
    if (email->body == NULL) {
        return -1;
    }
    int len = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        len += strlen(line);
        if (len + 1 >= MAX_EMAIL_BODY_LEN) {
            email->body = realloc(email->body, len + 1);
            if (email->body == NULL) {
                return -1;
            }
        }
        strcat(email->body, line);
    }

    return 0;
}

void print_email(email_t *email) {
    printf("From: %s", email->from);
    printf("To: %s", email->to);
    printf("Date: %s", email->date);
    printf("Subject: %s", email->subject);
    printf("\n\n%s", email->body);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <email_file>", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    email_t email;
    int result = read_email(&email, fp);
    if (result != 0) {
        printf("Error reading email");
        return EXIT_FAILURE;
    }

    print_email(&email);

    fclose(fp);

    return EXIT_SUCCESS;
}