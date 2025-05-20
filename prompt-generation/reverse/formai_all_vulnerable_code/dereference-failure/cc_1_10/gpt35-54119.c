//FormAI DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    struct User* next;
};

struct User* head = NULL;

void add_user(struct User** head_ref, char* username, char* password) {
    struct User* new_user = (struct User*) malloc(sizeof(struct User));
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->next = (*head_ref);
    (*head_ref) = new_user;
}

bool check_credentials(char* username, char* password) {
    struct User* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void print_list() {
    struct User* current = head;
    while (current != NULL) {
        printf("Username: %s\nPassword: %s\n\n", current->username, current->password);
        current = current->next;
    }
}

int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    while (true) {
        printf("1. Add user\n2. Check credentials\n3. Print list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                add_user(&head, username, password);
                printf("\nUser added successfully!\n\n");
                break;
            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                if (check_credentials(username, password)) {
                    printf("\nWelcome, %s!\n\n", username);
                } else {
                    printf("\nInvalid credentials!\n\n");
                }
                break;
            case 3:
                printf("\nUser list:\n");
                print_list();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    }
    return 0;
}