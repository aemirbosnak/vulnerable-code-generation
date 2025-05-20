//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
} subscriber;

typedef struct {
    subscriber *subscribers;
    int num_subscribers;
    int capacity;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = NULL;
    list->num_subscribers = 0;
    list->capacity = 0;
    return list;
}

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->num_subscribers >= list->capacity) {
        list->capacity *= 2;
        list->subscribers = realloc(list->subscribers, list->capacity * sizeof(subscriber));
    }
    list->subscribers[list->num_subscribers].name = strdup(name);
    list->subscribers[list->num_subscribers].email = strdup(email);
    list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, int index) {
    if (index < 0 || index >= list->num_subscribers) {
        return;
    }
    free(list->subscribers[index].name);
    free(list->subscribers[index].email);
    for (int i = index + 1; i < list->num_subscribers; i++) {
        list->subscribers[i - 1] = list->subscribers[i];
    }
    list->num_subscribers--;
}

void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        // Send an email to list->subscribers[i].email with subject subject and body body.
    }
}

int main() {
    mailing_list *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john@example.com");
    add_subscriber(list, "Jane Doe", "jane@example.com");
    send_email(list, "Hello world", "This is a test email.");
    remove_subscriber(list, 1);
    free_mailing_list(list);
    return 0;
}