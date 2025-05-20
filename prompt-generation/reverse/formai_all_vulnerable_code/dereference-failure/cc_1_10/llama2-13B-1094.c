//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

// Global variables
char *passwords[MAX_PASSWORDS];
int attempts[MAX_PASSWORDS];

void initPasswords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(20);
        attempts[i] = 0;
    }
}

void addPassword(char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(passwords[i], "") == 0) {
            passwords[i] = password;
            attempts[i] = 0;
            break;
        }
    }
}

void login(char *username, char *password) {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (strcmp(username, passwords[i]) == 0) {
            if (strcmp(password, passwords[i]) == 0) {
                printf("Logged in successfully as %s\n", username);
                break;
            } else {
                attempts[i]++;
                if (attempts[i] >= MAX_ATTEMPTS) {
                    printf("Invalid password. Trying again...\n");
                    sleep(1);
                    attempts[i] = 0;
                }
            }
        }
    }
}

int main() {
    initPasswords();

    char *username = "john";
    char *password = "password123";

    login(username, password);

    return 0;
}