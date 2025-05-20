//Falcon-180B DATASET v1.0 Category: Email Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 1024
#define MAX_BODY_LENGTH 4096

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[100];
int num_emails = 0;

void parse_email(char* line) {
    char* from = strtok(line, " ");
    char* to = strtok(NULL, " ");
    char* subject = strtok(NULL, " ");
    char* body = strtok(NULL, "\n");

    strcpy(emails[num_emails].from, from);
    strcpy(emails[num_emails].to, to);
    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);

    num_emails++;
}

int main() {
    FILE* file = fopen("emails.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_email(line);
    }

    fclose(file);

    // Print emails
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\n", emails[i].from);
        printf("To: %s\n", emails[i].to);
        printf("Subject: %s\n", emails[i].subject);
        printf("Body: %s\n\n", emails[i].body);
    }

    return 0;
}