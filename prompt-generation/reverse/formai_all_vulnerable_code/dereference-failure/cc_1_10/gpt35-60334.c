//FormAI DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LEN 50

typedef struct email {
    char address[MAX_LEN];
    struct email *next;
} email;

email *head = NULL;

int add_email(char address[MAX_LEN]) {
    if (strlen(address) > MAX_LEN) {
        printf("Error: Email address too long.\n");
        return 0;
    }

    email *current = head;

    while (current != NULL) {
        if (strcmp(current->address, address) == 0) {
            printf("Error: Email address already exists.\n");
            return 0;
        }
        current = current->next;
    }

    current = malloc(sizeof(email));
    strcpy(current->address, address);
    current->next = NULL;

    if (head == NULL) {
        head = current;
    } else {
        email *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = current;
    }

    return 1;
}

void print_list() {
    email *current = head;

    while (current != NULL) {
        printf("%s\n", current->address);
        current = current->next;
    }
}

int delete_email(char address[MAX_LEN]) {
    if (head == NULL) {
        printf("Error: List is empty.\n");
        return 0;
    }

    email *current = head;
    email *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->address, address) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    printf("Error: Email address not found.\n");
    return 0;
}

int main() {
    int choice;
    char address[MAX_LEN];

    do {
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Print list\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email address: ");
                scanf("%s", address);
                if (add_email(address)) {
                    printf("%s added to mailing list.\n", address);
                }
                break;
            case 2:
                printf("Enter email address: ");
                scanf("%s", address);
                if (delete_email(address)) {
                    printf("%s removed from mailing list.\n", address);
                }
                break;
            case 3:
                print_list();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}