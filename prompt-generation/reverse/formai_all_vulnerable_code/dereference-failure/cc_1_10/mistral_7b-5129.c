//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Predefined list of usernames and passwords
const char *users[] = {
    "alice:password1",
    "bob:password2",
    "charlie:password3",
    "david:password4",
    "emma:password5",
    NULL
};

// Function to get user input for username and password
void get_credentials(char *username, char *password) {
    printf("Enter your username: ");
    fgets(username, 32, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter your password: ");
    fgets(password, 16, stdin);
    password[strcspn(password, "\n")] = '\0';
}

// Function to check if username and password are valid
int is_valid_user(const char *username, const char *password) {
    int i;

    for (i = 0; users[i] != NULL; i++) {
        char *token = strtok(users[i], ":");
        if (strcmp(token, username) == 0) {
            token = strtok(NULL, ":");
            if (strcmp(token, password) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char username[32];
    char password[16];
    int valid;

    printf("Welcome to the System Administration Program!\n");
    printf("Please enter your username and password:\n");

    get_credentials(username, password);

    valid = is_valid_user(username, password);

    if (valid) {
        time_t now;
        struct tm *ltm;

        time(&now);
        ltm = localtime(&now);

        printf("\nHello %s,\n", username);
        printf("You have logged in successfully at %s %s.\n",
            asctime(ltm), ctime(&now)[11]);
    } else {
        printf("\nInvalid username or password.\n");
        printf("Please try again or contact your system administrator.\n");
        exit(1);
    }

    return 0;
}