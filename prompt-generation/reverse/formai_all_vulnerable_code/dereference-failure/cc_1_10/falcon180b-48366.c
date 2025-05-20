//Falcon-180B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password *passwords = (Password*)malloc(MAX_PASSWORDS * sizeof(Password));

    char choice;
    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[numPasswords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                }
                break;

            case '2':
                if (numPasswords == 0) {
                    printf("No passwords to delete.\n");
                } else {
                    printf("Enter username of password to delete: ");
                    scanf("%s", passwords[numPasswords - 1].username);
                    numPasswords--;
                }
                break;

            case '3':
                if (numPasswords == 0) {
                    printf("No passwords to view.\n");
                } else {
                    printf("Username\tPassword\n");
                    for (int i = 0; i < numPasswords; i++) {
                        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
                    }
                }
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}