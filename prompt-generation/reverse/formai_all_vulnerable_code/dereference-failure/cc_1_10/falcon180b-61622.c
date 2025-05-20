//Falcon-180B DATASET v1.0 Category: Password management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char* username;
    char* password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int length = strlen(username);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Username too long.\n");
        return;
    }

    int passwordLength = strlen(password);
    if (passwordLength > MAX_PASSWORD_LENGTH) {
        printf("Error: Password too long.\n");
        return;
    }

    passwords[numPasswords].username = malloc(length + 1);
    strcpy(passwords[numPasswords].username, username);

    passwords[numPasswords].password = malloc(passwordLength + 1);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void removePassword(char* username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            numPasswords--;
            return;
        }
    }

    printf("Error: Password not found.\n");
}

void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    addPassword("example@example.com", "password123");
    addPassword("test@test.com", "testpassword");

    printPasswords();

    removePassword("example@example.com");

    printPasswords();

    return 0;
}