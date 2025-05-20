//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBSCRIBERS 1000
#define SUBSCRIBER_NAME_LENGTH 50

typedef struct Subscriber {
    char name[SUBSCRIBER_NAME_LENGTH];
    bool isSubscribed;
    struct Subscriber *next;
} Subscriber;

Subscriber *subscribersList = NULL;

void addSubscriber(char *name) {
    Subscriber *newSubscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    newSubscriber->isSubscribed = true;
    newSubscriber->next = subscribersList;
    subscribersList = newSubscriber;
}

bool removeSubscriber(char *name) {
    Subscriber *current = subscribersList;
    Subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                subscribersList = current->next;
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

void printSubscribers() {
    Subscriber *current = subscribersList;

    printf("Subscribers:\n");
    while (current != NULL) {
        printf("%s%s\n", current->name, current->isSubscribed ? "" : " (unsubscribed)");
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [add|remove] [name]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc > 3) {
        addSubscriber(argv[3]);
    } else if (strcmp(argv[1], "remove") == 0 && argc > 3) {
        removeSubscriber(argv[3]);
    } else {
        printSubscribers();
    }

    return 0;
}