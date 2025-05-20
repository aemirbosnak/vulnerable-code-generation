//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIST_SIZE 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct Subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;

void add_subscriber(const char *name, const char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
}

void remove_subscriber(const char *email) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void print_mailing_list() {
    Subscriber *current = mailing_list;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    add_subscriber("John Doe", "john.doe@example.com");
    add_subscriber("Jane Smith", "jane.smith@example.com");
    add_subscriber("Bob Johnson", "bob.johnson@example.com");

    print_mailing_list();

    remove_subscriber("john.doe@example.com");

    print_mailing_list();

    return 0;
}