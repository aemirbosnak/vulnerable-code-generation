//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct Password {
    char *name;
    char *value;
} Password;

Password *passwords[MAX_PASSWORDS];
int password_count = 0;

void add_password() {
    char *name = malloc(256);
    char *value = malloc(256);

    printf("Enter name of password: ");
    scanf("%s", name);

    printf("Enter password value: ");
    scanf("%s", value);

    Password *p = malloc(sizeof(Password));
    p->name = name;
    p->value = value;

    passwords[password_count] = p;
    password_count++;

    printf("Password added successfully!\n\n");
}

void print_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < password_count; i++) {
        printf("%s: %s\n", passwords[i]->name, passwords[i]->value);
    }
    printf("\n");
}

void delete_password() {
    printf("Enter name of password to delete: ");
    char name[256];
    scanf("%s", name);

    int deleted_passwords = 0;
    for (int i = 0; i < password_count; i++) {
        if (strcmp(passwords[i]->name, name) == 0) {
            free(passwords[i]->name);
            free(passwords[i]->value);
            free(passwords[i]);
            passwords[i] = NULL;
            deleted_passwords++;
        }
    }

    if (deleted_passwords > 0) {
        printf("%d password(s) deleted successfully!\n\n", deleted_passwords);
    } else {
        printf("No passwords found with name '%s'\n\n", name);
    }
}

void delete_all_passwords() {
    printf("Confirm deletion of all passwords (y/n): ");
    char input;
    scanf(" %c", &input);

    if (input == 'y') {
        int deleted_passwords = 0;
        for (int i = 0; i < password_count; i++) {
            if (passwords[i] != NULL) {
                free(passwords[i]->name);
                free(passwords[i]->value);
                free(passwords[i]);
                passwords[i] = NULL;
                deleted_passwords++;
            }
        }
        password_count = 0;

        printf("%d password(s) deleted successfully!\n\n", deleted_passwords);
    } else {
        printf("Deletion cancelled.\n\n");
    }
}

int main() {
    printf("Welcome to Password Manager!\n\n");
    int input = 0;

    while (input != 4) {
        printf("Please choose an option:\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Quit\n");

        scanf("%d", &input);
        printf("\n");

        switch (input) {
            case 1:
                add_password();
                break;
            case 2:
                print_passwords();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                delete_all_passwords();
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input, please try again.\n\n");
                break;
        }
    }

    return 0;
}