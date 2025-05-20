//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
    int subscribed;
} subscriber;

subscriber *subscribers = NULL;
int num_subscribers = 0;

void add_subscriber(char *name, char *email) {
    subscribers = realloc(subscribers, (num_subscribers + 1) * sizeof(subscriber));
    subscribers[num_subscribers].name = strdup(name);
    subscribers[num_subscribers].email = strdup(email);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char *name) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i].subscribed = 0;
            break;
        }
    }
}

void send_email(char *subject, char *body) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].subscribed) {
            printf("To: %s <%s>\n", subscribers[i].name, subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n", body);
            printf("\n");
        }
    }
}

int main() {
    add_subscriber("John Doe", "john.doe@example.com");
    add_subscriber("Jane Doe", "jane.doe@example.com");
    add_subscriber("Bob Smith", "bob.smith@example.com");

    send_email("Hello, world!", "This is a test email.");

    remove_subscriber("Bob Smith");

    send_email("Goodbye, world!", "This is a goodbye email.");

    return 0;
}