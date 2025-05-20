//GEMINI-pro DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a password.
#define MAX_PASSWORD_LENGTH 256

// Define the number of password slots in the array.
#define NUM_PASSWORD_SLOTS 10

// Define the structure of a password slot.
typedef struct {
    char *name;
    char *password;
} password_slot;

// Define the array of password slots.
password_slot password_slots[NUM_PASSWORD_SLOTS];

// Define the function to add a new password to the array.
void add_password(char *name, char *password) {
    // Find an empty slot in the array.
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (password_slots[i].name == NULL) {
            break;
        }
    }

    // If there is no empty slot, return an error.
    if (i == NUM_PASSWORD_SLOTS) {
        printf("Error: No more slots available.\n");
        return;
    }

    // Allocate memory for the name and password.
    password_slots[i].name = malloc(strlen(name) + 1);
    password_slots[i].password = malloc(strlen(password) + 1);

    // Copy the name and password into the slot.
    strcpy(password_slots[i].name, name);
    strcpy(password_slots[i].password, password);
}

// Define the function to get a password from the array.
char *get_password(char *name) {
    // Find the slot with the given name.
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (strcmp(password_slots[i].name, name) == 0) {
            break;
        }
    }

    // If the slot is not found, return NULL.
    if (i == NUM_PASSWORD_SLOTS) {
        return NULL;
    }

    // Return the password from the slot.
    return password_slots[i].password;
}

// Define the function to delete a password from the array.
void delete_password(char *name) {
    // Find the slot with the given name.
    int i;
    for (i = 0; i < NUM_PASSWORD_SLOTS; i++) {
        if (strcmp(password_slots[i].name, name) == 0) {
            break;
        }
    }

    // If the slot is not found, return.
    if (i == NUM_PASSWORD_SLOTS) {
        return;
    }

    // Free the memory allocated for the name and password.
    free(password_slots[i].name);
    free(password_slots[i].password);

    // Set the slot to NULL.
    password_slots[i].name = NULL;
    password_slots[i].password = NULL;
}

// Define the main function.
int main() {
    // Add some passwords to the array.
    add_password("Google", "password123");
    add_password("Facebook", "password456");
    add_password("Amazon", "password789");

    // Get a password from the array.
    char *password = get_password("Amazon");

    // Print the password.
    printf("Password: %s\n", password);

    // Delete a password from the array.
    delete_password("Facebook");

    return 0;
}