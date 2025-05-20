//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LISTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char list_name[MAX_NAME_LENGTH];
    int num_subscribers;
    Subscriber *subscribers;
} MailingList;

void init_list(MailingList *list, char *list_name) {
    strcpy(list->list_name, list_name);
    list->num_subscribers = 0;
    list->subscribers = calloc(1, sizeof(Subscriber) * MAX_LISTS);
}

bool add_subscriber(MailingList *list, char *name, char *email) {
    if (list->num_subscribers >= MAX_LISTS) {
        printf("Error: List '%s' is full.\n", list->list_name);
        return false;
    }

    strcpy(list->subscribers[list->num_subscribers].name, name);
    strcpy(list->subscribers[list->num_subscribers].email, email);
    list->num_subscribers++;

    printf("Successfully added %s (%s) to list '%s'.\n", name, email, list->list_name);
    return true;
}

void print_list(MailingList *list) {
    printf("\nList '%s':\n", list->list_name);

    for (int i = 0; i < list->num_subscribers; i++) {
        printf("%d. %s <%s>\n", i + 1, list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList lists[MAX_LISTS];

    init_list(&lists[0], "Friends");
    init_list(&lists[1], "Family");

    add_subscriber(&lists[0], "Alice", "alice@example.com");
    add_subscriber(&lists[0], "Bob", "bob@example.com");
    add_subscriber(&lists[0], "Charlie", "charlie@example.com");

    add_subscriber(&lists[1], "Mom", "mom@example.com");
    add_subscriber(&lists[1], "Dad", "dad@example.com");

    print_list(&lists[0]);
    print_list(&lists[1]);

    return 0;
}