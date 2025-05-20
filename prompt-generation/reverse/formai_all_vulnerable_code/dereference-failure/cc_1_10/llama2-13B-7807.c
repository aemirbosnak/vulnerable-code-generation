//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: realistic
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
int attempts[MAX_PASSWORDS];

void init_passwords() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(sizeof(struct password));
        passwords[i]->username = malloc(20);
        passwords[i]->password = malloc(20);
        srand(time(NULL));
        snprintf(passwords[i]->username, 20, "User %d", i + 1);
        snprintf(passwords[i]->password, 20, "Password %d", i + 1);
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

    printf("Welcome, %s\n", passwords[i]->username);
}

void logout() {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (attempts[i] > 0) {
            attempts[i]--;
        } else {
            passwords[i]->username[0] = '\0';
            passwords[i]->password[0] = '\0';
        }
    }
}

int check_attempts(char *username) {
    int i;

    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->username, username) == 0) {
            return attempts[i];
        }
    }

    return -1;
}

int main() {
    init_passwords();

    char username[20];
    char password[20];

    while (1) {
        printf("Login or logout: ");
        scanf("%s %s", username, password);

        if (strcmp(username, "logout") == 0) {
            logout();
            continue;
        }

        int attempts = check_attempts(username);

        if (attempts == -1) {
            printf("Invalid username or password\n");
        } else if (attempts == 0) {
            printf("Username or password incorrect, try again\n");
        } else {
            login(username, password);
        }
    }

    return 0;
}