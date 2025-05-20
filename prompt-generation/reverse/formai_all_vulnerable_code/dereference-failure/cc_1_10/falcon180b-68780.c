//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email* parse_email(char* line)
{
    Email* email = malloc(sizeof(Email));
    char* from = strtok(line, " ");
    char* to = strtok(NULL, " ");
    char* subject = strtok(NULL, " ");
    char* body = strtok(NULL, " ");

    strcpy(email->from, from);
    strcpy(email->to, to);
    strcpy(email->subject, subject);
    strcpy(email->body, body);

    return email;
}

void send_email(Email* email)
{
    printf("FROM: %s\n", email->from);
    printf("TO: %s\n", email->to);
    printf("SUBJECT: %s\n", email->subject);
    printf("BODY:\n%s\n", email->body);
}

int main()
{
    FILE* input_file = fopen("inbox.txt", "r");
    if (input_file == NULL) {
        printf("Error: Unable to open inbox.txt\n");
        exit(1);
    }

    Email* email = NULL;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (email!= NULL) {
            send_email(email);
            free(email);
            email = NULL;
        }
        email = parse_email(line);
    }

    if (email!= NULL) {
        send_email(email);
        free(email);
    }

    fclose(input_file);
}