//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000
#define MAX_EMAILS 1000

struct Email {
    char* email;
    struct Email* next;
};

struct Email* emails[MAX_EMAILS];
int num_emails = 0;

void add_email(char* email) {
    struct Email* new_email = (struct Email*) malloc(sizeof(struct Email));
    new_email->email = strdup(email);
    new_email->next = NULL;

    if (num_emails == MAX_EMAILS) {
        printf("Sorry, maximum number of emails reached!\n");
        return;
    }

    struct Email* last = emails[num_emails-1];
    last->next = new_email;
    num_emails++;
}

void remove_email(char* email) {
    struct Email* current = emails[0];
    struct Email* previous = NULL;

    while (current!= NULL) {
        if (strcmp(current->email, email) == 0) {
            break;
        }
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Sorry, email not found!\n");
        return;
    }

    if (previous == NULL) {
        emails[num_emails-1] = current->next;
    } else {
        previous->next = current->next;
    }

    free(current->email);
    free(current);
    num_emails--;
}

void display_emails() {
    struct Email* current = emails[0];

    while (current!= NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    char* spam_email = "example@example.com";
    char* legit_email = "legit@example.com";

    add_email(spam_email);
    add_email(legit_email);

    remove_email(legit_email);

    display_emails();

    return 0;
}