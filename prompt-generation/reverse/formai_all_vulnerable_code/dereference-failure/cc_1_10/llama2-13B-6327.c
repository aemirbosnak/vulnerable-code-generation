//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: grateful
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

struct password passwords[MAX_PASSWORDS];
int attempts[MAX_ATTEMPTS];
int current_attempt = 0;

void init_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i].username = malloc(20 * sizeof(char));
        passwords[i].password = malloc(20 * sizeof(char));
        strcpy(passwords[i].username, "Grateful User");
        strcpy(passwords[i].password, "GratefulPassword!");
    }
}

void log_in(struct password *password) {
    if (strcmp(password->username, "Grateful User") == 0 &&
            strcmp(password->password, "GratefulPassword!") == 0) {
        printf("Welcome, %s! You have successfully logged in.\n", password->username);
        return;
    }
    printf("Invalid username or password. Try again, my dear user...\n");
}

void attempt_login(struct password *password) {
    if (current_attempt >= MAX_ATTEMPTS) {
        printf("Sorry, my dear user. You have exceeded the maximum number of attempts. Better luck next time...\n");
        return;
    }
    log_in(password);
    current_attempt++;
}

int main() {
    init_passwords();

    do {
        struct password *password = passwords;
        attempt_login(password);
    } while (current_attempt < MAX_ATTEMPTS);

    return 0;
}