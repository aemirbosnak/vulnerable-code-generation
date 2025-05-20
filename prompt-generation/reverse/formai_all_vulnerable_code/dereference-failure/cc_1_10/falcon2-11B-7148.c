//Falcon2-11B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 8

// Global variables
char* generatedPassword = NULL;
char* storedPassword = NULL;

// Function to generate a random password
char* generatePassword() {
    // Create a buffer to store the password
    char* password = (char*) malloc(PASSWORD_LENGTH * sizeof(char));
    
    // Set the password to all lowercase letters
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }
    
    // Shuffle the characters in the password
    for (i = PASSWORD_LENGTH - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    return password;
}

// Function to store a password in the database
void storePassword(char* password) {
    if (generatedPassword == NULL) {
        generatedPassword = password;
    } else {
        storedPassword = password;
    }
}

// Function to retrieve a stored password
char* retrievePassword() {
    if (generatedPassword == NULL) {
        return storedPassword;
    } else {
        return generatedPassword;
    }
}

// Function to update a stored password
void updatePassword(char* newPassword) {
    if (generatedPassword!= NULL) {
        free(generatedPassword);
        generatedPassword = newPassword;
    } else {
        free(storedPassword);
        storedPassword = newPassword;
    }
}

// Function to delete a stored password
void deletePassword() {
    free(generatedPassword);
    generatedPassword = NULL;
    free(storedPassword);
    storedPassword = NULL;
}

int main() {
    // Generate a random password
    char* password = generatePassword();
    printf("Generated password: %s\n", password);
    
    // Store the password in the database
    storePassword(password);
    
    // Retrieve the password from the database
    char* retrievedPassword = retrievePassword();
    printf("Retrieved password: %s\n", retrievedPassword);
    
    // Update the password if the user wants to change it
    char newPassword[PASSWORD_LENGTH];
    printf("Enter a new password: ");
    fgets(newPassword, PASSWORD_LENGTH, stdin);
    newPassword[strcspn(newPassword, "\n")] = '\0';
    updatePassword(newPassword);
    
    // Delete the password if the user wants to remove it
    deletePassword();
    
    return 0;
}