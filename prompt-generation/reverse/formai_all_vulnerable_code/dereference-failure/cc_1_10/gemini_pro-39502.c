//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

typedef struct mailing_list {
    node_t *head;
    node_t *tail;
    int size;
} mailing_list_t;

mailing_list_t *create_mailing_list() {
    mailing_list_t *list = malloc(sizeof(mailing_list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_mailing_list(mailing_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

int add_email_to_list(mailing_list_t *list, const char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    return 0;
}

int remove_email_from_list(mailing_list_t *list, const char *email) {
    node_t *current = list->head;
    node_t *previous = NULL;

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

            free(current->email);
            free(current);
            list->size--;
            return 0;
        }

        previous = current;
        current = current->next;
    }

    return -1;
}

int send_email_to_list(mailing_list_t *list, const char *subject, const char *body) {
    node_t *current = list->head;

    while (current != NULL) {
        // Send email to current->email with subject and body
        printf("Sending email to %s\n", current->email);
        current = current->next;
    }

    return 0;
}

int main() {
    mailing_list_t *list = create_mailing_list();

    add_email_to_list(list, "alice@example.com");
    add_email_to_list(list, "bob@example.com");
    add_email_to_list(list, "charlie@example.com");

    send_email_to_list(list, "Hello world", "This is a test email");

    remove_email_from_list(list, "alice@example.com");

    destroy_mailing_list(list);

    return 0;
}