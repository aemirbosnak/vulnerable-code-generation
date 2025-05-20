//Falcon2-11B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of passwords to store
#define MAX_PASSWORDS 10

// Define a structure to hold password information
typedef struct {
    char *user;
    char *password;
} Password;

// Define a function to add a password to the list
void add_password(Password *passwords, int num_passwords, char *user, char *password) {
    if (num_passwords == MAX_PASSWORDS) {
        printf("Password list is full, cannot add more passwords.\n");
        return;
    }

    Password new_pass;
    strcpy(new_pass.user, user);
    strcpy(new_pass.password, password);
    passwords[num_passwords++] = new_pass;
}

// Define a function to display the password list
void display_passwords(Password *passwords, int num_passwords) {
    for (int i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].user);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

// Define a function to remove a password from the list
void remove_password(Password *passwords, int num_passwords, char *user) {
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].user, user) == 0) {
            for (int j = i; j < num_passwords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }
            num_passwords--;
            return;
        }
    }

    printf("Password not found, cannot remove.\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    // Add some passwords
    add_password(passwords, num_passwords, "user1", "password1");
    add_password(passwords, num_passwords, "user2", "password2");
    add_password(passwords, num_passwords, "user3", "password3");

    // Display the password list
    printf("Password list:\n");
    display_passwords(passwords, num_passwords);

    // Remove a password
    remove_password(passwords, num_passwords, "user2");

    // Display the password list again
    printf("\nPassword list after removal:\n");
    display_passwords(passwords, num_passwords);

    return 0;
}