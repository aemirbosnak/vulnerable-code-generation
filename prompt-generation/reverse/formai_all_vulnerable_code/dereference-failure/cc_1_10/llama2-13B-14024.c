//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: introspective
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
void generate_password(struct password *password) {
    int i;
    for (i = 0; i < 10; i++) {
        password->password[i] = 'a' + (rand() % 26);
    }
    password->password[i] = '\0';
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

// Function to store the password in the password file
void store_password(struct password *password) {
    FILE *file = fopen("passwords.txt", "a");
    fprintf(file, "%s:%s:%d\n", password->username, password->password, password->attempts);
    fclose(file);
}

// Function to retrieve the password from the password file
struct password *retrieve_password(char *username) {
    FILE *file = fopen("passwords.txt", "r");
    char line[100];
    struct password *password = malloc(sizeof(struct password));
    while (fgets(line, 100, file)) {
        if (strcmp(line, username) == 0) {
            sscanf(line, "%s:%s:%d", password->username, password->password, &password->attempts);
            break;
        }
    }
    fclose(file);
    return password;
}

int main() {
    struct password password;
    generate_password(&password);
    char input[10];

    while (1) {
        printf("Enter your username: ");
        fgets(input, 10, stdin);
        if (strcmp(input, "q") == 0) {
            break;
        }

        if (check_password(&password, input)) {
            printf("Correct password! Welcome to the system.\n");
            store_password(&password);
            break;
        }

        printf("Incorrect password. You have %d attempts left.\n", password.attempts);
        password.attempts--;

        if (password.attempts == 0) {
            printf("You have run out of attempts. Goodbye.\n");
            break;
        }
    }

    return 0;
}