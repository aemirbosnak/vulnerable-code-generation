//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char email[50];
    struct node *next;
};

struct mailing_list {
    struct node *head;
    struct node *tail;
};

struct mailing_list *create_mailing_list() {
    struct mailing_list *list = malloc(sizeof(struct mailing_list));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void add_subscriber(struct mailing_list *list, char *name, char *email) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }

    list->tail = new_node;
}

void remove_subscriber(struct mailing_list *list, char *name) {
    struct node *current_node = list->head;
    struct node *previous_node = NULL;

    while (current_node != NULL) {
        if (strcmp(current_node->name, name) == 0) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }

            if (current_node == list->tail) {
                list->tail = previous_node;
            }

            free(current_node);
            return;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    printf("Subscriber not found.\n");
}

void send_email(struct mailing_list *list, char *subject, char *body) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        printf("To: %s <%s>\n", current_node->name, current_node->email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n\n", body);

        current_node = current_node->next;
    }
}

void free_mailing_list(struct mailing_list *list) {
    struct node *current_node = list->head;

    while (current_node != NULL) {
        struct node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(list);
}

int main() {
    struct mailing_list *list = create_mailing_list();

    add_subscriber(list, "John Doe", "john.doe@example.com");
    add_subscriber(list, "Jane Doe", "jane.doe@example.com");
    add_subscriber(list, "Bob Smith", "bob.smith@example.com");
    remove_subscriber(list, "Bob Smith");
    send_email(list, "Hello", "This is a test email.");
    free_mailing_list(list);

    return 0;
}