//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <stdint.h>
#include <stdlib.h>

#define PASSWORD_FILE "passwords.dat"
#define MAX_PASSWORDS 10

// Structure to store password information
struct password {
    char *username;
    char *password;
};

// Function to store password in file
void store_password(struct password *passwords, int num_passwords, const char *username, const char *password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    if (i == num_passwords) {
        // Username not found, add new password
        passwords[i].username = username;
        passwords[i].password = password;
        num_passwords++;
    }

    // Save passwords to file
    FILE *file = fopen(PASSWORD_FILE, "w");
    for (i = 0; i < num_passwords; i++) {
        fprintf(file, "%s:%s\n", passwords[i].username, passwords[i].password);
    }
    fclose(file);
}

// Function to retrieve password from file
struct password *retrieve_password(const char *username) {
    int i;
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    // Read passwords from file
    FILE *file = fopen(PASSWORD_FILE, "r");
    for (i = 0; i < MAX_PASSWORDS; i++) {
        char line[1024];
        fgets(line, 1024, file);
        if (strchr(line, ':') == NULL) {
            continue;
        }
        char *username = strtok(line, ":");
        char *password = strtok(NULL, ":");
        passwords[num_passwords].username = username;
        passwords[num_passwords].password = password;
        num_passwords++;
    }
    fclose(file);

    // Find matching password
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            return &passwords[i];
        }
    }

    // Return NULL if no matching password found
    return NULL;
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    // Store password example
    store_password(passwords, num_passwords, "user1", "password1");
    store_password(passwords, num_passwords, "user2", "password2");

    // Retrieve password example
    struct password *password = retrieve_password("user1");
    if (password == NULL) {
        printf("Password not found\n");
    } else {
        printf("Password found: %s\n", password->password);
    }

    return 0;
}