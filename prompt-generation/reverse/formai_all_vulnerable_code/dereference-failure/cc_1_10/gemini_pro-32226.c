//GEMINI-pro DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

// Define the structure of a password entry
typedef struct {
    char *username;
    char *password;
    char *website;
} PasswordEntry;

// Create a new password entry
PasswordEntry *createPasswordEntry(char *username, char *password, char *website) {
    PasswordEntry *entry = malloc(sizeof(PasswordEntry));
    entry->username = strdup(username);
    entry->password = strdup(password);
    entry->website = strdup(website);
    return entry;
}

// Free the memory allocated for a password entry
void freePasswordEntry(PasswordEntry *entry) {
    free(entry->username);
    free(entry->password);
    free(entry->website);
    free(entry);
}

// Add a new password entry to the list of entries
void addPasswordEntry(PasswordEntry **entries, int *numEntries, PasswordEntry *entry) {
    *entries = realloc(*entries, (*numEntries + 1) * sizeof(PasswordEntry));
    (*entries)[*numEntries] = *entry;
    (*numEntries)++;
}

// Find a password entry by username and website
PasswordEntry *findPasswordEntry(PasswordEntry *entries, int numEntries, char *username, char *website) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].username, username) == 0 && strcmp(entries[i].website, website) == 0) {
            return &entries[i];
        }
    }
    return NULL;
}

// Print all password entries
void printPasswordEntries(PasswordEntry *entries, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("Username: %s\n", entries[i].username);
        printf("Password: %s\n", entries[i].password);
        printf("Website: %s\n\n", entries[i].website);
    }
}

// Get the current user's home directory
char *getHomeDirectory() {
    struct passwd *pw = getpwuid(getuid());
    return pw->pw_dir;
}

// Save password entries to a file
void savePasswordEntries(PasswordEntry *entries, int numEntries) {
    char *homeDirectory = getHomeDirectory();
    char *filePath = malloc(strlen(homeDirectory) + strlen("/.password-manager") + 1);
    strcpy(filePath, homeDirectory);
    strcat(filePath, "/.password-manager");
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%s:%s:%s\n", entries[i].username, entries[i].password, entries[i].website);
    }
    fclose(file);
    free(filePath);
}

// Load password entries from a file
void loadPasswordEntries(PasswordEntry **entries, int *numEntries) {
    char *homeDirectory = getHomeDirectory();
    char *filePath = malloc(strlen(homeDirectory) + strlen("/.password-manager") + 1);
    strcpy(filePath, homeDirectory);
    strcat(filePath, "/.password-manager");
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *username = strtok(line, ":");
        char *password = strtok(NULL, ":");
        char *website = strtok(NULL, "\n");
        PasswordEntry *entry = createPasswordEntry(username, password, website);
        addPasswordEntry(entries, numEntries, entry);
    }
    fclose(file);
    free(filePath);
}

// Main function
int main() {
    // Initialize the list of password entries
    PasswordEntry *entries = NULL;
    int numEntries = 0;

    // Load password entries from a file
    loadPasswordEntries(&entries, &numEntries);

    // Add a new password entry
    PasswordEntry *entry = createPasswordEntry("username", "password", "website");
    addPasswordEntry(&entries, &numEntries, entry);

    // Find a password entry by username and website
    PasswordEntry *foundEntry = findPasswordEntry(entries, numEntries, "username", "website");
    if (foundEntry != NULL) {
        printf("Found password entry for username %s and website %s\n", foundEntry->username, foundEntry->website);
    } else {
        printf("Password entry not found\n");
    }

    // Print all password entries
    printPasswordEntries(entries, numEntries);

    // Save password entries to a file
    savePasswordEntries(entries, numEntries);

    // Free the memory allocated for the password entries
    for (int i = 0; i < numEntries; i++) {
        freePasswordEntry(&entries[i]);
    }
    free(entries);

    return 0;
}