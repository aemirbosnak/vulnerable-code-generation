//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mailing_list {
    char name[100];
    struct mailing_list *next;
};

struct mailing_list *head = NULL;

void add_to_list(char *name) {
    struct mailing_list *new_entry = malloc(sizeof(struct mailing_list));
    strcpy(new_entry->name, name);
    new_entry->next = NULL;

    if (head == NULL) {
        head = new_entry;
    } else {
        struct mailing_list *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_entry;
    }
}

void remove_from_list(char *name) {
    struct mailing_list *current = head;
    struct mailing_list *prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void display_list() {
    struct mailing_list *current = head;
    while (current!= NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    add_to_list("Alice");
    add_to_list("Bob");
    add_to_list("Charlie");
    add_to_list("David");
    add_to_list("Eve");

    display_list();

    remove_from_list("Alice");
    remove_from_list("Bob");
    remove_from_list("David");

    display_list();

    return 0;
}