//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: calm
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

struct mailing_list *create_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroy_list(struct mailing_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

int add_email(struct mailing_list *list, char *email) {
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
    return 1;
}

int remove_email(struct mailing_list *list, char *email) {
    struct node *current = list->head;
    struct node *previous = NULL;

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
            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

int main() {
    struct mailing_list *list = create_list();

    add_email(list, "john@example.com");
    add_email(list, "jane@example.com");
    add_email(list, "bob@example.com");

    remove_email(list, "jane@example.com");

    struct node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }

    destroy_list(list);
    return 0;
}