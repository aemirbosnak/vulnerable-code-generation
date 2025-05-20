//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
};

struct mailing_list {
    char name[50];
    struct subscriber *head;
    struct subscriber *tail;
    int count;
};

struct mailing_list *create_mailing_list(char *name) {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    strcpy(list->name, name);
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void add_subscriber(struct mailing_list *list, char *name, char *email) {
    struct subscriber *new_subscriber = malloc(sizeof(struct subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    new_subscriber->next = NULL;

    if (list->head == NULL) {
        list->head = new_subscriber;
        list->tail = new_subscriber;
    } else {
        list->tail->next = new_subscriber;
        list->tail = new_subscriber;
    }

    list->count++;
}

void remove_subscriber(struct mailing_list *list, char *email) {
    struct subscriber *current = list->head;
    struct subscriber *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == list->tail) {
                list->tail = previous;
            }

            free(current);
            list->count--;
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Subscriber not found.\n");
}

void send_email(struct mailing_list *list, char *subject, char *body) {
    struct subscriber *current = list->head;

    while (current != NULL) {
        printf("Sending email to %s (%s)\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        printf("\n");

        current = current->next;
    }
}

void print_mailing_list(struct mailing_list *list) {
    struct subscriber *current = list->head;

    printf("Mailing list: %s\n", list->name);
    printf("Total subscribers: %d\n", list->count);
    printf("\n");

    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    struct mailing_list *list = create_mailing_list("My Awesome Mailing List");

    add_subscriber(list, "John Doe", "johndoe@example.com");
    add_subscriber(list, "Jane Doe", "janedoe@example.com");
    add_subscriber(list, "Bob Smith", "bobsmith@example.com");

    print_mailing_list(list);
    printf("\n");

    send_email(list, "Important Update", "This is a test email to all subscribers.");
    printf("\n");

    remove_subscriber(list, "johndoe@example.com");
    printf("\n");

    print_mailing_list(list);

    return 0;
}