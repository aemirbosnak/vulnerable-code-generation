//Falcon-180B DATASET v1.0 Category: Email Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RECIPIENTS 10
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_LINE_LENGTH];
    char email[MAX_LINE_LENGTH];
} recipient_t;

typedef struct {
    char from[MAX_LINE_LENGTH];
    char to[MAX_LINE_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_LINE_LENGTH];
} email_t;

int main() {
    char line[MAX_LINE_LENGTH];
    char delimiter = ':';
    char *token;
    email_t email;
    int num_recipients = 0;
    recipient_t recipients[MAX_RECIPIENTS];

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(line, &delimiter);
        strcpy(email.from, token);
        token = strtok(NULL, &delimiter);
        strcpy(email.to, token);
        token = strtok(NULL, &delimiter);
        strcpy(email.subject, token);
        token = strtok(NULL, &delimiter);
        strcpy(email.body, token);

        email.body[strcspn(email.body, "\r")] = '\0';

        num_recipients = 0;
        token = strtok(email.to, ",");
        while (token!= NULL && num_recipients < MAX_RECIPIENTS) {
            strcpy(recipients[num_recipients].name, token);
            strcpy(recipients[num_recipients].email, token);
            num_recipients++;
            token = strtok(NULL, ",");
        }

        printf("From: %s\n", email.from);
        printf("To: %s\n", email.to);
        printf("Subject: %s\n", email.subject);
        printf("Body:\n%s\n", email.body);
        printf("\n");

        for (int i = 0; i < num_recipients; i++) {
            printf("Recipient %d:\n", i+1);
            printf("Name: %s\n", recipients[i].name);
            printf("Email: %s\n", recipients[i].email);
            printf("\n");
        }
    }

    return 0;
}