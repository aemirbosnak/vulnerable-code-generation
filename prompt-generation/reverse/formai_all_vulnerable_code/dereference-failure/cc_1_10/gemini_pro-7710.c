//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
} Subscriber;

typedef struct {
    Subscriber *subscribers;
    int num_subscribers;
    int capacity;
} MailingList;

MailingList *create_mailing_list() {
    MailingList *list = malloc(sizeof(MailingList));
    list->subscribers = malloc(sizeof(Subscriber) * 10);
    list->num_subscribers = 0;
    list->capacity = 10;
    return list;
}

void destroy_mailing_list(MailingList *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

void add_subscriber(MailingList *list, char *name, char *email) {
    if (list->num_subscribers == list->capacity) {
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, sizeof(Subscriber) * list->capacity);
    }
    Subscriber subscriber;
    subscriber.name = strdup(name);
    subscriber.email = strdup(email);
    list->subscribers[list->num_subscribers++] = subscriber;
}

void remove_subscriber(MailingList *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            free(list->subscribers[i].name);
            free(list->subscribers[i].email);
            for (int j = i + 1; j < list->num_subscribers; j++) {
                list->subscribers[j - 1] = list->subscribers[j];
            }
            list->num_subscribers--;
            return;
        }
    }
}

void send_email(MailingList *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

int main() {
    MailingList *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    send_email(list, "Hello", "This is a test email.");
    remove_subscriber(list, "john.doe@example.com");
    destroy_mailing_list(list);
    return 0;
}