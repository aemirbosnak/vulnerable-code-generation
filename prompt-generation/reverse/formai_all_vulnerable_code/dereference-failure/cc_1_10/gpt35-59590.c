//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char email[50];
    struct Node *next;
} Node;

Node *head = NULL;

// Adds a new email to the mailing list
void add_email(char email[]) {
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = head;
    head = new_node;
    printf("Added %s to the mailing list.\n", email);
}

// Deletes an email from the mailing list
void delete_email(char email[]) {
    Node *prev_node = NULL;
    Node *curr_node = head;

    while (curr_node != NULL) {
        if (strcmp(curr_node->email, email) == 0) {
            if (prev_node == NULL) {
                head = curr_node->next;
            } else {
                prev_node->next = curr_node->next;
            }
            free(curr_node);
            printf("Deleted %s from the mailing list.\n", email);
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    printf("%s not found in the mailing list.\n", email);
}

// Prints out all the emails in the mailing list
void print_list() {
    Node *curr_node = head;

    printf("Mailing List:\n");
    while (curr_node != NULL) {
        printf("%s\n", curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    char input[50];
    char email[50];

    printf("Welcome to the Mailing List Manager!\n");
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter option number: ");

        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "1") == 0) {
            printf("Enter email to add: ");
            fgets(email, 50, stdin);
            email[strcspn(email, "\n")] = '\0';
            add_email(email);
        } else if (strcmp(input, "2") == 0) {
            printf("Enter email to delete: ");
            fgets(email, 50, stdin);
            email[strcspn(email, "\n")] = '\0';
            delete_email(email);
        } else if (strcmp(input, "3") == 0) {
            print_list();
        } else if (strcmp(input, "4") == 0) {
            printf("Exiting Mailing List Manager...\n");
            return 0;
        } else {
            printf("Invalid option.\n");
        }
    }
}