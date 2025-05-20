//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

#define MAX_PASSWORDS 10
#define MAX_ATTEMPTS 3

struct password {
    char *name;
    char *password;
};

struct password *passwords[MAX_PASSWORDS];
int attempts[MAX_PASSWORDS];
int current_attempt = 0;

void init_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        passwords[i] = malloc(sizeof(struct password));
        passwords[i]->name = "default_password";
        passwords[i]->password = "password123";
    }
}

void set_password(int index, char *new_password) {
    passwords[index]->password = new_password;
}

char *get_password(int index) {
    return passwords[index]->password;
}

int check_password(int index, char *attempt) {
    if (strcmp(passwords[index]->password, attempt) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void increment_attempts(int index) {
    attempts[index]++;
}

int get_attempts(int index) {
    return attempts[index];
}

void print_passwords() {
    int i;
    for (i = 0; i < MAX_PASSWORDS; i++) {
        printf("%d. %s\n", i + 1, passwords[i]->name);
    }
}

int main() {
    srand(time(NULL));
    init_passwords();

    while (1) {
        int index = rand() % MAX_PASSWORDS;
        char *attempt = get_password(index);
        int success = check_password(index, attempt);

        if (success) {
            printf("Correct password: %s\n", attempt);
        } else {
            increment_attempts(index);
            if (get_attempts(index) >= MAX_ATTEMPTS) {
                printf("Incorrect password. Trying again...\n");
                continue;
            }
        }

        if (current_attempt < MAX_ATTEMPTS) {
            current_attempt++;
            printf("Attempt %d: %s\n", current_attempt, attempt);
            sleep(1);
        } else {
            printf("Maximum attempts reached. Game over!\n");
            break;
        }
    }

    return 0;
}