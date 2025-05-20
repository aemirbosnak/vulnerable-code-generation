//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 64

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char* charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    int numPasswords;
    printf("How many passwords do you want to generate? ");
    scanf("%d", &numPasswords);

    if (numPasswords > MAX_PASSWORDS) {
        printf("Error: Cannot generate more than %d passwords.\n", MAX_PASSWORDS);
        return 1;
    }

    Password passwords[numPasswords];

    for (int i = 0; i < numPasswords; i++) {
        printf("Enter a label for password %d: ", i+1);
        scanf("%s", passwords[i].username);

        generatePassword(passwords[i].password, MAX_PASSWORD_LENGTH);

        printf("Password for %s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}