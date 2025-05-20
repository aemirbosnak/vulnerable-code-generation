//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
    int attempts;
};

// Function to generate a random password
void generate_password(struct password *password) {
    int i, j;
    char c;

    for (i = 0; i < 10; i++) {
        c = 'a' + (rand() % 26);
        password->password[i] = c;
    }

    for (j = 0; j < 10; j++) {
        password->name[j] = 'a' + (rand() % 26);
    }
}

// Function to check if the password is correct
int check_password(struct password *password, char *input) {
    int i;

    for (i = 0; i < strlen(password->password); i++) {
        if (password->password[i] != input[i]) {
            return 0;
        }
    }

    return 1;
}

// Function to update the attempts and print the result
void update_attempts(struct password *password) {
    int attempts = password->attempts + 1;

    if (attempts >= MAX_ATTEMPTS) {
        printf("Incorrect password! Locking account...\n");
        password->attempts = 0;
    } else {
        printf("Incorrect password. %d attempts left.\n", attempts);
    }
}

int main() {
    struct password passwords[MAX_PASSWORDS];
    int i, j;
    char input[10];

    // Initialize the passwords and attempts
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].name = malloc(10 * sizeof(char));
        passwords[i].password = malloc(10 * sizeof(char));
        passwords[i].attempts = 0;

        generate_password(&passwords[i]);
    }

    // Loop until the user quits
    while (1) {
        // Print the passwords and their attempts
        for (i = 0; i < MAX_PASSWORDS; i++) {
            printf("%d. %s (%d attempts left)\n", i + 1, passwords[i].name, passwords[i].attempts);
        }

        // Get the user's input
        printf("Enter the password: ");
        fgets(input, 10, stdin);

        // Check if the password is correct
        for (i = 0; i < MAX_PASSWORDS; i++) {
            if (check_password(&passwords[i], input)) {
                break;
            }
        }

        // Update the attempts and print the result
        update_attempts(&passwords[i]);
    }

    // Free the memory
    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i].name);
        free(passwords[i].password);
    }

    return 0;
}