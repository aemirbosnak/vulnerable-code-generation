//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PASSWORD_FILE "passwords.dat"
#define MAX_PASSWORDS 10
#define MAX_LENGTH 50

// Structure to store password information
typedef struct {
    char *username;
    char *password;
    time_t last_used;
} password_t;

// Function to get the current time
time_t get_current_time() {
    return time(NULL);
}

// Function to save a password to the password file
void save_password(char *username, char *password) {
    // Create a new password struct
    password_t *password_struct = malloc(sizeof(password_t));
    password_struct->username = username;
    password_struct->password = password;
    password_struct->last_used = get_current_time();

    // Write the password struct to the password file
    FILE *password_file = fopen(PASSWORD_FILE, "a");
    fprintf(password_file, "%s:%s:%ld\n", username, password, password_struct->last_used);
    fclose(password_file);
}

// Function to retrieve a password from the password file
password_t *get_password(char *username) {
    // Open the password file
    FILE *password_file = fopen(PASSWORD_FILE, "r");

    // Search for the password struct for the given username
    password_t *password_struct = NULL;
    while (fscanf(password_file, "%s:%s:%ld", username, password_struct->password, &password_struct->last_used) == 3) {
        if (strcmp(username, password_struct->username) == 0) {
            break;
        }
        password_struct = NULL;
    }

    // Return the password struct if found, otherwise NULL
    return password_struct;
}

int main() {
    // Test the password management functionality
    char *username = "johndoe";
    char *password = "password123";

    // Save the password
    save_password(username, password);

    // Retrieve the password
    password_t *password_struct = get_password(username);
    if (password_struct == NULL) {
        printf("Password not found.\n");
        return 1;
    }

    // Print the password
    printf("Password: %s\n", password_struct->password);

    // Change the password and save it again
    password = "newpassword456";
    save_password(username, password);

    // Retrieve the new password
    password_struct = get_password(username);
    if (password_struct == NULL) {
        printf("Password not found.\n");
        return 1;
    }

    // Print the new password
    printf("New Password: %s\n", password_struct->password);

    return 0;
}