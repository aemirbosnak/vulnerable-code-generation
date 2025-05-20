//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Oooh, a fancy new mailing list manager!

// Let's have a struct for each subscriber!
typedef struct subscriber {
    char *email;
    char *name;
    bool subscribed;
} subscriber;

// And a list to hold all our subscribers!
subscriber *subscribers = NULL;

// How many subscribers do we have?
int subscriber_count = 0;

// Woo! Let's add a new subscriber!
void add_subscriber(char *email, char *name) {
    // First, let's see if the subscriber already exists.
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            // Found 'em!
            printf("Yay! Welcome back, %s!\n", subscribers[i].name);
            return;
        }
    }

    // If we're here, it's a new subscriber!
    printf("Hooray! Welcome aboard, %s!\n", name);

    // Let's make some space for the new one.
    subscribers = realloc(subscribers, (subscriber_count + 1) * sizeof(subscriber));

    // And fill in their info.
    subscribers[subscriber_count].email = strdup(email);
    subscribers[subscriber_count].name = strdup(name);
    subscribers[subscriber_count].subscribed = true;

    // And don't forget to update the count!
    subscriber_count++;
}

// Uh oh, someone wants to unsubscribe...
void unsubscribe_subscriber(char *email) {
    // Let's find them first.
    for (int i = 0; i < subscriber_count; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            // Found 'em!
            printf("Sad to see you go, %s...\n", subscribers[i].name);

            // Mark them as unsubscribed.
            subscribers[i].subscribed = false;

            // And we're done here.
            return;
        }
    }

    // If we're here, they're not on the list.
    printf("Oops! Couldn't find %s on the list.\n", email);
}

// Let's send out an email to everyone!
void send_email(char *subject, char *body) {
    printf("Sending out an email to %d subscribers:\n", subscriber_count);

    // Loop through all the subscribers.
    for (int i = 0; i < subscriber_count; i++) {
        if (subscribers[i].subscribed) {
            // Only send to subscribers who want our emails.
            printf(" - To: %s\n - Subject: %s\n - Body: %s\n", subscribers[i].email, subject, body);
        }
    }

    printf("Email sent! Check your inboxes, folks!\n");
}

// Oh, a new email arrived!
void process_incoming_email(char *from, char *subject, char *body) {
    printf("Got an email from %s...\n", from);

    // Is it a subscription request?
    if (strcmp(subject, "Subscribe") == 0) {
        // Let's add the sender to the list.
        add_subscriber(from, body);
    }
    // Or an unsubscribe request?
    else if (strcmp(subject, "Unsubscribe") == 0) {
        // Let's remove them from the list.
        unsubscribe_subscriber(from);
    }
    // Or just a regular email?
    else {
        printf("Hmm, not sure what to do with this email. But hey, it's always nice to hear from you, %s!\n", from);
    }
}

int main() {
    // Let's roll!
    printf("Welcome to the most exciting mailing list manager ever!\n");

    // Let's add some sample subscribers.
    add_subscriber("alice@example.com", "Alice");
    add_subscriber("bob@example.com", "Bob");
    add_subscriber("charlie@example.com", "Charlie");

    // Now let's send out an email to everyone.
    send_email("Hello from your mailing list manager!", "Just wanted to say hi and welcome you to the club!");

    // And let's say someone wants to unsubscribe...
    unsubscribe_subscriber("bob@example.com");

    // And finally, let's process a new email.
    process_incoming_email("eve@example.com", "Subscribe", "Please add me to your list!");

    // And that's it for now! Thanks for using the most exciting mailing list manager ever!
    return 0;
}