//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[255];
    char email[255];
    int subscribed;
} subscriber;

typedef struct {
    int num_subscribers;
    subscriber *subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    list->subscribers = NULL;
    return list;
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->subscribers[list->num_subscribers].subscribed = 1;
    list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, char *email) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            break;
        }
    }
    if (i == list->num_subscribers) {
        return;
    }
    for (; i < list->num_subscribers - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1];
    }
    list->num_subscribers--;
    list->subscribers = realloc(list->subscribers, (list->num_subscribers) * sizeof(subscriber));
}

void send_email(mailing_list *list, char *subject, char *body) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (list->subscribers[i].subscribed) {
            printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n\n", body);
        }
    }
}

int main() {
    mailing_list *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    send_email(list, "Hello, world!", "This is a test email.");
    remove_subscriber(list, "jane.doe@example.com");
    send_email(list, "Goodbye, world!", "This is a goodbye email.");
    return 0;
}