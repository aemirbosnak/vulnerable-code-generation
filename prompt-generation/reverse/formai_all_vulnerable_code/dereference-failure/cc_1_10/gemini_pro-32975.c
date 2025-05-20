//GEMINI-pro DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database of passwords
struct Password {
    char *name;
    char *password;
};
struct Password passwords[100];
int numPasswords = 0;

// Function to add a password to the database
void addPassword(char *name, char *password) {
    passwords[numPasswords].name = malloc(strlen(name) + 1);
    strcpy(passwords[numPasswords].name, name);
    passwords[numPasswords].password = malloc(strlen(password) + 1);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

// Function to find a password in the database
char *findPassword(char *name) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return passwords[i].password;
        }
    }
    return NULL;
}

// Function to print the database of passwords
void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

// Main function
int main() {
    // Add some sample passwords to the database
    addPassword("alice", "password1");
    addPassword("bob", "password2");
    addPassword("charlie", "password3");

    // Print the database of passwords
    printPasswords();

    // Find a password in the database
    char *foundPassword = findPassword("bob");
    if (foundPassword != NULL) {
        printf("Found password for bob: %s\n", foundPassword);
    } else {
        printf("Password for bob not found\n");
    }

    return 0;
}