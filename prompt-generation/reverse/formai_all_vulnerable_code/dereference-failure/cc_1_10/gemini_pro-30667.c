//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    char *email;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_email(char *email) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->email = strdup(email);
    new_node->next = head;
    head = new_node;
}

void remove_email(char *email) {
    node_t *current = head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->email);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

bool find_email(char *email) {
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}

void print_list() {
    node_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    char input[100];
    char *email;

    printf("Welcome to the Romantic Mailing List Manager!\n");

    while (true) {
        printf("What would you like to do?\n");
        printf("1. Add an email address\n");
        printf("2. Remove an email address\n");
        printf("3. Find an email address\n");
        printf("4. Print the list of email addresses\n");
        printf("5. Quit\n");

        fgets(input, sizeof(input), stdin);
        email = strtok(input, "\n");

        switch (atoi(email)) {
            case 1:
                printf("Enter the email address you would like to add: ");
                fgets(input, sizeof(input), stdin);
                email = strtok(input, "\n");
                add_email(email);
                printf("Email address added!\n");
                break;
            case 2:
                printf("Enter the email address you would like to remove: ");
                fgets(input, sizeof(input), stdin);
                email = strtok(input, "\n");
                remove_email(email);
                printf("Email address removed!\n");
                break;
            case 3:
                printf("Enter the email address you would like to find: ");
                fgets(input, sizeof(input), stdin);
                email = strtok(input, "\n");
                if (find_email(email)) {
                    printf("Email address found!\n");
                } else {
                    printf("Email address not found!\n");
                }
                break;
            case 4:
                printf("Here is the list of email addresses:\n");
                print_list();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}