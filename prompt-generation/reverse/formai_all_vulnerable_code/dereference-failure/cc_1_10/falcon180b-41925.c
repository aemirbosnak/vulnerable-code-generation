//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Message;

Subscriber *subscribers = NULL;
int num_subscribers = 0;

void add_subscriber(Subscriber *subscriber) {
    subscribers = realloc(subscribers, sizeof(Subscriber) * ++num_subscribers);
    memcpy(&subscribers[num_subscribers - 1], subscriber, sizeof(Subscriber));
}

int find_subscriber_index(const char *email) {
    for (int i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

void send_message(const char *subject, const char *message) {
    for (int i = 0; i < num_subscribers; i++) {
        printf("Sending message to %s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    Subscriber subscriber = {"John Doe", "john.doe@example.com"};
    add_subscriber(&subscriber);

    Message message = {"Hello, world!", "This is a test message."};
    send_message(message.subject, message.message);

    return 0;
}