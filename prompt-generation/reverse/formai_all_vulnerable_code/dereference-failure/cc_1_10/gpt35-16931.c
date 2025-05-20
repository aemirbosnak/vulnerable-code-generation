//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char address[100];
    struct email *next;
} Email;

typedef struct list {
    Email *head;
    int size;
} List;

List *create_list() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_email(List *list, char *address) {
    Email *new_email = malloc(sizeof(Email));
    strcpy(new_email->address, address);
    new_email->next = NULL;

    if (list->head == NULL) {
        list->head = new_email;
    } else {
        Email *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_email;
    }

    list->size++;
}

void remove_email(List *list, char *address) {
    Email *previous = NULL;
    Email *current = list->head;

    while (current != NULL && strcmp(current->address, address) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email not found!\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    list->size--;
}

void print_list(List *list) {
    Email *current = list->head;

    while (current != NULL) {
        printf("%s\n", current->address);
        current = current->next;
    }
}

int main() {
    List *list = create_list();

    add_email(list, "john.doe@email.com");
    add_email(list, "jane.doe@email.com");
    add_email(list, "foo.bar@email.com");

    printf("Mailing List:\n");
    print_list(list);

    printf("Removing jane.doe@email.com...\n");
    remove_email(list, "jane.doe@email.com");

    printf("Mailing List:\n");
    print_list(list);

    return 0;
}