//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    passwords[num_passwords].username = (char *)malloc(strlen(username) + 1);
    strcpy(passwords[num_passwords].username, username);

    passwords[num_passwords].password = (char *)malloc(strlen(password) + 1);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void delete_password() {
    int i;

    printf("Enter username to delete: ");
    scanf("%s", passwords[0].username);

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            passwords[i] = passwords[num_passwords - 1];
            num_passwords--;

            break;
        }
    }
}

void view_passwords() {
    int i;

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n2. Delete password\n3. View passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            delete_password();
            break;
        case 3:
            view_passwords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}