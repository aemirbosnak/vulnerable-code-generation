//Falcon-180B DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char* service;
    char* username;
    char* password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* service, char* username, char* password) {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    numPasswords++;

    int i;
    for (i = 0; i < numPasswords - 1; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            printf("Error: Password for %s already exists.\n", service);
            return;
        }
    }

    passwords[numPasswords - 1].service = strdup(service);
    passwords[numPasswords - 1].username = strdup(username);
    passwords[numPasswords - 1].password = strdup(password);
}

void removePassword(char* service) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].service, service) == 0) {
            free(passwords[i].service);
            free(passwords[i].username);
            free(passwords[i].password);

            numPasswords--;

            for (int j = i; j < numPasswords; j++) {
                passwords[j] = passwords[j + 1];
            }

            return;
        }
    }

    printf("Error: Password for %s not found.\n", service);
}

void printPasswords() {
    printf("Service\tUsername\tPassword\n");

    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
    }
}

int main() {
    addPassword("Gmail", "example@gmail.com", "password123");
    addPassword("Facebook", "example@facebook.com", "password456");

    printPasswords();

    removePassword("Gmail");

    printPasswords();

    return 0;
}