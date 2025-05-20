//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subscriber {
    char *name;
    char *email;
    struct subscriber *next;
} subscriber_t;

typedef struct mailing_list {
    char *name;
    subscriber_t *head;
} mailing_list_t;

mailing_list_t *create_mailing_list(char *name) {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    list->name = strdup(name);
    list->head = NULL;
    return list;
}

void add_subscriber(mailing_list_t *list, char *name, char *email) {
    subscriber_t *new_subscriber = malloc(sizeof(subscriber_t));
    new_subscriber->name = strdup(name);
    new_subscriber->email = strdup(email);
    new_subscriber->next = NULL;

    if (list->head == NULL) {
        list->head = new_subscriber;
    } else {
        subscriber_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_subscriber;
    }
}

void send_email(mailing_list_t *list, char *subject, char *body) {
    subscriber_t *current = list->head;
    while (current != NULL) {
        printf("Sending email to %s at %s\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

int main() {
    mailing_list_t *list = create_mailing_list("My Mailing List");
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Smith", "jane.smith@example.com");
    send_email(list, "Hello from your mailing list", "This is a test email.");
    return 0;
}