//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PasswordNode {
    char service[50];
    char password[50];
    struct PasswordNode* next;
} PasswordNode;

PasswordNode* head = NULL;

void add_password() {
    PasswordNode* new_node = (PasswordNode*)malloc(sizeof(PasswordNode));
    
    printf("Enter the service name: ");
    scanf("%s", new_node->service);
    
    printf("Enter the password: ");
    scanf("%s", new_node->password);
    
    new_node->next = head;
    head = new_node;
    printf("Password added for %s!\n", new_node->service);
}

void display_passwords() {
    if (head == NULL) {
        printf("No passwords stored.\n");
        return;
    }
    
    printf("\nStored Passwords:\n");
    PasswordNode* current = head;
    
    while (current != NULL) {
        printf("Service: %s, Password: %s\n", current->service, current->password);
        current = current->next;
    }
    printf("\n");
}

void delete_password() {
    char service[50];
    printf("Enter the service name to delete: ");
    scanf("%s", service);

    PasswordNode* current = head;
    PasswordNode* previous = NULL;

    while (current != NULL && strcmp(current->service, service) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No password found for %s.\n", service);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Password for %s deleted!\n", service);
}

void free_memory() {
    PasswordNode* current = head;
    PasswordNode* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Password Manager ---\n");
        printf("1. Add Password\n");
        printf("2. Display Passwords\n");
        printf("3. Delete Password\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                display_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                free_memory();
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}