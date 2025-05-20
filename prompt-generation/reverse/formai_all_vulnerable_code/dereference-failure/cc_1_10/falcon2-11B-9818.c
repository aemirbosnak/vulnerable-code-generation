//Falcon2-11B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

struct Password {
    char* username;
    char* password;
};

struct Password* passwordList[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    struct Password* newPassword = malloc(sizeof(struct Password));
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);
    passwordList[numPasswords++] = newPassword;
}

void removePassword(char* username) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwordList[i]->username, username) == 0) {
            free(passwordList[i]->username);
            free(passwordList[i]->password);
            free(passwordList[i]);
            passwordList[i] = NULL;
            numPasswords--;
            break;
        }
    }
}

void printPasswords() {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\n", passwordList[i]->username);
        printf("Password: ********\n");
    }
}

int main() {
    char* username = "john";
    char* password = "password123";
    addPassword(username, password);
    printPasswords();

    removePassword(username);
    printPasswords();

    return 0;
}