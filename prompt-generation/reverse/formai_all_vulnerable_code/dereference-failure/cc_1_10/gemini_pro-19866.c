//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *email;
    char *name;
    int subscribed;
} subscriber;

subscriber *subscribers = NULL;
int num_subscribers = 0;

void add_subscriber(char *email, char *name) {
    subscribers = realloc(subscribers, (num_subscribers + 1) * sizeof(subscriber));
    subscribers[num_subscribers].email = strdup(email);
    subscribers[num_subscribers].name = strdup(name);
    subscribers[num_subscribers].subscribed = 1;
    num_subscribers++;
}

void remove_subscriber(char *email) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            free(subscribers[i].email);
            free(subscribers[i].name);
            subscribers[i] = subscribers[num_subscribers - 1];
            num_subscribers--;
            return;
        }
    }
}

void send_email(char *subject, char *body) {
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (subscribers[i].subscribed) {
            printf("Sending email to %s <%s>:\n", subscribers[i].name, subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n", body);
        }
    }
}

int main() {
    add_subscriber("john@doe.com", "John Doe");
    add_subscriber("jane@doe.com", "Jane Doe");

    send_email("Hello from the mailing list!", "This is a test email from the mailing list.");

    remove_subscriber("john@doe.com");

    send_email("Goodbye from the mailing list!", "This is a goodbye email from the mailing list.");

    return 0;
}