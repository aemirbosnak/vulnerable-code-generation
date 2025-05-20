//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a mailing list node
typedef struct mailing_list_node {
    char *email;
    struct mailing_list_node *next;
} mailing_list_node;

// define a mailing list
typedef struct mailing_list {
    mailing_list_node *head;
    mailing_list_node *tail;
} mailing_list;

// create a new mailing list
mailing_list *create_mailing_list() {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// add an email to the mailing list
void add_email(mailing_list *list, char *email) {
    mailing_list_node *node = malloc(sizeof(mailing_list_node));
    node->email = strdup(email);
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// remove an email from the mailing list
void remove_email(mailing_list *list, char *email) {
    mailing_list_node *current = list->head;
    mailing_list_node *previous = NULL;

    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // email not found
        return;
    } else if (previous == NULL) {
        // email is the head of the list
        list->head = current->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
    } else {
        // email is in the middle of the list
        previous->next = current->next;
        if (current == list->tail) {
            list->tail = previous;
        }
    }

    free(current->email);
    free(current);
}

// print the mailing list
void print_mailing_list(mailing_list *list) {
    mailing_list_node *current = list->head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

// free the mailing list
void free_mailing_list(mailing_list *list) {
    mailing_list_node *current = list->head;

    while (current != NULL) {
        mailing_list_node *next = current->next;
        free(current->email);
        free(current);
        current = next;
    }

    free(list);
}

// main function
int main() {
    // create a new mailing list
    mailing_list *list = create_mailing_list();

    // add some emails to the mailing list
    add_email(list, "john@example.com");
    add_email(list, "mary@example.com");
    add_email(list, "bob@example.com");

    // print the mailing list
    print_mailing_list(list);

    // remove an email from the mailing list
    remove_email(list, "bob@example.com");

    // print the mailing list
    print_mailing_list(list);

    // free the mailing list
    free_mailing_list(list);

    return 0;
}