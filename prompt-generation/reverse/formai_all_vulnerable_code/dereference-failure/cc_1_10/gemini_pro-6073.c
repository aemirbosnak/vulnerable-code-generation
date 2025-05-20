//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
} subscriber;

typedef struct {
    subscriber *subscribers;
    int size;
    int capacity;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = malloc(sizeof(subscriber) * 10);
    list->size = 0;
    list->capacity = 10;
    return list;
}

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    if (list->size == list->capacity) {
        list->subscribers = realloc(list->subscribers, sizeof(subscriber) * (list->capacity * 2));
        list->capacity *= 2;
    }
    list->subscribers[list->size].name = strdup(name);
    list->subscribers[list->size].email = strdup(email);
    list->size++;
}

void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->size; i++) {
        // Send an email to list->subscribers[i] with the given subject and body.
    }
}

int main() {
    mailing_list *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Smith", "jane.smith@example.com");
    send_email(list, "Hello, world!", "This is a test email.\n");
    free_mailing_list(list);
    return 0;
}