//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct password {
    char *username;
    char *password;
};

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int num_passwords = 0;
    struct password passwords[MAX_PASSWORDS];

    // Initialize the passwords array
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = NULL;
        passwords[i].password = NULL;
    }

    // Get the username and password from the user
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Generate a hash of the password
    char hash[MAX_PASSWORD_LENGTH];
    int hash_length = strlen(password);
    for (int i = 0; i < hash_length; i++) {
        hash[i] = toupper(password[i]);
    }

    // Check if the username already exists in the passwords array
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Username already exists.\n");
            return 1;
        }
    }

    // Add the new password to the passwords array
    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(hash);
    num_passwords++;

    // Save the passwords array to a file
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    for (int i = 0; i < num_passwords; i++) {
        fprintf(file, "%s:%s\n", passwords[i].username, passwords[i].password);
    }
    fclose(file);

    printf("Password saved successfully.\n");
    return 0;
}