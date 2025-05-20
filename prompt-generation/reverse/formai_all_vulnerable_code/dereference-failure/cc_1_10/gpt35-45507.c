//FormAI DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact_t;

typedef struct node {
    contact_t contact;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_contact(contact_t new_contact) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->contact = new_contact;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void remove_contact(char *email) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *current = head;
    node_t *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->contact.email, email) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Contact removed successfully\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Contact not found\n");
}

void print_list() {
    printf("Current Contacts:\n");
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *current = head;
    while (current != NULL) {
        printf("Name: %s\tEmail: %s\n", current->contact.name, current->contact.email);
        current = current->next;
    }
}

int main() {
    while (1) {
        printf("=====================\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("=====================\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                contact_t new_contact;
                printf("Enter name: ");
                scanf("%s", new_contact.name);
                printf("Enter email: ");
                scanf("%s", new_contact.email);
                add_contact(new_contact);
                printf("Contact added successfully\n");
                break;
            }
            case 2: {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_contact(email);
                break;
            }
            case 3: {
                print_list();
                break;
            }
            case 4: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    return 0;
}