//Falcon2-11B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int numPasswords = 0;
int numUsers = 0;
char* passwords[100];

// Function to add a new password for a user
void addPassword(char* user, char* password) {
    int len = strlen(user);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(user, passwords[i]) == 0) {
            break;
        }
    }

    if (i == numUsers) {
        numUsers++;
        passwords[numUsers] = malloc(strlen(user) + 1);
        strcpy(passwords[numUsers], user);
    }

    len = strlen(password);
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(password, passwords[i]) == 0) {
            break;
        }
    }

    if (i == numPasswords) {
        numPasswords++;
        passwords[numPasswords] = malloc(len + 1);
        strcpy(passwords[numPasswords], password);
    }
}

// Function to delete a password for a user
void deletePassword(char* user, char* password) {
    int len = strlen(user);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(user, passwords[i]) == 0) {
            break;
        }
    }

    if (i == numUsers) {
        return;
    }

    len = strlen(password);
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(password, passwords[i]) == 0) {
            break;
        }
    }

    if (i == numPasswords) {
        return;
    }

    free(passwords[i]);
    numPasswords--;

    for (i = i + 1; i < numPasswords; i++) {
        strcpy(passwords[i - 1], passwords[i]);
    }
}

// Function to retrieve a password for a user
char* retrievePassword(char* user) {
    int len = strlen(user);
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(user, passwords[i]) == 0) {
            break;
        }
    }

    if (i == numUsers) {
        return NULL;
    }

    len = strlen(passwords[i]);
    return strdup(passwords[i]);
}

int main() {
    char* user = "Alice";
    char* password = "p@ssw0rd";

    addPassword(user, password);

    char* retrievedPassword = retrievePassword(user);
    if (retrievedPassword!= NULL) {
        printf("Password for %s is %s\n", user, retrievedPassword);
        free(retrievedPassword);
    } else {
        printf("Password not found\n");
    }

    deletePassword(user, "p@ssw0rd");

    retrievedPassword = retrievePassword(user);
    if (retrievedPassword!= NULL) {
        printf("Password for %s is %s\n", user, retrievedPassword);
        free(retrievedPassword);
    } else {
        printf("Password not found\n");
    }

    return 0;
}