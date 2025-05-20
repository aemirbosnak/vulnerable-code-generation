//GEMINI-pro DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

// Global variables
PasswordEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char *name, char *password);
void deleteEntry(char *name);
void listEntries();
void searchEntry(char *name);

int main() {
    // Initialize the program
    printf("Welcome to the Cybernetic Password Manager 2.0!\n");
    printf("Enter 'help' for a list of commands.\n\n");

    // Main loop
    while (1) {
        // Get the user's input
        printf("> ");
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Parse the input
        char *command = strtok(input, " ");
        char *args = strtok(NULL, "\n");

        // Execute the command
        if (strcmp(command, "add") == 0) {
            // Add a new password entry
            if (numEntries < MAX_ENTRIES) {
                addEntry(args, strtok(NULL, "\n"));
                printf("Entry added successfully.\n");
            } else {
                printf("Error: Password manager is full.\n");
            }
        } else if (strcmp(command, "delete") == 0) {
            // Delete a password entry
            deleteEntry(args);
            printf("Entry deleted successfully.\n");
        } else if (strcmp(command, "list") == 0) {
            // List all password entries
            listEntries();
        } else if (strcmp(command, "search") == 0) {
            // Search for a password entry
            searchEntry(args);
        } else if (strcmp(command, "help") == 0) {
            // Display help information
            printf("Commands:\n");
            printf("  add <name> <password> - Add a new password entry\n");
            printf("  delete <name> - Delete a password entry\n");
            printf("  list - List all password entries\n");
            printf("  search <name> - Search for a password entry\n");
            printf("  help - Display this help information\n");
            printf("  exit - Exit the program\n");
        } else if (strcmp(command, "exit") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            break;
        } else {
            // Invalid command
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}

void addEntry(char *name, char *password) {
    // Create a new password entry
    PasswordEntry entry;
    strcpy(entry.name, name);
    strcpy(entry.password, password);

    // Add the entry to the array
    entries[numEntries] = entry;
    numEntries++;
}

void deleteEntry(char *name) {
    // Find the entry to delete
    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the entry was found, delete it
    if (index != -1) {
        for (int i = index; i < numEntries - 1; i++) {
            entries[i] = entries[i + 1];
        }
        numEntries--;
    } else {
        printf("Error: Entry not found.\n");
    }
}

void listEntries() {
    // Print the list of entries
    printf("Password Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("  %s: %s\n", entries[i].name, entries[i].password);
    }
}

void searchEntry(char *name) {
    // Find the entry
    int index = -1;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // If the entry was found, print it
    if (index != -1) {
        printf("Entry found:\n  %s: %s\n", entries[index].name, entries[index].password);
    } else {
        printf("Error: Entry not found.\n");
    }
}