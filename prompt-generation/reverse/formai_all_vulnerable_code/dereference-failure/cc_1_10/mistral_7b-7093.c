//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct mailing_list {
    char name[50];
    struct mailing_list *next;
} mailing_list;

void add_to_list(mailing_list **head, char *name) {
    mailing_list *new_mailing_list = (mailing_list *)malloc(sizeof(mailing_list));
    strcpy(new_mailing_list->name, name);
    new_mailing_list->next = *head;
    *head = new_mailing_list;
}

void remove_from_list(mailing_list **head, char *name) {
    mailing_list *current = *head;
    mailing_list *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_list(mailing_list *head) {
    mailing_list *current = head;
    printf("---Mailman's Funny Mailing List---*\n");
    while (current != NULL) {
        printf("%s: %s is on the list!\n", current->name, current->name);
        current = current->next;
    }
}

int main() {
    mailing_list *head = NULL;

    add_to_list(&head, "Alice");
    add_to_list(&head, "Bob");
    add_to_list(&head, "Charlie");

    printf("Before removing someone:\n");
    print_list(head);

    remove_from_list(&head, "Bob");

    printf("After removing Bob:\n");
    print_list(head);

    return 0;
}