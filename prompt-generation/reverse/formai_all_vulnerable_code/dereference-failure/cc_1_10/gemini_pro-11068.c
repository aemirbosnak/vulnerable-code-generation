//GEMINI-pro DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 50

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password entry
typedef struct password_entry {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Define the global array of password entries
password_entry passwords[NUM_PASSWORDS];

// Define the global counter for the number of password entries
int num_passwords = 0;

// Declare the functions used in the program
void add_password(char *username, char *password);
void delete_password(char *username);
void change_password(char *username, char *new_password);
void list_passwords();

// Define the main function
int main(int argc, char **argv) {
    // Check if the user has provided enough arguments
    if (argc < 2) {
        printf("Usage: %s <command> <args>\n", argv[0]);
        return 1;
    }

    // Get the command from the user
    char *command = argv[1];

    // Parse the command
    if (strcmp(command, "add") == 0) {
        // Check if the user has provided enough arguments
        if (argc < 4) {
            printf("Usage: %s add <username> <password>\n", argv[0]);
            return 1;
        }

        // Get the username and password from the user
        char *username = argv[2];
        char *password = argv[3];

        // Add the password to the array
        add_password(username, password);
    } else if (strcmp(command, "delete") == 0) {
        // Check if the user has provided enough arguments
        if (argc < 3) {
            printf("Usage: %s delete <username>\n", argv[0]);
            return 1;
        }

        // Get the username from the user
        char *username = argv[2];

        // Delete the password from the array
        delete_password(username);
    } else if (strcmp(command, "change") == 0) {
        // Check if the user has provided enough arguments
        if (argc < 4) {
            printf("Usage: %s change <username> <new_password>\n", argv[0]);
            return 1;
        }

        // Get the username and new password from the user
        char *username = argv[2];
        char *new_password = argv[3];

        // Change the password in the array
        change_password(username, new_password);
    } else if (strcmp(command, "list") == 0) {
        // List the passwords in the array
        list_passwords();
    } else {
        // Print an error message
        printf("Invalid command: %s\n", command);
        return 1;
    }

    return 0;
}

// Define the function to add a password to the array
void add_password(char *username, char *password) {
    // Check if the array is full
    if (num_passwords == NUM_PASSWORDS) {
        printf("Error: The password array is full.\n");
        return;
    }

    // Copy the username and password to the array
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    // Increment the counter for the number of password entries
    num_passwords++;
}

// Define the function to delete a password from the array
void delete_password(char *username) {
    // Find the password entry in the array
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // Check if the password entry was found
    if (i == num_passwords) {
        printf("Error: Password entry not found.\n");
        return;
    }

    // Shift the passwords down in the array
    for (i = i + 1; i < num_passwords; i++) {
        passwords[i - 1] = passwords[i];
    }

    // Decrement the counter for the number of password entries
    num_passwords--;
}

// Define the function to change a password in the array
void change_password(char *username, char *new_password) {
    // Find the password entry in the array
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    // Check if the password entry was found
    if (i == num_passwords) {
        printf("Error: Password entry not found.\n");
        return;
    }

    // Copy the new password to the array
    strcpy(passwords[i].password, new_password);
}

// Define the function to list the passwords in the array
void list_passwords() {
    // Print the passwords in the array
    int i;
    for (i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}