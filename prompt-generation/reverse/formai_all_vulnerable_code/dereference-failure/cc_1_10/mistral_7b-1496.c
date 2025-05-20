//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define MAX_SUBSCRIBER_NAME_LENGTH 50
#define MAX_SUBSCRIBER_EMAIL_LENGTH 100

typedef struct Subscriber {
    char name[MAX_SUBSCRIBER_NAME_LENGTH];
    char email[MAX_SUBSCRIBER_EMAIL_LENGTH];
    bool is_subscribed;
    struct Subscriber *next;
} Subscriber;

Subscriber *mailing_list = NULL;
int num_subscribers = 0;

void add_subscriber(const char *name, const char *email) {
    Subscriber *new_subscriber = (Subscriber *) malloc(sizeof(Subscriber));

    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->is_subscribed = true;
    new_subscriber->next = mailing_list;

    mailing_list = new_subscriber;
    num_subscribers++;
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
            num_subscribers--;
            break;
        }

        previous = current;
        current = current->next;
    }
}

void print_mailing_list() {
    Subscriber *current = mailing_list;

    printf("\nMailing List:\n");
    printf("--------------------\n");

    while (current != NULL) {
        printf("%s <%s> - %s\n", current->name, current->email, current->is_subscribed ? "Subscribed" : "Unsubscribed");
        current = current->next;
    }

    printf("--------------------\n");
}

int main() {
    add_subscriber("John Doe", "johndoe@example.com");
    add_subscriber("Jane Doe", "janedoe@example.com");

    print_mailing_list();

    remove_subscriber("johndoe@example.com");

    print_mailing_list();

    return 0;
}