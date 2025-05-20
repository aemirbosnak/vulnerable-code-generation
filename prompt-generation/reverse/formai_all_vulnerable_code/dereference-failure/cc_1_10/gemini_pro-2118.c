//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
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

void free_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].name);
        free(list->subscribers[i].email);
    }
    free(list->subscribers);
    free(list);
}

void add_subscriber(mailing_list *list, char *name, char *email) {
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

void remove_subscriber(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i + 1; j < list->num_subscribers; j++) {
                list->subscribers[j - 1] = list->subscribers[j];
            }
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

int main() {
    mailing_list *list = create_mailing_list();

    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");
    add_subscriber(list, "Alice Johnson", "alice.johnson@example.com");
    add_subscriber(list, "Tom Brown", "tom.brown@example.com");

    send_email(list, "Hello, world!", "This is just a test.");

    remove_subscriber(list, "john.doe@example.com");

    send_email(list, "Update", "The mailing list has been updated.");

    free_mailing_list(list);

    return 0;
}