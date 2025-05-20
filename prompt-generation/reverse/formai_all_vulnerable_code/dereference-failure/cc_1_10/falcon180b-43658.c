//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *name;
    char *email;
    time_t timestamp;
} Contact;

typedef struct {
    char *subject;
    char *body;
    time_t timestamp;
    Contact sender;
} Email;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [inbox|sent|drafts]\n", argv[0]);
        return 1;
    }

    char mailbox[50];
    strcpy(mailbox, argv[1]);

    FILE *fp;
    if (strcmp(mailbox, "inbox") == 0) {
        fp = fopen("inbox.txt", "r");
    } else if (strcmp(mailbox, "sent") == 0) {
        fp = fopen("sent.txt", "r");
    } else if (strcmp(mailbox, "drafts") == 0) {
        fp = fopen("drafts.txt", "r");
    } else {
        printf("Invalid mailbox\n");
        return 1;
    }

    if (fp == NULL) {
        printf("Mailbox is empty\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Email email;
        sscanf(line, "%s %s %s %s", email.subject, email.body, ctime(&email.timestamp), email.sender.name);
        printf("%s\n", line);
    }

    fclose(fp);
    return 0;
}