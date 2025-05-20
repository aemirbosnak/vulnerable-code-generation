//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

list_t *create_list() {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_node(list_t *list, char *email) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->email = (char *)malloc(strlen(email) + 1);
    strcpy(new_node->email, email);
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

void remove_node(list_t *list, char *email) {
    node_t *current_node = list->head;
    node_t *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->email, email) == 0) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == list->tail) {
                list->tail = previous_node;
            }

            free(current_node->email);
            free(current_node);
            list->size--;
            return;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

void print_list(list_t *list) {
    node_t *current_node = list->head;

    while (current_node != NULL) {
        printf("%s\n", current_node->email);
        current_node = current_node->next;
    }
}

void free_list(list_t *list) {
    node_t *current_node = list->head;
    node_t *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node->email);
        free(current_node);
        current_node = next_node;
    }

    free(list);
}

int main() {
    list_t *list = create_list();

    char *emails[] = {
        "john@doe.com",
        "jane@doe.com",
        "bob@smith.com",
        "alice@smith.com",
        "tom@jones.com",
        "mary@jones.com"
    };

    for (int i = 0; i < 6; i++) {
        add_node(list, emails[i]);
    }

    print_list(list);

    remove_node(list, "bob@smith.com");
    remove_node(list, "alice@smith.com");

    print_list(list);

    free_list(list);

    return 0;
}