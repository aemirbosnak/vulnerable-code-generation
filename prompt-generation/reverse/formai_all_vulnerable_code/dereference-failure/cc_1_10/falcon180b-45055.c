//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME 100
#define MAX_SUBJECT 200

typedef struct email {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
    char subject[MAX_SUBJECT];
} email_t;

email_t emails[MAX_EMAILS];
int email_count = 0;

void add_email(char *name, char *email, char *subject) {
    if (email_count >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[email_count].name, name);
    strcpy(emails[email_count].email, email);
    strcpy(emails[email_count].subject, subject);

    email_count++;
}

void print_emails() {
    int i;

    for (i = 0; i < email_count; i++) {
        printf("Name: %s\nEmail: %s\nSubject: %s\n\n", emails[i].name, emails[i].email, emails[i].subject);
    }
}

void remove_email(int index) {
    if (index >= email_count) {
        printf("Error: Email not found.\n");
        return;
    }

    email_count--;
    memmove(&emails[index], &emails[index + 1], sizeof(email_t) * (email_count - index));
}

int main() {
    int choice, index;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Email\n2. Print Emails\n3. Remove Email\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name: ");
            scanf("%s", &emails[email_count].name);
            printf("Enter email: ");
            scanf("%s", &emails[email_count].email);
            printf("Enter subject: ");
            scanf("%s", &emails[email_count].subject);
            email_count++;
            break;

        case 2:
            print_emails();
            break;

        case 3:
            printf("Enter email index to remove: ");
            scanf("%d", &index);
            remove_email(index);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}