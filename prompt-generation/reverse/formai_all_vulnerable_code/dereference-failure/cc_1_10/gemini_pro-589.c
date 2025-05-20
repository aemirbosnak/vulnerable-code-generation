//GEMINI-pro DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the structure of a password entry
typedef struct password_entry {
    char *website;
    char *username;
    char *password;
} password_entry;

// Define the maximum number of password entries
#define MAX_PASSWORD_ENTRIES 100

// Define the global array of password entries
password_entry password_entries[MAX_PASSWORD_ENTRIES];

// Define the current number of password entries
int num_password_entries = 0;

// Function to add a new password entry
void add_password_entry(char *website, char *username, char *password) {
    // Check if the array of password entries is full
    if (num_password_entries >= MAX_PASSWORD_ENTRIES) {
        printf("Error: The array of password entries is full.\n");
        return;
    }

    // Allocate memory for the new password entry
    password_entries[num_password_entries].website = malloc(strlen(website) + 1);
    password_entries[num_password_entries].username = malloc(strlen(username) + 1);
    password_entries[num_password_entries].password = malloc(strlen(password) + 1);

    // Copy the website, username, and password into the new password entry
    strcpy(password_entries[num_password_entries].website, website);
    strcpy(password_entries[num_password_entries].username, username);
    strcpy(password_entries[num_password_entries].password, password);

    // Increment the current number of password entries
    num_password_entries++;
}

// Function to find a password entry by website
password_entry *find_password_entry_by_website(char *website) {
    // Iterate over the array of password entries
    for (int i = 0; i < num_password_entries; i++) {
        // Check if the website matches the website of the current password entry
        if (strcmp(password_entries[i].website, website) == 0) {
            // Return the current password entry
            return &password_entries[i];
        }
    }

    // Return NULL if the website was not found
    return NULL;
}

// Function to print all password entries
void print_all_password_entries() {
    // Iterate over the array of password entries
    for (int i = 0; i < num_password_entries; i++) {
        // Print the website, username, and password of the current password entry
        printf("%s %s %s\n", password_entries[i].website, password_entries[i].username, password_entries[i].password);
    }
}

// Function to free the memory allocated for the password entries
void free_password_entries() {
    // Iterate over the array of password entries
    for (int i = 0; i < num_password_entries; i++) {
        // Free the memory allocated for the website, username, and password of the current password entry
        free(password_entries[i].website);
        free(password_entries[i].username);
        free(password_entries[i].password);
    }
}

// Main function
int main() {
    // Add some password entries to the array
    add_password_entry("www.google.com", "john.doe", "password123");
    add_password_entry("www.facebook.com", "jane.doe", "password456");
    add_password_entry("www.amazon.com", "jack.doe", "password789");

    // Print all password entries
    print_all_password_entries();

    // Find a password entry by website
    password_entry *password_entry = find_password_entry_by_website("www.google.com");

    // Print the website, username, and password of the found password entry
    printf("%s %s %s\n", password_entry->website, password_entry->username, password_entry->password);

    // Free the memory allocated for the password entries
    free_password_entries();

    return 0;
}