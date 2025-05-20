//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_USERNAME 20

// Structure to store password information
typedef struct {
    char *username;
    char *password;
} password_t;

// Function to read password from user
void read_password(password_t *password) {
    printf("Enter your username: ");
    fgets(password->username, MAX_USERNAME, stdin);
    printf("Enter your password: ");
    fgets(password->password, MAX_PASSWORDS, stdin);
}

// Function to print password
void print_password(password_t password) {
    printf("Your username is: %s\n", password.username);
    printf("Your password is: %s\n", password.password);
}

// Function to store password
void store_password(password_t password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (password.username[i] == '\0') {
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached\n");
        return;
    }
    password.password[i] = '\0';
    printf("Password stored successfully\n");
}

// Function to retrieve password
void retrieve_password(password_t *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (password->username[i] == '\0') {
            break;
        }
    }
    if (i == MAX_PASSWORDS) {
        printf("Error: Password not found\n");
        return;
    }
    printf("Your username is: %s\n", password->username);
    printf("Your password is: %s\n", password->password);
}

int main() {
    password_t password;
    char command;

    do {
        printf("Enter a command (r/retrieve, s/store, p/print): ");
        scanf(" %c", &command);

        if (command == 'r' || command == 'retrieve') {
            retrieve_password(&password);
        } else if (command == 's' || command == 'store') {
            read_password(&password);
            store_password(password);
        } else if (command == 'p' || command == 'print') {
            print_password(password);
        } else {
            printf("Invalid command\n");
        }
    } while (command != 'q' && command != 'Q');

    return 0;
}