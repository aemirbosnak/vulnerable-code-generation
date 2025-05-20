//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 20
#define MAX_PASSWORDS 10

typedef struct {
    char *password;
    int frequency;
} password_t;

password_t passwords[MAX_PASSWORDS];
int password_count = 0;

void add_password(char *password) {
    if (password_count >= MAX_PASSWORDS) {
        printf("Sorry, the password manager is full! Please delete some "
               "existing passwords before adding new ones.\n");
        return;
    }

    passwords[password_count].password = password;
    passwords[password_count].frequency = 1;
    password_count++;

    printf("New password added: %s (frequency: 1)\n", password);
}

void check_password_strength(char *password) {
    int score = 0;

    // Check for character diversity
    for (int i = 0; i < strlen(password); i++) {
        if (isalnum(password[i]) || ispunct(password[i])) {
            score++;
        }
    }

    // Check for length
    if (strlen(password) < 8) {
        score--;
    }

    // Check for repeated characters
    for (int i = 1; i < strlen(password); i++) {
        if (password[i] == password[i - 1]) {
            score--;
        }
    }

    printf("Password strength: %d%% (%d/%d)\n",
           (score * 100) / (strlen(password) + 2),
           score,
           strlen(password) + 2);
}

void generate_password(void) {
    char *password = malloc(PASSWORD_LENGTH * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = 'a' + (rand() % 26);
    }

    add_password(password);
}

int main(void) {
    srand(time(NULL));

    while (1) {
        printf("Password manager:\n");

        generate_password();

        printf("Passwords:\n");

        for (int i = 0; i < password_count; i++) {
            printf("1. %s (frequency: %d)\n", passwords[i].password,
                   passwords[i].frequency);
        }

        int choice = getchar();

        if (choice == '1') {
            char *password = passwords[0].password;
            printf("Using password: %s\n", password);
            break;
        }

        if (choice == '2') {
            generate_password();
        }

        if (choice == '3') {
            password_count--;
            for (int i = password_count; i < password_count + 1; i++) {
                passwords[i].password = NULL;
                passwords[i].frequency = 0;
            }
            printf("Password manager updated.\n");
        }
    }

    return 0;
}