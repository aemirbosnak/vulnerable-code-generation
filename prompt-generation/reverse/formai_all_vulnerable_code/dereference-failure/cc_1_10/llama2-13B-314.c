//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: visionary
// The Great Library of Passwords

// A mystical tome, guarded by the ancient dragon of wisdom

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_CHARS 20

// Structure to store passwords
typedef struct {
    char *name;
    char *password;
} password_t;

// Array to store passwords
password_t passwords[MAX_PASSWORDS];

// Function to add a password to the array
void add_password(char *name, char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) != 0) {
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("The Great Library of Passwords is full. Please delete some passwords before adding more.\n");
        return;
    }
    passwords[i].name = name;
    passwords[i].password = password;
}

// Function to retrieve a password
char *get_password(char *name) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            return passwords[i].password;
        }
    }
    return NULL;
}

// Function to delete a password
void delete_password(char *name) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("The Great Library of Passwords does not contain the password you are trying to delete.\n");
        return;
    }
    memset(passwords[i].name, 0, strlen(passwords[i].name));
    memset(passwords[i].password, 0, strlen(passwords[i].password));
    passwords[i].name = NULL;
    passwords[i].password = NULL;
}

int main() {
    // Add some passwords
    add_password("Alice", "secret123");
    add_password("Bob", "password101");
    add_password("Charlie", "letmein");

    // Retrieve a password
    char *password = get_password("Alice");
    if (password) {
        printf("Alice's password is: %s\n", password);
    } else {
        printf("Alice does not have a password.\n");
    }

    // Delete a password
    delete_password("Bob");

    return 0;
}