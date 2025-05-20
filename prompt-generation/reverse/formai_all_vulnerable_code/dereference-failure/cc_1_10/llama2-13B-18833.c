//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *username;
    char *password;
};

struct password *passwords[MAX_PASSWORDS];
int attempts[MAX_ATTEMPTS];

void init_passwords() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(sizeof(struct password));
        passwords[i]->username = malloc(sizeof("username"));
        passwords[i]->password = malloc(sizeof("password"));
        strcpy(passwords[i]->username, "username");
        strcpy(passwords[i]->password, "password");
    }
}

void login(char *username, char *password) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->username, username) == 0 &&
                strcmp(passwords[i]->password, password) == 0) {
            break;
        }
    }

    if (i == MAX_PASSWORDS) {
        printf("Invalid username or password\n");
        return;
    }

    printf("Welcome, %s\n", username);
}

void logout() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        free(passwords[i]->username);
        free(passwords[i]->password);
    }
}

int main() {
    srand(time(NULL));

    init_passwords();

    while (1) {
        char username[50];
        char password[50];

        printf("Username: ");
        fgets(username, 50, stdin);

        printf("Password: ");
        fgets(password, 50, stdin);

        login(username, password);

        // Simulate a random delay before logging in
        usleep(rand() % 10000);
    }

    logout();

    return 0;
}