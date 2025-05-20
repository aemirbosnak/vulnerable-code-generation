//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 2048
#define MAX_SUBJECT_LENGTH 2048
#define MAX_FROM_LENGTH 2048
#define MAX_TO_LENGTH 2048
#define MAX_BODY_LENGTH 2048
#define MAX_HEADER_LENGTH 2048

#define EMAIL_HEADER_FROM "From: "
#define EMAIL_HEADER_TO "To: "
#define EMAIL_HEADER_SUBJECT "Subject: "
#define EMAIL_HEADER_DATE "Date: "

typedef struct {
    char* from;
    char* to;
    char* subject;
    char* date;
    char* body;
} Email;

Email* parseEmail(char* emailText) {
    Email* email = malloc(sizeof(Email));
    char* line = strtok(emailText, "\n");
    email->from = strtok(line, " ");
    line = strtok(NULL, "\n");
    email->to = strtok(line, " ");
    line = strtok(NULL, "\n");
    email->subject = strtok(line, " ");
    line = strtok(NULL, "\n");
    email->date = strtok(line, " ");
    line = strtok(NULL, "\n");
    email->body = strtok(line, " ");
    return email;
}

void printEmail(Email* email) {
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Date: %s\n", email->date);
    printf("Body:\n%s\n", email->body);
}

int main() {
    char emailText[MAX_LINE_LENGTH];
    fgets(emailText, MAX_LINE_LENGTH, stdin);
    Email* email = parseEmail(emailText);
    printEmail(email);
    free(email->from);
    free(email->to);
    free(email->subject);
    free(email->date);
    free(email->body);
    free(email);
    return 0;
}