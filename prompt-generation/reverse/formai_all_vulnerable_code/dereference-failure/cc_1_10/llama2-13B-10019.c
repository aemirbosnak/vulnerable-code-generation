//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define MAX_USERS 10

// Global variables
char *passwords[MAX_USERS];
int numUsers;

void initPasswordStorage();
void addPassword(char *password);
void removePassword(int index);
char *getPassword(int index);
void printPasswordList();

int main() {
    initPasswordStorage();

    // Add some passwords
    addPassword("Hello123");
    addPassword("World456");
    addPassword("Pass789");

    // Print the password list
    printPasswordList();

    // Remove a password
    removePassword(1);

    // Print the updated password list
    printPasswordList();

    return 0;
}

// Function to initialize the password storage
void initPasswordStorage() {
    numUsers = 0;
    passwords[0] = NULL;
}

// Function to add a password
void addPassword(char *password) {
    if (numUsers == MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    passwords[numUsers] = malloc(strlen(password) + 1);
    strcpy(passwords[numUsers], password);
    numUsers++;
}

// Function to remove a password
void removePassword(int index) {
    if (index < 0 || index >= numUsers) {
        printf("Error: Invalid index.\n");
        return;
    }

    free(passwords[index]);
    passwords[index] = NULL;
    numUsers--;
}

// Function to get a password
char *getPassword(int index) {
    if (index < 0 || index >= numUsers) {
        printf("Error: Invalid index.\n");
        return NULL;
    }

    return passwords[index];
}

// Function to print the password list
void printPasswordList() {
    int i;
    for (i = 0; i < numUsers; i++) {
        printf("%d. %s\n", i + 1, passwords[i]);
    }
}