//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    int size;
    int capacity;
    Subscriber *subscribers;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->size = 0;
    list->capacity = 10;
    list->subscribers = malloc(list->capacity * sizeof(Subscriber));
}

int addSubscriber(MailingList *list, char *name, char *email) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, list->capacity * sizeof(Subscriber));
    }

    Subscriber *subscriber = &list->subscribers[list->size];
    strncpy(subscriber->name, name, MAX_NAME_LENGTH);
    strncpy(subscriber->email, email, MAX_EMAIL_LENGTH);

    list->size++;

    return 0;
}

int removeSubscriber(MailingList *list, char *email) {
    for (int i = 0; i < list->size; i++) {
        Subscriber *subscriber = &list->subscribers[i];

        if (strcmp(subscriber->email, email) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                Subscriber *temp = &list->subscribers[j];
                list->subscribers[j] = list->subscribers[j + 1];
            }

            list->size--;

            return 0;
        }
    }

    return -1;
}

int sendEmail(MailingList *list, char *subject, char *body) {
    for (int i = 0; i < list->size; i++) {
        Subscriber *subscriber = &list->subscribers[i];

        printf("Sending email to %s (%s)\n", subscriber->name, subscriber->email);
    }

    return 0;
}

int main() {
    MailingList list;
    initializeMailingList(&list);

    addSubscriber(&list, "John Doe", "johndoe@example.com");
    addSubscriber(&list, "Jane Doe", "janedoe@example.com");

    sendEmail(&list, "Test Email", "This is a test email!");

    removeSubscriber(&list, "johndoe@example.com");

    sendEmail(&list, "Test Email 2", "This is another test email!");

    return 0;
}