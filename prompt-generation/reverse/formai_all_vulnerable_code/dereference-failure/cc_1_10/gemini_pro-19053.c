//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *email;
    char *name;
} subscriber;

typedef struct {
    subscriber *subscribers;
    int num_subscribers;
} mailing_list;

mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->num_subscribers = 0;
    list->subscribers = NULL;
    return list;
}

void subscribe(mailing_list *list, char *email, char *name) {
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    list->subscribers[list->num_subscribers].email = strdup(email);
    list->subscribers[list->num_subscribers].name = strdup(name);
    list->num_subscribers++;
}

void unsubscribe(mailing_list *list, char *email) {
    for (int i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            free(list->subscribers[i].email);
            free(list->subscribers[i].name);
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

void delete_mailing_list(mailing_list *list) {
    for (int i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i].email);
        free(list->subscribers[i].name);
    }
    free(list->subscribers);
    free(list);
}

int main() {
    mailing_list *list = create_mailing_list();

    subscribe(list, "john@example.com", "John Doe");
    subscribe(list, "jane@example.com", "Jane Doe");

    send_email(list, "Test email", "This is a test email.");

    unsubscribe(list, "john@example.com");

    delete_mailing_list(list);

    return 0;
}