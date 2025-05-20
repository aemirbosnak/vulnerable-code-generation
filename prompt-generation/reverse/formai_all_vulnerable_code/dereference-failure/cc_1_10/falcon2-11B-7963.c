//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    struct list_node *next;
} list_node;

typedef struct {
    list_node *head;
} mailing_list;

list_node *create_list(const char *name) {
    list_node *new_node = malloc(sizeof(list_node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void delete_list(mailing_list *list) {
    list_node *current = list->head;
    list->head = NULL;
    free(current);
}

void add_member(mailing_list *list, const char *name) {
    list_node *new_node = create_list(name);
    list_node *current = list->head;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Member %s already exists in the list.\n", name);
            return;
        }
        current = current->next;
    }

    new_node->next = list->head;
    list->head = new_node;
}

void remove_member(mailing_list *list, const char *name) {
    list_node *current = list->head;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Member %s removed from the list.\n", name);
            list_node *next = current->next;
            free(current);
            list->head = next;
            return;
        }
        current = current->next;
    }

    printf("Member %s not found in the list.\n", name);
}

char *list_members(mailing_list *list) {
    list_node *current = list->head;
    char *members = malloc(100 * sizeof(char));

    while (current!= NULL) {
        strcat(members, current->name);
        strcat(members, ", ");
        current = current->next;
    }

    return strcat(members, "\n");
}

void usage() {
    mailing_list list;
    list.head = create_list("List 1");
    add_member(&list, "John");
    add_member(&list, "Jane");
    add_member(&list, "Bob");
    printf("%s\n", list_members(&list));
    remove_member(&list, "Bob");
    printf("%s\n", list_members(&list));
    delete_list(&list);
}

int main() {
    usage();
    return 0;
}