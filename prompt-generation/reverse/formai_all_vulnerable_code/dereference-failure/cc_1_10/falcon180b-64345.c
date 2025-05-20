//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBJECT_LENGTH 80
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    Subscriber *subscribers;
    int num_subscribers;
} MailingList;

void addSubscriber(MailingList *list, char *name, char *email) {
    Subscriber *newSubscriber = (Subscriber *)malloc(sizeof(Subscriber));
    strcpy(newSubscriber->name, name);
    strcpy(newSubscriber->email, email);
    list->subscribers = (Subscriber *)realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers + 1));
    list->subscribers[list->num_subscribers] = *newSubscriber;
    list->num_subscribers++;
}

void removeSubscriber(MailingList *list, char *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (!strcmp(list->subscribers[i].email, email)) {
            list->subscribers = (Subscriber *)realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers - 1));
            list->num_subscribers--;
            return;
        }
    }
}

void sendEmail(MailingList *list, char *subject, char *body) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList list;
    list.num_subscribers = 0;

    addSubscriber(&list, "John Doe", "johndoe@example.com");
    addSubscriber(&list, "Jane Doe", "janedoe@example.com");

    sendEmail(&list, "Test Email", "Hello, world!");

    removeSubscriber(&list, "johndoe@example.com");

    sendEmail(&list, "Another Test Email", "How are you doing?");

    return 0;
}