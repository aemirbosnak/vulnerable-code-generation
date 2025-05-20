//Falcon-180B DATASET v1.0 Category: Email Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_WORD 256
#define MAX_EMAIL 256

typedef struct {
    char name[MAX_WORD];
    char email[MAX_EMAIL];
} contact;

typedef struct {
    char from[MAX_WORD];
    char to[MAX_WORD];
    char subject[MAX_LINE];
    char body[MAX_LINE];
} email;

int main() {
    char line[MAX_LINE];
    contact contacts[100];
    int num_contacts = 0;
    email email;
    char *token;
    int i;

    // Read in contacts from file
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open contacts file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        token = strtok(line, ",");
        strcpy(contacts[num_contacts].name, token);
        token = strtok(NULL, ",");
        strcpy(contacts[num_contacts].email, token);
        num_contacts++;
    }
    fclose(fp);

    // Read in email from file
    fp = fopen("inbox.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open inbox file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        // Parse email headers
        token = strtok(line, ":");
        strcpy(email.from, token);
        token = strtok(NULL, ":");
        strcpy(email.to, token);
        token = strtok(NULL, ":");
        strcpy(email.subject, token);
        token = strtok(NULL, "\n");
        strcpy(email.body, token);

        // Find contact for email
        for (i = 0; i < num_contacts; i++) {
            if (strcmp(email.to, contacts[i].email) == 0) {
                strcpy(email.to, contacts[i].name);
                break;
            }
        }

        // Print email
        printf("From: %s\nTo: %s\nSubject: %s\n\n%s\n\n", email.from, email.to, email.subject, email.body);
    }

    fclose(fp);

    return 0;
}