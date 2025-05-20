//Falcon-180B DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Error: Username already exists.\n");
            return;
        }
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);
    num_passwords++;
}

void remove_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            num_passwords--;
            break;
        }
    }
}

void display_passwords() {
    if (num_passwords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Username\tPassword\n");
    printf("------------------------------------\n");

    int i;
    for (i = 0; i < num_passwords; i++) {
        if (passwords[i].username[0]!= '\0') {
            printf("%s\t%s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    char choice;

    do {
        printf("Password Manager\n");
        printf("---------------------\n");
        printf("A - Add password\n");
        printf("R - Remove password\n");
        printf("D - Display passwords\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A': {
                char username[MAX_PASSWORD_LENGTH];
                char password[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                add_password(username, password);
                break;
            }

            case 'R': {
                char username[MAX_PASSWORD_LENGTH];

                printf("Enter username: ");
                scanf("%s", username);

                remove_password(username);
                break;
            }

            case 'D': {
                display_passwords();
                break;
            }

            case 'Q': {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Error: Invalid choice.\n");
            }
        }
    } while (choice!= 'Q');

    return 0;
}