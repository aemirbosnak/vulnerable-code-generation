//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LIST_SIZE 1000000
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
    time_t timestamp;
} subscriber;

int num_subscribers = 0;
subscriber *subscribers = NULL;

void add_subscriber(char *email, char *name) {
    if (num_subscribers >= MAX_LIST_SIZE) {
        printf("Error: List is full.\n");
        return;
    }

    subscriber *new_subscriber = (subscriber*) malloc(sizeof(subscriber));
    strcpy(new_subscriber->email, email);
    strcpy(new_subscriber->name, name);
    new_subscriber->timestamp = time(NULL);

    subscribers = (subscriber*) realloc(subscribers, sizeof(subscriber) * ++num_subscribers);
    subscribers[num_subscribers - 1] = *new_subscriber;
    free(new_subscriber);

    printf("Subscriber added successfully.\n");
}

void remove_subscriber(char *email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            free(subscribers[i].email);
            free(subscribers[i].name);
            subscribers[i] = subscribers[num_subscribers - 1];
            num_subscribers--;
            break;
        }
    }
}

void print_list() {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("%s (%s) - %s\n", subscribers[i].name, subscribers[i].email, ctime(&subscribers[i].timestamp));
    }
}

void send_email(char *subject, char *message, char *recipient) {
    printf("Sending email to %s...\n", recipient);
}

int main() {
    add_subscriber("john@example.com", "John Doe");
    add_subscriber("jane@example.com", "Jane Doe");
    add_subscriber("bob@example.com", "Bob Smith");

    print_list();

    remove_subscriber("jane@example.com");
    print_list();

    send_email("Test Email", "This is a test email.", "john@example.com");

    return 0;
}