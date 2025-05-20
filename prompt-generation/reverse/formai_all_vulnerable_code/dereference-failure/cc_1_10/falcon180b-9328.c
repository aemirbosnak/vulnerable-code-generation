//Falcon-180B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password *newPassword = &passwords[numPasswords];
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);

    numPasswords++;
}

void removePassword(char *username) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            numPasswords--;

            for (int j = i; j < numPasswords; j++) {
                passwords[j] = passwords[j + 1];
            }

            return;
        }
    }

    printf("Error: Password not found.\n");
}

void printPasswords() {
    printf("Username\tPassword\n");

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    addPassword("example@gmail.com", "password123");
    addPassword("test@example.com", "testpassword");

    printPasswords();

    removePassword("example@gmail.com");

    printPasswords();

    return 0;
}