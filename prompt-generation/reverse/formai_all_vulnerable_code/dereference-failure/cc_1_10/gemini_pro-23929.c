//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: systematic
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

void free_mailing_list(mailing_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    free(list);
}

int add_email_to_mailing_list(mailing_list_t *list, char *email) {
    node_t *new_node = malloc(sizeof(node_t));
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
    return 0;
}

int remove_email_from_mailing_list(mailing_list_t *list, char *email) {
    node_t *current = list->head;
    node_t *previous = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        return -1;
    } else if (previous == NULL) {
        list->head = current->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    } else {
        previous->next = current->next;
        if (current == list->tail) {
            list->tail = previous;
        }
    }
    free(current->email);
    free(current);
    list->size--;
    return 0;
}

void print_mailing_list(mailing_list_t *list) {
    node_t *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    mailing_list_t *list = create_mailing_list();
    add_email_to_mailing_list(list, "alice@example.com");
    add_email_to_mailing_list(list, "bob@example.com");
    add_email_to_mailing_list(list, "charlie@example.com");
    print_mailing_list(list);
    remove_email_from_mailing_list(list, "bob@example.com");
    print_mailing_list(list);
    free_mailing_list(list);
    return 0;
}