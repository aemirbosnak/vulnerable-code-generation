//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: optimized
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

void add_email(struct mailing_list *list, char *email) {
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

void remove_email(struct mailing_list *list, char *email) {
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
            return;
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    struct mailing_list *list = create_mailing_list();

    add_email(list, "alice@example.com");
    add_email(list, "bob@example.com");
    add_email(list, "charlie@example.com");

    remove_email(list, "bob@example.com");

    struct node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }

    return 0;
}