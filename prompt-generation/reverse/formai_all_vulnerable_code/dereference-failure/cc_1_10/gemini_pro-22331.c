//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *email;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

void list_init(struct list *list) {
    list->head = NULL;
    list->tail = NULL;
}

void list_append(struct list *list, char *email) {
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
}

void list_remove(struct list *list, char *email) {
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
            return;
        }
        previous = current;
        current = current->next;
    }
}

void list_print(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void list_free(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

int main(int argc, char **argv) {
    struct list list;
    list_init(&list);
    list_append(&list, "joe@example.com");
    list_append(&list, "mary@example.com");
    list_append(&list, "bob@example.com");
    list_print(&list);
    list_remove(&list, "bob@example.com");
    list_print(&list);
    list_free(&list);
    return 0;
}