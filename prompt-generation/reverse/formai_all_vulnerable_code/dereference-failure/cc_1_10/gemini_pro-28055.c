//GEMINI-pro DATASET v1.0 Category: Password management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of passwords to store
#define NUM_PASSWORDS 10

// Define the structure of a password entry
typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_entry;

// Define the array of password entries
password_entry passwords[NUM_PASSWORDS];

// Define the current number of password entries
int num_passwords = 0;

// Function to add a new password entry
void add_password(char *username, char *password) {
    // Check if the array of password entries is full
    if (num_passwords == NUM_PASSWORDS) {
        printf("Error: The array of password entries is full.\n");
        return;
    }

    // Copy the username and password into the new entry
    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    // Increment the current number of password entries
    num_passwords++;
}

// Function to find a password entry by username
password_entry *find_password(char *username) {
    // Iterate over the array of password entries
    for (int i = 0; i < num_passwords; i++) {
        // Check if the username matches the given username
        if (strcmp(passwords[i].username, username) == 0) {
            // Return the password entry
            return &passwords[i];
        }
    }

    // Return NULL if the username was not found
    return NULL;
}

// Function to print all password entries
void print_passwords() {
    // Iterate over the array of password entries
    for (int i = 0; i < num_passwords; i++) {
        // Print the username and password
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

// Function to get a password from the user
char *get_password() {
    // Allocate memory for the password
    char *password = (char *)malloc(MAX_PASSWORD_LENGTH);

    // Prompt the user for the password
    printf("Enter your password: ");

    // Read the password from the user
    scanf("%s", password);

    // Return the password
    return password;
}

// Function to generate a random password
char *generate_password() {
    // Define the characters that can be used in the password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    // Allocate memory for the password
    char *password = (char *)malloc(MAX_PASSWORD_LENGTH);

    // Generate a random password
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }

    // Return the password
    return password;
}

// Function to main
int main() {
    // Add some sample password entries
    add_password("user1", "password1");
    add_password("user2", "password2");
    add_password("user3", "password3");

    // Print all password entries
    print_passwords();

    // Find a password entry by username
    password_entry *password_entry = find_password("user2");

    // Print the username and password
    printf("%s: %s\n", password_entry->username, password_entry->password);

    // Get a password from the user
    char *password = get_password();

    // Generate a random password
    char *random_password = generate_password();

    // Print the password
    printf("Your new password is: %s\n", random_password);

    // Free the memory allocated for the password
    free(password);
    free(random_password);

    return 0;
}