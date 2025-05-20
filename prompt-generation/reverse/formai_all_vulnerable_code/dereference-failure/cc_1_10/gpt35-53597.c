//FormAI DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 5

/* Structure to store password information */
typedef struct password_info {
    char username[20];
    char password[20];
} password_info_t;

/* Function to add a new password to the database */
void add_password(password_info_t *passwords, int *num_passwords) {
    if (*num_passwords >= MAX_PASSWORDS) {
        printf("Cannot add more passwords. Database max capacity reached.\n");
        return;
    }
    printf("Enter username: ");
    scanf("%s", passwords[*num_passwords].username);
    printf("Enter password: ");
    scanf("%s", passwords[*num_passwords].password);
    *num_passwords += 1;
    printf("Password added successfully!\n");
}

/* Function to retrieve a password from the database */
void get_password(password_info_t *passwords, int num_passwords) {
    char username[20];
    printf("Enter username: ");
    scanf("%s", username);
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password for %s is %s\n", username, passwords[i].password);
            return;
        }
    }
    printf("Password not found for %s\n", username);
}

/* Main function */
int main(int argc, char *argv[]) {
    /* Initialize password database */
    password_info_t *passwords = (password_info_t *) malloc(MAX_PASSWORDS * sizeof(password_info_t));
    int num_passwords = 0;

    /* Infinite loop for menu-driven interface */
    while (1) {
        printf("\n1. Add password\n");
        printf("2. Get password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password(passwords, &num_passwords);
                break;
            
            case 2:
                get_password(passwords, num_passwords);
                break;
            
            case 3:
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}