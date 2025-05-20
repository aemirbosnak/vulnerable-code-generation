//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char* site;
    char* username;
    char* password;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int passwordCount = 0;

    char input[MAX_PASSWORD_LENGTH];
    while (1) {
        printf("(A)dd new password, (V)iew passwords, or (Q)uit\n");
        fgets(input, MAX_PASSWORD_LENGTH, stdin);
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        } else if (input[0] == 'a' || input[0] == 'A') {
            Password newPassword;
            newPassword.site = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
            newPassword.username = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
            newPassword.password = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char));

            printf("Enter site name: ");
            fgets(newPassword.site, MAX_PASSWORD_LENGTH, stdin);
            printf("Enter username: ");
            fgets(newPassword.username, MAX_PASSWORD_LENGTH, stdin);
            printf("Enter password: ");
            fgets(newPassword.password, MAX_PASSWORD_LENGTH, stdin);

            passwords[passwordCount] = newPassword;
            passwordCount++;
        } else if (input[0] == 'v' || input[0] == 'V') {
            for (int i = 0; i < passwordCount; i++) {
                printf("Site: %sUsername: %sPassword: %s\n", passwords[i].site, passwords[i].username, passwords[i].password);
            }
        } else {
            printf("Invalid input!\n");
        }
    }

    for (int i = 0; i < passwordCount; i++) {
        free(passwords[i].site);
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}