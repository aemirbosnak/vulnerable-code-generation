//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100

struct Subscription {
    char email[50];
    struct Subscription *next;
};

struct MailingList {
    char name[50];
    int numSubscribers;
    struct Subscription *subscribers;
};

void addSubscriber(struct MailingList *list, char *email) {
    struct Subscription *newSub = malloc(sizeof(struct Subscription));
    strcpy(newSub->email, email);
    newSub->next = list->subscribers;
    list->subscribers = newSub;
    list->numSubscribers++;
}

void removeSubscriber(struct MailingList *list, char *email) {
    struct Subscription *current = list->subscribers;
    struct Subscription *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Email not found in mailing list.\n");
        return;
    }

    if (previous == NULL) {
        list->subscribers = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    list->numSubscribers--;
}

int main() {
    struct MailingList myList = {"My Mailing List", 0, NULL};
    addSubscriber(&myList, "example1@example.com");
    addSubscriber(&myList, "example2@example.com");
    addSubscriber(&myList, "example3@example.com");

    printf("Mailing list name: %s\n", myList.name);
    printf("Number of subscribers: %d\n", myList.numSubscribers);

    removeSubscriber(&myList, "example2@example.com");

    printf("Number of subscribers after removal: %d\n", myList.numSubscribers);

    return 0;
}