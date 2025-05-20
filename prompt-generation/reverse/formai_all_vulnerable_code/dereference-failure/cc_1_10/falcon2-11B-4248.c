//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name;
    char* email;
    char* subject;
    char* body;
} mail;

void add_mail(mail* mails, int size, char* email, char* subject, char* body) {
    mails[size].name = strdup(email);
    mails[size].email = strdup(email);
    mails[size].subject = strdup(subject);
    mails[size].body = strdup(body);
    size++;
}

void remove_mail(mail* mails, int size, char* email) {
    for (int i = 0; i < size; i++) {
        if (strcmp(mails[i].name, email) == 0) {
            free(mails[i].name);
            free(mails[i].email);
            free(mails[i].subject);
            free(mails[i].body);
            memmove(&mails[i], &mails[i + 1], (size - i - 1) * sizeof(mail));
            size--;
            break;
        }
    }
}

void display_mails(mail* mails, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s %s %s %s\n", mails[i].name, mails[i].email, mails[i].subject, mails[i].body);
    }
}

int main() {
    mail mails[100];
    int size = 0;

    printf("Enter email to add: ");
    char* email = malloc(100 * sizeof(char));
    scanf("%s", email);
    add_mail(mails, size, email, "Subject", "Body");

    printf("Enter email to remove: ");
    char* email2 = malloc(100 * sizeof(char));
    scanf("%s", email2);
    remove_mail(mails, size, email2);

    display_mails(mails, size);

    return 0;
}