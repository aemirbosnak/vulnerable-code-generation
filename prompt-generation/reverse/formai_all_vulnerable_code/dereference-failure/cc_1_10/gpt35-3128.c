//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email_node {
    char address[50];
    struct email_node *next;
} email_node;

// Function to create a new email_node
email_node *create_node(char *address) {
    email_node *new_node = malloc(sizeof(email_node));
    strcpy(new_node->address, address);
    new_node->next = NULL;
    return new_node;
}

// Function to add a new email to the mailing list
void add_email(email_node **head, char *address) {
    email_node *new_node = create_node(address);

    if (*head == NULL) {
        *head = new_node;
        printf("Successfully added %s to the mailing list!\n", address);
    } else {
        email_node *current_node = *head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
        printf("Successfully added %s to the mailing list!\n", address);
    }
}

// Function to print out all the emails in the mailing list
void print_emails(email_node *head) {
    if (head == NULL) {
        printf("There are currently no emails in the mailing list.\n");
    } else {
        printf("Here are all the emails in the mailing list:\n");
        email_node *current_node = head;
        while (current_node != NULL) {
            printf("%s\n", current_node->address);
            current_node = current_node->next;
        }
    }
}

// Function to remove an email from the mailing list
void remove_email(email_node **head, char *address) {
    if (*head == NULL) {
        printf("There are no emails in the mailing list to remove.\n");
    } else if (strcmp((*head)->address, address) == 0) {
        email_node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Successfully removed %s from the mailing list!\n", address);
    } else {
        email_node *prev_node = *head;
        email_node *current_node = (*head)->next;
        while (current_node != NULL && strcmp(current_node->address, address) != 0) {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (current_node == NULL) {
            printf("%s is not in the mailing list.\n", address);
        } else {
            prev_node->next = current_node->next;
            free(current_node);
            printf("Successfully removed %s from the mailing list!\n", address);
        }
    }
}

int main() {
    email_node *head = NULL;
    printf("Welcome to the mailing list manager!\n");

    while (1) {
        int choice;
        char email[50];

        printf("What would you like to do?\n");
        printf("1. Add an email to the mailing list.\n");
        printf("2. Remove an email from the mailing list.\n");
        printf("3. View all emails in the mailing list.\n");
        printf("4. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the email address to add: ");
                scanf("%s", email);
                add_email(&head, email);
                break;
            case 2:
                printf("Enter the email address to remove: ");
                scanf("%s", email);
                remove_email(&head, email);
                break;
            case 3:
                print_emails(head);
                break;
            case 4:
                printf("Thank you for using the mailing list manager. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
                break;
        }
    }

    return 0;
}