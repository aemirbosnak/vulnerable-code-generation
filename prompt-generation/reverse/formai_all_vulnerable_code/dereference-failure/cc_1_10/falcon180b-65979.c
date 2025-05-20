//Falcon-180B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char from[MAX_SUBJECT_LENGTH];
    char to[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email* create_email() {
    Email* email = (Email*) malloc(sizeof(Email));
    strcpy(email->subject, "");
    strcpy(email->from, "");
    strcpy(email->to, "");
    strcpy(email->body, "");
    return email;
}

void free_email(Email* email) {
    free(email);
}

int main() {
    Email* email = create_email();
    char input[1000];
    while(fgets(input, sizeof(input), stdin)) {
        if(strstr(input, "Subject:")!= NULL) {
            char* subject = strtok(input, ":");
            strcpy(email->subject, subject);
        } else if(strstr(input, "From:")!= NULL) {
            char* from = strtok(input, ":");
            strcpy(email->from, from);
        } else if(strstr(input, "To:")!= NULL) {
            char* to = strtok(input, ":");
            strcpy(email->to, to);
        } else if(strstr(input, "Body:")!= NULL) {
            char* body = strtok(input, ":");
            strcpy(email->body, body);
        } else if(strstr(input, "Send")!= NULL) {
            printf("Sending email...\n");
            printf("Subject: %s\n", email->subject);
            printf("From: %s\n", email->from);
            printf("To: %s\n", email->to);
            printf("Body: %s\n", email->body);
        }
    }
    free_email(email);
    return 0;
}