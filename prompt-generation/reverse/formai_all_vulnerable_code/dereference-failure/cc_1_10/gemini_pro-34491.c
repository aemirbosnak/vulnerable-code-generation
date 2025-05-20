//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MailingList {
    char name[256];
    char email[256];
    struct MailingList *next;
} MailingList;

MailingList *head = NULL;
MailingList *tail = NULL;

void add_to_mailing_list(char *name, char *email) {
    MailingList *new_node = malloc(sizeof(MailingList));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_mailing_list() {
    MailingList *current_node = head;

    while (current_node != NULL) {
        printf("%s (%s)\n", current_node->name, current_node->email);
        current_node = current_node->next;
    }
}

void remove_from_mailing_list(char *email) {
    MailingList *current_node = head;
    MailingList *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->email, email) == 0) {
            if (current_node == head) {
                head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            free(current_node);

            if (current_node == tail) {
                tail = previous_node;
            }

            break;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

int main() {
    add_to_mailing_list("John Doe", "john.doe@example.com");
    add_to_mailing_list("Jane Doe", "jane.doe@example.com");
    add_to_mailing_list("Bill Smith", "bill.smith@example.com");

    print_mailing_list();

    remove_from_mailing_list("jane.doe@example.com");

    print_mailing_list();

    return 0;
}