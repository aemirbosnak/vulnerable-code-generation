//Falcon-180B DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100
#define DELIMITER ";"

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int numEmails;

void readEmails(char *filename) {
    FILE *fp;
    char line[MAX_SUBJECT_LENGTH + MAX_BODY_LENGTH + 2]; // 2 for delimiter and null terminator
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int j = 0;
        char *subject = strtok(line, DELIMITER);
        char *body = strtok(NULL, DELIMITER);

        if (subject == NULL || body == NULL) {
            printf("Invalid email format.\n");
            exit(1);
        }

        strcpy(emails[i].subject, subject);
        strcpy(emails[i].body, body);
        i++;
        numEmails++;
    }

    fclose(fp);
}

void sendEmail(int index) {
    printf("Subject: %s\n", emails[index].subject);
    printf("Body:\n%s", emails[index].body);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    readEmails(argv[1]);

    if (numEmails == 0) {
        printf("No emails found.\n");
    } else {
        printf("Number of emails: %d\n", numEmails);
        for (int i = 0; i < numEmails; i++) {
            sendEmail(i);
        }
    }

    return 0;
}