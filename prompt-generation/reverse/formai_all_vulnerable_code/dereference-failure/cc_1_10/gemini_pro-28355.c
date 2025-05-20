//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
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

void add_subscriber(mailing_list *list, char *name, char *email) {
    subscriber *new_subscriber = malloc(sizeof(subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);

    list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
    list->subscribers[list->num_subscribers] = *new_subscriber;
    list->num_subscribers++;
}

void send_email(mailing_list *list, char *subject, char *body) {
    for (int i = 0; i < list->num_subscribers; i++) {
        printf("Sending email to %s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
    }
}

int main() {
    mailing_list *list = create_mailing_list();

    add_subscriber(list, "Sherlock Holmes", "sherlock@bakerstreet.net");
    add_subscriber(list, "Dr. Watson", "watson@bakerstreet.net");
    add_subscriber(list, "Inspector Lestrade", "lestrade@scotlandyard.net");

    send_email(list, "The Adventure of the Red-Headed League", "I have a most extraordinary case to relate...");

    return 0;
}