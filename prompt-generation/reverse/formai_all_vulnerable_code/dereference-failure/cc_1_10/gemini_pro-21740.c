//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *email;
    struct node *next;
};

struct mailing_list {
    struct node *head;
    int count;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->count = 0;
    return list;
}

void add_email_to_list(struct mailing_list *list, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = strdup(email);
    new_node->next = list->head;
    list->head = new_node;
    list->count++;
}

void remove_email_from_list(struct mailing_list *list, char *email) {
    struct node *current = list->head;
    struct node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->email);
            free(current);
            list->count--;
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Email not found in list.\n");
}

void send_email_to_list(struct mailing_list *list, char *subject, char *body) {
    struct node *current = list->head;

    while (current != NULL) {
        printf("Sending email to %s:\n", current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

void destroy_mailing_list(struct mailing_list *list) {
    struct node *current = list->head;

    while (current != NULL) {
        struct node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    struct mailing_list *list = create_mailing_list();

    add_email_to_list(list, "john@example.com");
    add_email_to_list(list, "mary@example.com");
    add_email_to_list(list, "bob@example.com");

    send_email_to_list(list, "Hello, world!", "This is a test email.");

    remove_email_from_list(list, "bob@example.com");

    destroy_mailing_list(list);

    return 0;
}