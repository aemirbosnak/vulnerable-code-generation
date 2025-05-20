//Falcon-180B DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SUBJ 1024
#define MAX_FROM 1024
#define MAX_TO 1024
#define MAX_MSG 10240

typedef struct {
    char *subject;
    char *from;
    char *to;
    char *msg;
} Email;

Email *parse_email(char *line) {
    Email *email = malloc(sizeof(Email));
    char *p;
    char *subject = NULL;
    char *from = NULL;
    char *to = NULL;
    char *msg = NULL;
    int in_subject = 0;
    int in_from = 0;
    int in_to = 0;
    int in_msg = 0;

    email->subject = subject;
    email->from = from;
    email->to = to;
    email->msg = msg;

    return email;
}

void free_email(Email *email) {
    free(email->subject);
    free(email->from);
    free(email->to);
    free(email->msg);
    free(email);
}

int main(int argc, char **argv) {
    FILE *inbox;
    char line[MAX_LINE];
    Email *email;

    inbox = fopen("inbox", "r");
    if (inbox == NULL) {
        printf("Error: cannot open inbox\n");
        return 1;
    }

    while (fgets(line, MAX_LINE, inbox)!= NULL) {
        email = parse_email(line);
        printf("Subject: %s\n", email->subject);
        printf("From: %s\n", email->from);
        printf("To: %s\n", email->to);
        printf("Message:\n%s\n\n", email->msg);
        free_email(email);
    }

    fclose(inbox);
    return 0;
}