//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50

typedef struct Subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    bool is_subscribed;
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;

void add_subscriber(char *name) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    new_subscriber->is_subscribed = true;
    new_subscriber->next = mailing_list;
    mailing_list = new_subscriber;
}

bool remove_subscriber(char *name) {
    Subscriber *current = mailing_list;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                mailing_list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

void print_mailing_list() {
    Subscriber *current = mailing_list;

    printf("Mailing List:\n");
    while (current != NULL) {
        printf("%s %s\n", current->name, current->is_subscribed ? "Subscribed" : "Unsubscribed");
        current = current->next;
    }
}

int main() {
    add_subscriber("John Doe");
    add_subscriber("Jane Smith");
    add_subscriber("Bob Johnson");

    print_mailing_list();

    remove_subscriber("Bob Johnson");

    print_mailing_list();

    return 0;
}