//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_NAME 50

struct Email {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
};

void addEmail(struct Email *emails, int count, char *name, char *email) {
    if (count >= MAX_EMAILS) {
        printf("Error: Max emails reached\n");
        return;
    }

    strcpy(emails[count].name, name);
    strcpy(emails[count].email, email);
    count++;
}

void printEmails(struct Email *emails, int count) {
    printf("Name\tEmail\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", emails[i].name, emails[i].email);
    }
}

void sortEmails(struct Email *emails, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(emails[i].name, emails[j].name) > 0) {
                struct Email temp = emails[i];
                emails[i] = emails[j];
                emails[j] = temp;
            }
        }
    }
}

int main() {
    struct Email emails[MAX_EMAILS];
    int count = 0;

    char name[MAX_NAME];
    char email[MAX_EMAILS];

    printf("Enter name and email (Press Enter to stop):\n");

    while (fgets(name, MAX_NAME, stdin)!= NULL) {
        if (name[0] == '\n') {
            break;
        }

        char *token = strtok(name, " ");
        strcpy(email, token);

        addEmail(emails, count, name, email);
        count++;
    }

    printf("Sorted emails:\n");
    sortEmails(emails, count);
    printEmails(emails, count);

    return 0;
}