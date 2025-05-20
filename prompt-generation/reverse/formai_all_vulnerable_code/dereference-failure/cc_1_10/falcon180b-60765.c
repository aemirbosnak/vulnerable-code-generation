//Falcon-180B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} email;

void read_contacts(contact contacts[], int *num_contacts) {
    FILE *file;
    char line[MAX_EMAIL_LENGTH];
    int i = 0;

    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open contacts file.\n");
        exit(1);
    }

    while (fgets(line, MAX_EMAIL_LENGTH, file)!= NULL) {
        if (i >= *num_contacts) {
            printf("Error: Too many contacts in file.\n");
            exit(1);
        }
        strcpy(contacts[i].name, line);
        i++;
    }

    fclose(file);
    *num_contacts = i;
}

void read_email(email *email) {
    FILE *file;
    char line[MAX_EMAIL_LENGTH];

    file = fopen("email.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open email file.\n");
        exit(1);
    }

    fgets(line, MAX_EMAIL_LENGTH, file);
    strcpy(email->from, line);

    fgets(line, MAX_EMAIL_LENGTH, file);
    strcpy(email->to, line);

    fgets(line, MAX_SUBJECT_LENGTH, file);
    strcpy(email->subject, line);

    fgets(line, MAX_EMAIL_LENGTH, file);
    strcpy(email->body, line);

    fclose(file);
}

void send_email(contact contacts[], int num_contacts, email email) {
    int i;

    for (i = 0; i < num_contacts; i++) {
        if (strcmp(email.to, contacts[i].email) == 0) {
            printf("Sending email to %s (%s)\n", contacts[i].name, contacts[i].email);
            printf("Subject: %s\n", email.subject);
            printf("Body:\n%s\n", email.body);
            break;
        }
    }
}

int main() {
    contact contacts[100];
    int num_contacts = 0;
    email email;

    read_contacts(contacts, &num_contacts);
    read_email(&email);
    send_email(contacts, num_contacts, email);

    return 0;
}