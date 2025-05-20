//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
// This program is a mailing list manager written in C. 
// It allows users to manage their mailing lists by adding, deleting, and viewing email addresses. 
// The program uses structures and dynamic memory allocation to store email addresses.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char address[50];
    struct email *next;
};

void add_email(struct email **list, char *address);
void delete_email(struct email **list, char *address);
void print_emails(struct email *list);
void free_emails(struct email **list);

int main() {
    struct email *head = NULL;
    int choice;
    char address[50];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add email address\n");
        printf("2. Delete email address\n");
        printf("3. View email addresses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the email address you wish to add to the list: ");
                scanf("%s", address);
                add_email(&head, address);
                break;
            case 2:
                printf("Enter the email address you wish to delete from the list: ");
                scanf("%s", address);
                delete_email(&head, address);
                break;
            case 3:
                print_emails(head);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free_emails(&head);
    return 0;
}

void add_email(struct email **list, char *address) {
    struct email *new_email = malloc(sizeof(struct email));
    strcpy(new_email->address, address);
    new_email->next = *list;
    *list = new_email;
}

void delete_email(struct email **list, char *address) {
    struct email *current = *list;
    struct email *previous = NULL;

    while (current != NULL && strcmp(current->address, address) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Email address not found in list.\n");
        return;
    }

    if (previous == NULL) {
        *list = current->next;
    } else {
        previous->next = current->next;
    }

    printf("Email address deleted from list.\n");
    free(current);
}

void print_emails(struct email *list) {
    if (list == NULL) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("Mailing List:\n");
    while (list != NULL) {
        printf("%s\n", list->address);
        list = list->next;
    }
}

void free_emails(struct email **list) {
    struct email *current = *list;
    struct email *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *list = NULL;
}