//Falcon-180B DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000

typedef struct {
    char from[MAX_LINE_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

Email* read_email(FILE* fp) {
    Email* email = malloc(sizeof(Email));
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (strncmp(line, "From:", 6) == 0) {
            strncpy(email->from, line + 6, MAX_LINE_LEN - 1);
            email->from[MAX_LINE_LEN - 1] = '\0';
        } else if (strncmp(line, "Subject:", 9) == 0) {
            strncpy(email->subject, line + 9, MAX_SUBJECT_LEN - 1);
            email->subject[MAX_SUBJECT_LEN - 1] = '\0';
        } else if (strncmp(line, "Body:", 5) == 0) {
            strncpy(email->body, line + 6, MAX_BODY_LEN - 1);
            email->body[MAX_BODY_LEN - 1] = '\0';
        }
    }

    return email;
}

void print_email(Email* email) {
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("Body:\n%s\n", email->body);
}

int main() {
    FILE* fp = fopen("email.txt", "r");
    Email* email = read_email(fp);

    print_email(email);

    free(email);
    fclose(fp);

    return 0;
}