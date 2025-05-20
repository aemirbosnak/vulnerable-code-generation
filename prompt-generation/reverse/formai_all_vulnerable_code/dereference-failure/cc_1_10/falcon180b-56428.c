//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    Password* newPassword = &passwords[numPasswords];
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);

    numPasswords++;
}

int findPasswordIndex(char* username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void removePassword(int index) {
    if (index < 0 || index >= numPasswords) {
        printf("Error: Invalid password index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < numPasswords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    numPasswords--;
}

void listPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\n", passwords[i].username);
    }
}

int main() {
    addPassword("example@gmail.com", "password123");
    addPassword("test@yahoo.com", "testpassword456");

    listPasswords();

    removePassword(0);

    listPasswords();

    return 0;
}