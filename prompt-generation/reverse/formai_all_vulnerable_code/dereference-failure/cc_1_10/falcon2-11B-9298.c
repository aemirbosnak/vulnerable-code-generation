//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SUBSCRIBERS 100
#define MAX_LISTNAME 20
#define MAX_EMAIL 50

typedef struct subscriber {
    char listname[MAX_LISTNAME];
    char email[MAX_EMAIL];
    bool isSubscribed;
} Subscriber;

Subscriber subscribers[MAX_SUBSCRIBERS];
int numSubscribers = 0;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <listname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *listname = argv[1];
    if (strlen(listname) > MAX_LISTNAME) {
        fprintf(stderr, "List name is too long\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numSubscribers; i++) {
        if (strcmp(subscribers[i].listname, listname) == 0) {
            fprintf(stderr, "List name already exists\n");
            exit(EXIT_FAILURE);
        }
    }

    Subscriber newSubscriber;
    strcpy(newSubscriber.listname, listname);
    strcpy(newSubscriber.email, "");
    newSubscriber.isSubscribed = false;

    strcpy(subscribers[numSubscribers].listname, listname);
    strcpy(subscribers[numSubscribers].email, "");
    subscribers[numSubscribers].isSubscribed = false;

    numSubscribers++;

    printf("Subscribed to %s mailing list\n", listname);

    return 0;
}