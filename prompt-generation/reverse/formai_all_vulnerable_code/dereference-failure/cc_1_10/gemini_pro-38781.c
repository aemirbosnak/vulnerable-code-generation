//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void init_list(list *l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void add_email(list *l, char *email) {
    node *new_node = malloc(sizeof(node));
    new_node->email = strdup(email);
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }

    l->size++;
}

void remove_email(list *l, char *email) {
    if (l->head == NULL) {
        return;
    }

    node *current = l->head;
    node *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                l->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == l->tail) {
                l->tail = previous;
            }

            free(current->email);
            free(current);

            l->size--;

            return;
        }

        previous = current;
        current = current->next;
    }
}

void print_list(list *l) {
    node *current = l->head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    list l;
    init_list(&l);

    char email[100];

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an email\n");
        printf("2. Remove an email\n");
        printf("3. Print the list\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the email address to add: ");
                scanf("%s", email);
                add_email(&l, email);
                printf("Email added!\n");
                break;
            case 2:
                printf("Enter the email address to remove: ");
                scanf("%s", email);
                remove_email(&l, email);
                printf("Email removed!\n");
                break;
            case 3:
                printf("Here is the list of emails:\n");
                print_list(&l);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}