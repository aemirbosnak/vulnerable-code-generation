//GEMINI-pro DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store a password entry
typedef struct password_entry {
    char username[50];
    char password[50];
    char website[50];
} password_entry;

// Function to create a new password entry
password_entry* create_password_entry(char *username, char *password, char *website) {
    password_entry *entry = (password_entry*)malloc(sizeof(password_entry));
    strcpy(entry->username, username);
    strcpy(entry->password, password);
    strcpy(entry->website, website);
    return entry;
}

// Function to add a new password entry to the database
void add_password_entry(password_entry *entry) {
    // Open the database file
    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    // Write the entry to the database file
    fprintf(fp, "%s,%s,%s\n", entry->username, entry->password, entry->website);

    // Close the database file
    fclose(fp);
}

// Function to search for a password entry in the database
password_entry* search_password_entry(char *username, char *website) {
    // Open the database file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening the database file.\n");
        return NULL;
    }

    // Read the entries from the database file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into username, password, and website
        char *parts[3];
        int i = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            parts[i++] = token;
            token = strtok(NULL, ",");
        }

        // Check if the username and website match the search criteria
        if (strcmp(parts[0], username) == 0 && strcmp(parts[2], website) == 0) {
            // Create a new password entry and return it
            password_entry *entry = create_password_entry(parts[0], parts[1], parts[2]);
            return entry;
        }
    }

    // Close the database file
    fclose(fp);

    // Return NULL if the entry was not found
    return NULL;
}

// Function to delete a password entry from the database
void delete_password_entry(char *username, char *website) {
    // Open the database file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    // Create a temporary file to store the new entries
    FILE *fp_temp = fopen("passwords.txt.temp", "w");
    if (fp_temp == NULL) {
        printf("Error creating the temporary file.\n");
        return;
    }

    // Read the entries from the database file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into username, password, and website
        char *parts[3];
        int i = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            parts[i++] = token;
            token = strtok(NULL, ",");
        }

        // Check if the username and website match the search criteria
        if (strcmp(parts[0], username) != 0 || strcmp(parts[2], website) != 0) {
            // Write the entry to the temporary file
            fprintf(fp_temp, "%s,%s,%s\n", parts[0], parts[1], parts[2]);
        }
    }

    // Close the database file and the temporary file
    fclose(fp);
    fclose(fp_temp);

    // Delete the database file and rename the temporary file to the database file
    remove("passwords.txt");
    rename("passwords.txt.temp", "passwords.txt");
}

// Function to print all password entries in the database
void print_password_entries() {
    // Open the database file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening the database file.\n");
        return;
    }

    // Read the entries from the database file
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split the line into username, password, and website
        char *parts[3];
        int i = 0;
        char *token = strtok(line, ",");
        while (token != NULL) {
            parts[i++] = token;
            token = strtok(NULL, ",");
        }

        // Print the entry
        printf("%s,%s,%s\n", parts[0], parts[1], parts[2]);
    }

    // Close the database file
    fclose(fp);
}

// Main function
int main() {
    // Create a new password entry
    password_entry *entry = create_password_entry("john", "password123", "example.com");

    // Add the entry to the database
    add_password_entry(entry);

    // Search for the entry in the database
    password_entry *found_entry = search_password_entry("john", "example.com");
    if (found_entry != NULL) {
        printf("Found entry: %s,%s,%s\n", found_entry->username, found_entry->password, found_entry->website);
    } else {
        printf("Entry not found.\n");
    }

    // Delete the entry from the database
    delete_password_entry("john", "example.com");

    // Print all entries in the database
    print_password_entries();

    return 0;
}