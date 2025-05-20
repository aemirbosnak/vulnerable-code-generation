//GEMINI-pro DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 20

// Define the number of password slots
#define NUM_PASSWORD_SLOTS 10

// Define the structure of a password slot
typedef struct {
    char *password;
    char *username;
} password_slot;

// Define the array of password slots
password_slot password_slots[NUM_PASSWORD_SLOTS];

// Define the function to add a password to the array
void add_password(char *username, char *password) {
    // Find an empty slot in the array
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (password_slots[i].password == NULL) {
            break;
        }
    }

    // If there is no empty slot, return an error
    if (i == NUM_PASSWORD_SLOTS) {
        printf("Error: No empty password slot available.\n");
        return;
    }

    // Allocate memory for the password and username
    password_slots[i].password = malloc(MAX_PASSWORD_LENGTH + 1);
    password_slots[i].username = malloc(MAX_PASSWORD_LENGTH + 1);

    // Copy the password and username into the slot
    strcpy(password_slots[i].password, password);
    strcpy(password_slots[i].username, username);
}

// Define the function to get a password from the array
char *get_password(char *username) {
    // Find the slot with the given username
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (strcmp(password_slots[i].username, username) == 0) {
            break;
        }
    }

    // If the slot is not found, return an error
    if (i == NUM_PASSWORD_SLOTS) {
        printf("Error: Username not found.\n");
        return NULL;
    }

    // Return the password
    return password_slots[i].password;
}

// Define the function to delete a password from the array
void delete_password(char *username) {
    // Find the slot with the given username
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (strcmp(password_slots[i].username, username) == 0) {
            break;
        }
    }

    // If the slot is not found, return an error
    if (i == NUM_PASSWORD_SLOTS) {
        printf("Error: Username not found.\n");
        return;
    }

    // Free the memory for the password and username
    free(password_slots[i].password);
    free(password_slots[i].username);

    // Set the slot to NULL
    password_slots[i].password = NULL;
    password_slots[i].username = NULL;
}

// Define the main function
int main() {
    // Add some passwords to the array
    add_password("Romeo", "password1");
    add_password("Juliet", "password2");

    // Get a password from the array
    char *password = get_password("Romeo");

    // Print the password
    printf("Password: %s\n", password);

    // Delete a password from the array
    delete_password("Romeo");

    // Get a password from the array
    password = get_password("Romeo");

    // If the password is NULL, the username was not found
    if (password == NULL) {
        printf("Username not found.\n");
    } else {
        printf("Password: %s\n", password);
    }

    return 0;
}