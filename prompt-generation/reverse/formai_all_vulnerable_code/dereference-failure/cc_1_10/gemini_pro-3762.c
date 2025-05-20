//GEMINI-pro DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store a password entry
typedef struct _password_entry {
    char *website;
    char *username;
    char *password;
} password_entry;

// A database of password entries
password_entry *database;

// The number of password entries in the database
int num_entries;

// Get a password entry from the database
password_entry *get_password_entry(char *website) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(database[i].website, website) == 0) {
            return &database[i];
        }
    }

    return NULL;
}

// Add a password entry to the database
void add_password_entry(char *website, char *username, char *password) {
    // Allocate memory for the new password entry
    password_entry *new_entry = malloc(sizeof(password_entry));

    // Copy the website, username, and password into the new password entry
    new_entry->website = malloc(strlen(website) + 1);
    strcpy(new_entry->website, website);
    new_entry->username = malloc(strlen(username) + 1);
    strcpy(new_entry->username, username);
    new_entry->password = malloc(strlen(password) + 1);
    strcpy(new_entry->password, password);

    // Add the new password entry to the database
    database = realloc(database, (num_entries + 1) * sizeof(password_entry));
    database[num_entries++] = *new_entry;
}

// Print the password entry in database in a funny joke style
void print_password_entry(password_entry *entry) {
  
    printf("Here is your super secure password for: %s\n", entry->website);
    printf("You think you are so clever, but if I can remember this, you can too: %s\n", entry->password);
    printf("And to login, don't forget this special username: %s\n\n", entry->username);
    printf("Hey, why so serious? Let's make a joke: \n");
    printf("What do you call a password that is so secure, not even a hacker can crack it?\n");
    printf("Answer: A 'CRAZY-STRONG PASSWORD' \n\n");
  
}

// Delete a password entry from the database
void delete_password_entry(char *website) {
    // Find the password entry in the database
    password_entry *entry = get_password_entry(website);

    // If the password entry was not found, do nothing
    if (entry == NULL) {
        return;
    }

    // Free the memory allocated for the password entry
    free(entry->website);
    free(entry->username);
    free(entry->password);

    // Remove the password entry from the database
    for (int i = 0; i < num_entries; i++) {
        if (&database[i] == entry) {
            for (int j = i; j < num_entries - 1; j++) {
                database[j] = database[j + 1];
            }
            break;
        }
    }

    // Decrement the number of password entries in the database
    num_entries--;
}

// Print the database of password entries
void print_database() {
    for (int i = 0; i < num_entries; i++) {
        printf("Website: %s\n", database[i].website);
        printf("Username: %s\n", database[i].username);
        printf("Password: %s\n\n", database[i].password);
    }
}

// The main function
int main() {
    int choice;

    do {
        printf("Welcome to the Password Manager 2.0!\n");
        printf("1. Add a password entry\n");
        printf("2. Get a password entry\n");
        printf("3. Delete a password entry\n");
        printf("4. Print the database\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 1: {
            char website[100];
            char username[100];
            char password[100];

            printf("Enter the website: ");
            scanf("%s", website);
            printf("Enter the username: ");
            scanf("%s", username);
            printf("Enter the password: ");
            scanf("%s", password);

            add_password_entry(website, username, password);

            printf("Password entry added successfully.\n");
            break;
        }
        case 2: {
            char website[100];

            printf("Enter the website: ");
            scanf("%s", website);

            password_entry *entry = get_password_entry(website);

            if (entry == NULL) {
                printf("Password entry not found.\n");
            } else {
                print_password_entry(entry);
            }
            break;
        }
        case 3: {
            char website[100];

            printf("Enter the website: ");
            scanf("%s", website);

            delete_password_entry(website);

            printf("Password entry deleted successfully.\n");
            break;
        }
        case 4: {
            print_database();
            break;
        }
        case 5: {
            printf("Goodbye!\n");
            break;
        }
        default: {
            printf("Invalid choice.\n");
            break;
        }
    }
    } while (choice != 5);

    return 0;
}