//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
} subscriber;

typedef struct {
    subscriber *subscribers;
    int count;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = malloc(0);
    list->count = 0;
    return list;
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    list->subscribers = realloc(list->subscribers, (list->count + 1) * sizeof(subscriber));
    list->subscribers[list->count].name = strdup(name);
    list->subscribers[list->count].email = strdup(email);
    list->count++;
}

void remove_subscriber(mailing_list *list, int index) {
    if (index < 0 || index >= list->count) {
        return;
    }
    free(list->subscribers[index].name);
    free(list->subscribers[index].email);
    for (int i = index + 1; i < list->count; i++) {
        list->subscribers[i - 1] = list->subscribers[i];
    }
    list->count--;
    list->subscribers = realloc(list->subscribers, list->count * sizeof(subscriber));
}

void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->count; i++) {
        // Send an email to list->subscribers[i].email with subject and body.
        printf("Sending email to %s (%s) with subject '%s' and body '%s'.\n",
            list->subscribers[i].name, list->subscribers[i].email, subject, body);
    }
}

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

int main() {
    mailing_list *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    send_email(list, "Hello", "This is an email from your mailing list.");
    remove_subscriber(list, 1);
    send_email(list, "Goodbye", "This is the last email from your mailing list.");
    free_mailing_list(list);
    return 0;
}