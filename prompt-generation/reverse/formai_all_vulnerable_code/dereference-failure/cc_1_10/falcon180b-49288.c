//Falcon-180B DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct Email {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void parse_email(char* email_text) {
    Email* email = &emails[num_emails];
    strcpy(email->from, email_text);

    char* from = strtok(email_text, "@");
    char* domain = strtok(NULL, "@");
    strcpy(email->to, domain);

    strcpy(email->subject, "");
    strcpy(email->body, "");

    char* line = strtok(NULL, "\n");
    while (line!= NULL) {
        if (strstr(line, "Subject:")!= NULL) {
            strcpy(email->subject, line + 9);
        } else if (strstr(line, "Body:")!= NULL) {
            strcpy(email->body, line + 6);
        }
        line = strtok(NULL, "\n");
    }

    email->timestamp = time(NULL);
    num_emails++;
}

void display_emails() {
    printf("Email\tFrom\tTo\tSubject\tBody\tTimestamp\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d\t%s\t%s\t%s\t%s\t%ld\n", i+1, emails[i].from, emails[i].to, emails[i].subject, emails[i].body, emails[i].timestamp);
    }
}

int main() {
    FILE* fp = fopen("emails.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char email_text[BUFFER_SIZE];
    while (fgets(email_text, BUFFER_SIZE, fp)!= NULL) {
        parse_email(email_text);
    }

    fclose(fp);

    display_emails();

    return 0;
}