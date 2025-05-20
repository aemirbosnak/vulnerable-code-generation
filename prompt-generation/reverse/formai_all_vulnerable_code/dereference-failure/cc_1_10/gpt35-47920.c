//FormAI DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

struct password {
    int id;
    char name[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct password* next;
};

struct password* head = NULL;

void add_password() {
    struct password* new_password = (struct password*)malloc(sizeof(struct password));
    printf("Enter password name: ");
    scanf("%s", new_password->name);
    printf("Enter username: ");
    scanf("%s", new_password->username);
    printf("Enter password: ");
    scanf("%s", new_password->password);
    new_password->next = head;
    head = new_password;
    printf("\nNew password added successfully!\n\n");
}

void view_passwords() {
    struct password* current = head;
    if (current == NULL) {
        printf("\nNo passwords found.\n\n");
    }
    else {
        printf("\nPassword List:\n");
        while (current != NULL) {
            printf("ID: %d\tName: %s\tUsername: %s\tPassword: %s\n", current->id, current->name, current->username, current->password);
            current = current->next;
        }
    }
}

void search_password() {
    char name[MAX_PASSWORD_LENGTH];
    printf("\nEnter password name: ");
    scanf("%s", name);
    struct password* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("\nPassword found:\n");
            printf("ID: %d\tName: %s\tUsername: %s\tPassword: %s\n\n", current->id, current->name, current->username, current->password);
            return;
        }
        current = current->next;
    }
    printf("\nPassword not found.\n\n");
}

void delete_password() {
    int id;
    printf("\nEnter password ID to delete: ");
    scanf("%d", &id);
    struct password* current = head;
    struct password* previous = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            printf("\nPassword deleted successfully.\n\n");
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("\nPassword not found.\n\n");
}

int get_menu_choice() {
    int choice;
    printf("Menu\n");
    printf("1. Add Password\n");
    printf("2. View Passwords\n");
    printf("3. Search Password\n");
    printf("4. Delete Password\n");
    printf("5. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int get_next_id() {
    struct password* current = head;
    int max_id = 0;
    while (current != NULL) {
        if (current->id > max_id) {
            max_id = current->id;
        }
        current = current->next;
    }
    return max_id + 1;
}

int main() {
    while (1) {
        int choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    }
}