//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct mailing_list_node {
    char *email;
    struct mailing_list_node *next;
};

struct mailing_list {
    struct mailing_list_node *head;
};

void print_list(struct mailing_list *list) {
    struct mailing_list_node *node = list->head;
    while (node!= NULL) {
        printf("%s\n", node->email);
        node = node->next;
    }
}

void add_to_list(struct mailing_list *list, char *email) {
    struct mailing_list_node *new_node = malloc(sizeof(struct mailing_list_node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(new_node->email, email);
    new_node->next = list->head;
    list->head = new_node;
}

void delete_from_list(struct mailing_list *list, char *email) {
    struct mailing_list_node *node = list->head;
    while (node!= NULL) {
        if (strcmp(node->email, email) == 0) {
            break;
        }
        node = node->next;
    }
    if (node == NULL) {
        printf("Email not found in list.\n");
        return;
    }
    struct mailing_list_node *temp = node->next;
    free(node);
    list->head = temp;
}

void update_email(struct mailing_list *list, char *old_email, char *new_email) {
    struct mailing_list_node *node = list->head;
    while (node!= NULL) {
        if (strcmp(node->email, old_email) == 0) {
            node->email = new_email;
            break;
        }
        node = node->next;
    }
}

int main() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    if (list == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    list->head = NULL;

    add_to_list(list, "user1@example.com");
    add_to_list(list, "user2@example.com");
    add_to_list(list, "user3@example.com");

    printf("List before removing user2:\n");
    print_list(list);

    delete_from_list(list, "user2@example.com");

    printf("List after removing user2:\n");
    print_list(list);

    update_email(list, "user3@example.com", "user3@example.com.com");

    printf("List after updating user3's email:\n");
    print_list(list);

    free(list);
    return 0;
}