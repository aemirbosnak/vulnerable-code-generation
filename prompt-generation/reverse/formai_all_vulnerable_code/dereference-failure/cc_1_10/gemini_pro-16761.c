//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
    char name[50];
    char email[50];
    struct subscriber *next;
};

struct mailing_list {
    struct subscriber *head;
    struct subscriber *tail;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->tail = NULL;
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
}

void send_email(struct mailing_list *list, char *subject, char *body) {
    struct subscriber *current = list->head;
    while (current != NULL) {
        printf("Sending email to %s (%s)\n", current->name, current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

void print_mailing_list(struct mailing_list *list) {
    struct subscriber *current = list->head;
    while (current != NULL) {
        printf("%s (%s)\n", current->name, current->email);
        current = current->next;
    }
}

int main() {
    struct mailing_list *list = create_mailing_list();
    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Mary Smith", "mary.smith@example.com");
    print_mailing_list(list);
    send_email(list, "Hello from the mailing list!", "This is a test email from the mailing list.");
    return 0;
}