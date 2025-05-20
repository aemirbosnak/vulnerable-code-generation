//GEMINI-pro DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Data structure to represent a password entry
typedef struct {
    char *username;
    char *password;
    char *website;
} PasswordEntry;

// Function to create a new password entry
PasswordEntry *createPasswordEntry(char *username, char *password, char *website) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->username = strdup(username);
    entry->password = strdup(password);
    entry->website = strdup(website);
    return entry;
}

// Function to free a password entry
void freePasswordEntry(PasswordEntry *entry) {
    free(entry->username);
    free(entry->password);
    free(entry->website);
    free(entry);
}

// Function to print a password entry
void printPasswordEntry(PasswordEntry *entry) {
    printf("Username: %s\n", entry->username);
    printf("Password: %s\n", entry->password);
    printf("Website: %s\n", entry->website);
}

// Function to hash a password using SHA-256
char *hashPassword(char *password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Final(hash, &sha256);
    char *hashedPassword = malloc(SHA256_DIGEST_LENGTH * 2 + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashedPassword + i * 2, "%02x", hash[i]);
    }
    return hashedPassword;
}

// Function to add a new password entry to the database
void addPasswordEntry(PasswordEntry *entry) {
    // Open the password database file
    FILE *fp = fopen("passwords.txt", "a");
    if (fp == NULL) {
        perror("Error opening password database file");
        exit(EXIT_FAILURE);
    }

    // Write the password entry to the file
    fprintf(fp, "%s,%s,%s\n", entry->username, entry->password, entry->website);

    // Close the password database file
    fclose(fp);
}

// Function to get a password entry from the database
PasswordEntry *getPasswordEntry(char *username, char *website) {
    // Open the password database file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        perror("Error opening password database file");
        exit(EXIT_FAILURE);
    }

    // Read the password entries from the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the password entry
        char *username, *password, *website;
        username = strtok(line, ",");
        password = strtok(NULL, ",");
        website = strtok(NULL, "\n");

        // Check if the username and website match
        if (strcmp(username, username) == 0 && strcmp(website, website) == 0) {
            // Create a new password entry
            PasswordEntry *entry = createPasswordEntry(username, password, website);

            // Close the password database file
            fclose(fp);

            // Return the password entry
            return entry;
        }
    }

    // Close the password database file
    fclose(fp);

    // Return NULL if the password entry was not found
    return NULL;
}

// Function to update a password entry in the database
void updatePasswordEntry(PasswordEntry *entry) {
    // Open the password database file
    FILE *fp = fopen("passwords.txt", "r+");
    if (fp == NULL) {
        perror("Error opening password database file");
        exit(EXIT_FAILURE);
    }

    // Read the password entries from the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the password entry
        char *username, *password, *website;
        username = strtok(line, ",");
        password = strtok(NULL, ",");
        website = strtok(NULL, "\n");

        // Check if the username and website match
        if (strcmp(username, entry->username) == 0 && strcmp(website, entry->website) == 0) {
            // Update the password entry
            fseek(fp, -1, SEEK_CUR);
            fprintf(fp, "%s,%s,%s\n", entry->username, entry->password, entry->website);
            break;
        }
    }

    // Close the password database file
    fclose(fp);
}

//
int main() {
    // Create a new password entry
    PasswordEntry *entry = createPasswordEntry("johndoe", "password123", "example.com");

    // Add the password entry to the database
    addPasswordEntry(entry);

    // Get the password entry from the database
    PasswordEntry *entry2 = getPasswordEntry("johndoe", "example.com");

    // Print the password entry
    printPasswordEntry(entry2);

    // Update the password entry
    entry2->password = "newPassword123";
    updatePasswordEntry(entry2);

    // Free the password entries
    freePasswordEntry(entry);
    freePasswordEntry(entry2);

    return 0;
}