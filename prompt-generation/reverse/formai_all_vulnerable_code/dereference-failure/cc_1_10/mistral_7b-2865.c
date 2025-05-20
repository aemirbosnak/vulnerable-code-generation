//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 1000

typedef struct {
    char name[50];
    char email[100];
    int subscribed;
} Subscriber;

int num_subscribers = 0;
Subscriber *mailing_list = NULL;

void add_subscriber(const char *name, const char *email) {
    Subscriber *new_subscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->subscribed = 1;

    if (num_subscribers == MAX_SUBSCRIBERS) {
        printf("Mailing list is full. Cannot add subscriber.\n");
        free(new_subscriber);
        return;
    }

    mailing_list[num_subscribers++] = *new_subscriber;
}

void remove_subscriber(int index) {
    if (index < 0 || index >= num_subscribers) {
        printf("Invalid index. Cannot remove subscriber.\n");
        return;
    }

    free(mailing_list + index);
    memmove(mailing_list + index, mailing_list + index + 1,
            (num_subscribers - index - 1) * sizeof(Subscriber));
    num_subscribers--;
}

void send_email(const char *subject, const char *message) {
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", mailing_list[i].name,
               mailing_list[i].email);
        // send email using a library or API
    }
}

void print_num_subscribers() {
    printf("Number of subscribers: %d\n", num_subscribers);
}

void print_subscribers() {
    printf("Subscribers:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s) %s\n", mailing_list[i].name,
               mailing_list[i].email,
               mailing_list[i].subscribed ? "Subscribed" : "Unsubscribed");
    }
}

int main() {
    add_subscriber("John Doe", "john.doe@example.com");
    add_subscriber("Jane Doe", "jane.doe@example.com");
    print_subscribers();
    print_num_subscribers();
    send_email("Welcome to the mailing list!", "Thanks for subscribing.");
    remove_subscriber(0);
    print_subscribers();
    print_num_subscribers();

    return 0;
}