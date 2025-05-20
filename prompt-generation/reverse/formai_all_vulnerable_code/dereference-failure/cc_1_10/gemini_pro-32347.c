//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_EMAIL_LEN 64
#define MAX_MAILINGS 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} subscriber;

typedef struct {
    char subject[MAX_NAME_LEN];
    char body[1024];
} mailing;

typedef struct {
    subscriber *subscribers;
    int num_subscribers;
    mailing *mailings;
    int num_mailings;
} mailing_list;

void init_mailing_list(mailing_list *list) {
    list->subscribers = NULL;
    list->num_subscribers = 0;
    list->mailings = NULL;
    list->num_mailings = 0;
}

void add_subscriber(mailing_list *list, const char *name, const char *email) {
    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;
}

void add_mailing(mailing_list *list, const char *subject, const char *body) {
    list->mailings = realloc(list->mailings, (list->num_mailings + 1) * sizeof(mailing));
    strcpy(list->mailings[list->num_mailings].subject, subject);
    strcpy(list->mailings[list->num_mailings].body, body);
    list->num_mailings++;
}

void send_mailing(mailing_list *list, mailing *mailing) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("To: %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", mailing->subject);
        printf("%s\n", mailing->body);
        printf("\n");
    }
}

void free_mailing_list(mailing_list *list) {
    free(list->subscribers);
    free(list->mailings);
}

int main() {
    mailing_list list;
    init_mailing_list(&list);

    add_subscriber(&list, "Alice", "alice@example.com");
    add_subscriber(&list, "Bob", "bob@example.com");
    add_subscriber(&list, "Carol", "carol@example.com");

    add_mailing(&list, "Welcome to the mailing list", "This is the first mailing in the series.");
    add_mailing(&list, "Second mailing", "This is the second mailing in the series.");
    add_mailing(&list, "Third mailing", "This is the third mailing in the series.");

    send_mailing(&list, &list.mailings[0]);
    send_mailing(&list, &list.mailings[1]);
    send_mailing(&list, &list.mailings[2]);

    free_mailing_list(&list);

    return 0;
}