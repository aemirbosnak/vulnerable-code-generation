//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
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
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = NULL;
    list->num_subscribers = 0;
    return list;
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    subscriber *new_subscriber = malloc(sizeof(subscriber));
    new_subscriber->name = strdup(name);
    new_subscriber->email = strdup(email);
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    list->subscribers[list->num_subscribers] = *new_subscriber;
    list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            free(list->subscribers[i].name);
            free(list->subscribers[i].email);
            list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
            list->num_subscribers--;
            break;
        }
    }
}

void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);
    }
}

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
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
    add_subscriber(list, "Peter Parker", "peter.parker@example.com");

    send_email(list, "Welcome to the mailing list!", "This is your first email from us.");

    remove_subscriber(list, "jane.doe@example.com");

    send_email(list, "New email from the mailing list!", "This is a new email from us.");

    free_mailing_list(list);

    return 0;
}