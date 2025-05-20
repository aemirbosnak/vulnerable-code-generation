//Falcon-180B DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char *from;
    char *subject;
    char *email;
} Email;

Email *create_email() {
    Email *email = (Email *)malloc(sizeof(Email));
    if (email == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    email->from = NULL;
    email->subject = NULL;
    email->email = NULL;
    return email;
}

void free_email(Email *email) {
    if (email == NULL) {
        return;
    }
    if (email->from!= NULL) {
        free(email->from);
    }
    if (email->subject!= NULL) {
        free(email->subject);
    }
    if (email->email!= NULL) {
        free(email->email);
    }
    free(email);
}

Email *parse_email(char *line) {
    Email *email = create_email();
    char *token = strtok(line, " ");
    while (token!= NULL) {
        if (strcasecmp(token, "From:") == 0) {
            email->from = strdup(token + strlen("From:"));
        } else if (strcasecmp(token, "Subject:") == 0) {
            email->subject = strdup(token + strlen("Subject:"));
        } else if (strcasecmp(token, "To:") == 0) {
            // Skip To: line
        } else if (strcasecmp(token, "Date:") == 0) {
            // Skip Date: line
        } else if (strcasecmp(token, "Content-Type:") == 0) {
            // Skip Content-Type: line
        }
        token = strtok(NULL, " ");
    }
    return email;
}

void print_email(Email *email) {
    if (email == NULL) {
        fprintf(stdout, "No email found\n");
        return;
    }
    fprintf(stdout, "From: %s\n", email->from);
    fprintf(stdout, "Subject: %s\n", email->subject);
    fprintf(stdout, "Email: %s\n", email->email);
}

int main(int argc, char *argv[]) {
    FILE *input_file;
    char line[MAX_LINE_LENGTH];
    Email *email;
    input_file = fopen("emails.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Cannot open input file\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        email = parse_email(line);
        if (email!= NULL) {
            print_email(email);
        }
        free_email(email);
    }
    fclose(input_file);
    return 0;
}