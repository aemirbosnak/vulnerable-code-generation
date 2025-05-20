//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber *subscribers;
    int num_subscribers;
} MailingList;

void init_mailing_list(MailingList *list) {
    list->subscribers = NULL;
    list->num_subscribers = 0;
}

void add_subscriber(MailingList *list, const char *name, const char *email) {
    Subscriber *new_subscriber = malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    list->subscribers = realloc(list->subscribers, sizeof(Subscriber) * (list->num_subscribers + 1));
    list->subscribers[list->num_subscribers] = *new_subscriber;
    list->num_subscribers++;
}

void remove_subscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->num_subscribers - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->num_subscribers--;
            break;
        }
    }
}

void print_subscribers(MailingList *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList mailing_list;
    init_mailing_list(&mailing_list);

    add_subscriber(&mailing_list, "Alice", "alice@example.com");
    add_subscriber(&mailing_list, "Bob", "bob@example.com");
    add_subscriber(&mailing_list, "Charlie", "charlie@example.com");

    print_subscribers(&mailing_list);

    remove_subscriber(&mailing_list, "alice@example.com");

    print_subscribers(&mailing_list);

    return 0;
}