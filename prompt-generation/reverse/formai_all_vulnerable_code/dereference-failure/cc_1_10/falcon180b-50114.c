//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* name, char* email) {
    strcpy(emails[num_emails].name, name);
    strcpy(emails[num_emails].email, email);
    num_emails++;
}

void remove_email(int index) {
    num_emails--;
    for (int i = index; i < num_emails; i++) {
        strcpy(emails[i].name, emails[i+1].name);
        strcpy(emails[i].email, emails[i+1].email);
    }
}

void print_emails() {
    for (int i = 0; i < num_emails; i++) {
        printf("%s (%s)\n", emails[i].name, emails[i].email);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("1. Add email\n2. Remove email\n3. Print emails\n4. Exit\n");
        scanf("%d", &num_emails);

        switch (num_emails) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_email(name, email);
                break;
            case 2:
                printf("Enter index of email to remove: ");
                scanf("%d", &num_emails);
                remove_email(num_emails);
                break;
            case 3:
                print_emails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}