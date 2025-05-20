//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: lively
// PwdMng - The Ultimate Password Manager! 🔒🔓

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LEN 32

// Structure to store passwords
typedef struct {
    char *username;
    char *password;
    time_t last_used;
} password_t;

// Global variables
password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

// Function to add a new password
void add_password(char *username, char *password) {
    password_t *new_password = (password_t *)malloc(sizeof(password_t));
    new_password->username = username;
    new_password->password = password;
    new_password->last_used = time(NULL);
    passwords[num_passwords] = *new_password;
    num_passwords++;
}

// Function to retrieve a password
char *get_password(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return passwords[i].password;
        }
    }
    return NULL;
}

// Function to check if a password is valid
int is_password_valid(char *username, char *password) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0 &&
                strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to update the last_used time of a password
void update_last_used(char *username) {
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            passwords[i].last_used = time(NULL);
            break;
        }
    }
}

// Main function
int main() {
    // Add some passwords
    add_password("user1", "password1");
    add_password("user2", "password2");
    add_password("user3", "password3");

    // Retrieve a password
    char *password = get_password("user1");
    if (password != NULL) {
        printf("Retrieved password: %s\n", password);
    } else {
        printf("Password not found\n");
    }

    // Check if a password is valid
    int valid = is_password_valid("user1", "password1");
    if (valid) {
        printf("Password is valid\n");
    } else {
        printf("Password is invalid\n");
    }

    // Update the last_used time of a password
    update_last_used("user1");

    return 0;
}