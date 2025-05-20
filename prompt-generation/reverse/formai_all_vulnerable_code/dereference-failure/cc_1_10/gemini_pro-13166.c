//GEMINI-pro DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password generation constants
#define PW_LEN 16
#define PW_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()"

// Password storage structure
typedef struct {
    char *site;
    char *username;
    char *password;
} PasswordEntry;

// Password management functions
PasswordEntry *generate_password(char *site, char *username);
void save_password(PasswordEntry *entry);
PasswordEntry *get_password(char *site, char *username);
void delete_password(char *site, char *username);

// Main function
int main() {
    // Generate a password for a website
    PasswordEntry *entry = generate_password("example.com", "username");

    // Save the password
    save_password(entry);

    // Get the password
    PasswordEntry *retrieved_entry = get_password("example.com", "username");

    // Print the password
    printf("Password: %s\n", retrieved_entry->password);

    // Delete the password
    delete_password("example.com", "username");

    return 0;
}

// Password generation function
PasswordEntry *generate_password(char *site, char *username) {
    // Allocate memory for the password entry
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));

    // Set the site and username
    entry->site = site;
    entry->username = username;

    // Generate a random password
    entry->password = malloc(PW_LEN + 1);
    for (int i = 0; i < PW_LEN; i++) {
        entry->password[i] = PW_CHARS[rand() % strlen(PW_CHARS)];
    }
    entry->password[PW_LEN] = '\0';

    // Return the password entry
    return entry;
}

// Password saving function
void save_password(PasswordEntry *entry) {
    // Open the password file
    FILE *fp = fopen("passwords.txt", "a");

    // Write the password entry to the file
    fprintf(fp, "%s,%s,%s\n", entry->site, entry->username, entry->password);

    // Close the password file
    fclose(fp);
}

// Password getting function
PasswordEntry *get_password(char *site, char *username) {
    // Open the password file
    FILE *fp = fopen("passwords.txt", "r");

    // Read the password file line by line
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the password entry
        char *site_str, *username_str, *password_str;
        site_str = strtok(line, ",");
        username_str = strtok(NULL, ",");
        password_str = strtok(NULL, "\n");

        // Check if the site and username match
        if (strcmp(site, site_str) == 0 && strcmp(username, username_str) == 0) {
            // Allocate memory for the password entry
            PasswordEntry *entry = malloc(sizeof(PasswordEntry));

            // Set the site, username, and password
            entry->site = site_str;
            entry->username = username_str;
            entry->password = password_str;

            // Return the password entry
            return entry;
        }
    }

    // Close the password file
    fclose(fp);

    // Return NULL if the password entry was not found
    return NULL;
}

// Password deleting function
void delete_password(char *site, char *username) {
    // Open the password file
    FILE *fp = fopen("passwords.txt", "r");

    // Read the password file line by line
    char line[256];
    FILE *fp_temp=fopen("temp.txt","w");
    while (fgets(line, sizeof(line), fp)) {
        // Parse the password entry
        char *site_str, *username_str, *password_str;
        site_str = strtok(line, ",");
        username_str = strtok(NULL, ",");
        password_str = strtok(NULL, "\n");

        // Check if the site and username match
        if (strcmp(site, site_str) == 0 && strcmp(username, username_str) == 0) {
            // Skip writing this line to the temp file
            continue;
        }
        fprintf(fp_temp,"%s,%s,%s\n",site_str,username_str,password_str);
    }

    // Close the password file
    fclose(fp);
    fclose(fp_temp);
    remove("passwords.txt");
    rename("temp.txt","passwords.txt");
}