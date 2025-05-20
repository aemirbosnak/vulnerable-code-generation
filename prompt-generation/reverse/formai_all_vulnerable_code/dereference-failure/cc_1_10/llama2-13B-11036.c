//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_ATTEMPTS 5

struct password {
    char *password;
    int attempts;
};

struct password *passwords[MAX_PASSWORDS];
int current_password = 0;

void init_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(sizeof(struct password));
        passwords[i]->password = malloc(50 * sizeof(char));
        passwords[i]->attempts = 0;
    }
}

void add_password(char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->password, password) == 0) {
            passwords[i]->attempts++;
            return;
        }
    }
    passwords[current_password] = malloc(sizeof(struct password));
    passwords[current_password]->password = password;
    passwords[current_password]->attempts = 1;
    current_password++;
}

void check_password(char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i]->password, password) == 0) {
            passwords[i]->attempts++;
            return;
        }
    }
    printf("Incorrect password. Attempts left: %d\n", MAX_ATTEMPTS - passwords[current_password - 1]->attempts);
}

void reset_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i]->attempts = 0;
    }
}

int main() {
    init_passwords();

    char *passwords[] = {"password1", "password2", "password3"};
    int attempts = 0;

    for (int i = 0; i < 3; i++) {
        check_password(passwords[i]);
        attempts++;
        if (attempts >= MAX_ATTEMPTS) {
            break;
        }
    }

    reset_passwords();

    return 0;
}