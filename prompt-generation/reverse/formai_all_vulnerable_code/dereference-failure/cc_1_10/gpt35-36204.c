//FormAI DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* password;
    struct node *next;
} Node;

Node *head = NULL;

void add_password(char* password) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->password = password;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void delete_password(char* password) {
    if (head == NULL) {
        printf("No passwords to delete!\n");
        return;
    }

    Node *current_node = head;
    Node *previous_node = NULL;

    while (current_node != NULL && strcmp(current_node->password, password) != 0) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        printf("Password not found!\n");
        return;
    }

    if (previous_node == NULL) {
        head = current_node->next;
    } else {
        previous_node->next = current_node->next;
    }
    free(current_node);
    printf("Password has been deleted.\n");
}

void print_passwords() {
    if (head == NULL) {
        printf("No passwords to print!\n");
        return;
    }

    Node *current_node = head;

    while (current_node != NULL) {
        printf("%s\n", current_node->password);
        current_node = current_node->next;
    }
}

int main() {
    char choice;
    char password[50];

    do {
        printf("\nPassword Management System\n");
        printf("(a) Add password\n");
        printf("(b) Delete password\n");
        printf("(c) Print passwords\n");
        printf("(q) Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter password to add: ");
                scanf(" %s", password);
                add_password(password);
                printf("Password has been added.\n");
                break;
            case 'b':
                printf("Enter password to delete: ");
                scanf(" %s", password);
                delete_password(password);
                break;
            case 'c':
                printf("Current Passwords:\n");
                print_passwords();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 'q');

    return 0;
}