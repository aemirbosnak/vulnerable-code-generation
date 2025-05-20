//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct contact *next;
};

struct mailing_list {
    struct contact *head;
    int size;
};

void add_contact(struct mailing_list *list, char *name, char *email) {
    struct contact *new_contact = (struct contact*) malloc(sizeof(struct contact));
    strncpy(new_contact->name, name, MAX_NAME_LENGTH);
    strncpy(new_contact->email, email, MAX_EMAIL_LENGTH);
    new_contact->next = list->head;
    list->head = new_contact;
    list->size++;
}

void print_contacts(struct mailing_list *list) {
    struct contact *ptr = list->head;
    while (ptr != NULL) {
        printf("Name: %s\n", ptr->name);
        printf("Email: %s\n", ptr->email);
        ptr = ptr->next;
    }
}

void delete_contact(struct mailing_list *list, char *name) {
    struct contact *ptr = list->head;
    struct contact *prev = NULL;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (prev == NULL) {
                list->head = ptr->next;
            }
            else {
                prev->next = ptr->next;
            }
            free(ptr);
            list->size--;
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

int main() {
    struct mailing_list list;
    list.head = NULL;
    list.size = 0;

    add_contact(&list, "Alice", "alice@example.com");
    add_contact(&list, "Bob", "bob@example.com");
    add_contact(&list, "Charlie", "charlie@example.com");

    printf("Initial list:\n");
    print_contacts(&list);

    delete_contact(&list, "Charlie");

    printf("List after deleting Charlie:\n");
    print_contacts(&list);

    return 0;
}