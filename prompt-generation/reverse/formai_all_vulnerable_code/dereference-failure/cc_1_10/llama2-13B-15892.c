//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Structure to store password information
struct password {
    char *username;
    char *password;
    int attempts;
};

// Function to generate a random password
void generate_password(struct password *pwd) {
    int i;
    for (i = 0; i < 10; i++) {
        pwd->password[i] = 'a' + (rand() % 26);
    }
    pwd->password[i] = '\0';
}

// Function to check if a password is correct
int check_password(struct password *pwd, char *password) {
    int i;
    for (i = 0; i < strlen(pwd->password); i++) {
        if (pwd->password[i] != password[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to store a password in the password list
void add_password(struct password **passwords, char *username, char *password) {
    struct password *pwd = (struct password *)malloc(sizeof(struct password));
    pwd->username = username;
    pwd->password = password;
    pwd->attempts = 0;
    passwords[sizeof(passwords) - 1] = pwd;
}

// Function to retrieve a password from the password list
struct password *get_password(struct password **passwords, char *username) {
    int i;
    for (i = 0; i < sizeof(passwords); i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            return passwords[i];
        }
    }
    return NULL;
}

// Function to check if a username is in the password list
int username_in_list(struct password **passwords, char *username) {
    int i;
    for (i = 0; i < sizeof(passwords); i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct password *passwords[MAX_PASSWORDS];
    char username[50];
    char password[50];
    int attempts = 0;

    // Initialize the password list
    for (int i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = NULL;
    }

    // Prompt the user for a username and password
    printf("Enter a username: ");
    fgets(username, 50, stdin);
    printf("Enter a password: ");
    fgets(password, 50, stdin);

    // Add the password to the list
    add_password(passwords, username, password);

    // Check if the password is correct
    if (check_password(get_password(passwords, username), password)) {
        printf("Correct password! Welcome, %s!\n", username);
    } else {
        printf("Incorrect password. Try again...\n");
        attempts++;

        // If the attempts exceed the maximum, lock the account
        if (attempts >= MAX_ATTEMPTS) {
            printf("Account locked due to too many incorrect attempts.\n");
            return 1;
        }
    }

    // If the user wants to retrieve a password, prompt them to enter the username
    if (username_in_list(passwords, username)) {
        struct password *pwd = get_password(passwords, username);
        printf("Password for %s: %s\n", pwd->username, pwd->password);
    }

    return 0;
}