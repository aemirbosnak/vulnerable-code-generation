//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *email;
    struct node *next;
};

struct mailing_list {
    struct node *head;
    struct node *tail;
    int size;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
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

void add_email_to_mailing_list(struct mailing_list *list, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

void remove_email_from_mailing_list(struct mailing_list *list, char *email) {
    struct node *current = list->head;
    struct node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                list->head = current->next;
                if (list->head == NULL)
                    list->tail = NULL;
            } else {
                previous->next = current->next;
                if (current == list->tail)
                    list->tail = previous;
            }
            free(current->email);
            free(current);
            list->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void send_email_to_mailing_list(struct mailing_list *list, char *subject, char *body) {
    struct node *current = list->head;
    while (current != NULL) {
        // Send the email to the current email address
        printf("Sending email to %s\n", current->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
        current = current->next;
    }
}

int main() {
    struct mailing_list *list = create_mailing_list();

    add_email_to_mailing_list(list, "john@example.com");
    add_email_to_mailing_list(list, "mary@example.com");
    add_email_to_mailing_list(list, "bob@example.com");

    send_email_to_mailing_list(list, "Hello", "This is a test email");

    remove_email_from_mailing_list(list, "bob@example.com");

    destroy_mailing_list(list);

    return 0;
}