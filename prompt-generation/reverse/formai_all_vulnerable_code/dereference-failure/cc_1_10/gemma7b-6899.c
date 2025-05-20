//Gemma-7B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
    char *name;
    char *password;
    struct Password *next;
} Password;

void insert_password(Password **head) {
    Password *new_password = (Password *)malloc(sizeof(Password));
    new_password->name = malloc(20);
    new_password->password = malloc(20);
    new_password->next = NULL;

    printf("Enter the name of the password:");
    scanf("%s", new_password->name);

    printf("Enter the password:");
    scanf("%s", new_password->password);

    if (*head == NULL) {
        *head = new_password;
    } else {
        (*head)->next = new_password;
    }
}

void search_password(Password *head) {
    char search_name[20];

    printf("Enter the name of the password to search:");
    scanf("%s", search_name);

    Password *current_password = head;
    while (current_password) {
        if (strcmp(current_password->name, search_name) == 0) {
            printf("Password: %s\n", current_password->password);
            break;
        }
        current_password = current_password->next;
    }

    if (current_password == NULL) {
        printf("Password not found.\n");
    }
}

int main() {
    Password *head = NULL;

    while (1) {
        int choice;

        printf("1. Insert password\n");
        printf("2. Search password\n");
        printf("3. Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_password(&head);
                break;
            case 2:
                search_password(head);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}