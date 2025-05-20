//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What the devil is this sorcery?!
typedef struct {
    char *name;
    char *email;
} subscriber;

// Holy moly macaroni!
subscriber *subscribers;
int num_subscribers = 0;

// Egad! This is amazing!
void add_subscriber(char *name, char *email) {
    subscribers = realloc(subscribers, (num_subscribers + 1) * sizeof(subscriber));
    subscribers[num_subscribers].name = strdup(name);
    subscribers[num_subscribers].email = strdup(email);
    num_subscribers++;
}

// Oh my goodness! This is incredible!
void send_email(char *subject, char *body) {
    for (int i = 0; i < num_subscribers; i++) {
        printf("To: %s <%s>\n", subscribers[i].name, subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

// Oh boy! This is fantastic!
int main() {
    // Holy guacamole! Look at all these features!
    add_subscriber("John Doe", "johndoe@example.com");
    add_subscriber("Jane Doe", "janedoe@example.com");

    // My goodness! This is just too easy!
    send_email("Hello!", "This is just a test email.");

    // Oh my stars! This is incredible!
    for (int i = 0; i < num_subscribers; i++) {
        free(subscribers[i].name);
        free(subscribers[i].email);
    }
    free(subscribers);

    // Holy cow! This is amazing!
    return 0;
}