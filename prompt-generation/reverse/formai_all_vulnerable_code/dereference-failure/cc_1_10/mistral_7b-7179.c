//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MIN_LENGTH 8
#define MAX_ATTEMPTS 5
#define STRENGTH_THRESHOLD 7

typedef struct {
    char password[MIN_LENGTH];
    int strength;
} Password;

void generate_random_password(char *password) {
    int length = 0;
    int random;
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:<>?";

    while (length < MIN_LENGTH) {
        random = rand() % (sizeof(characters) - 1);
        password[length] = characters[random];
        length++;
    }
    password[length] = '\0';
}

int check_password_strength(const char *password) {
    int length = strlen(password);
    int strength = 0;

    if (length < MIN_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            strength++;
        }

        if (isalpha(password[i])) {
            strength++;
            if (isupper(password[i])) {
                strength++;
            }
        }

        if (strchr("!@#$%^&*()_+{}:<>?", password[i]) != NULL) {
            strength++;
        }
    }

    return strength;
}

int main(void) {
    char password[MIN_LENGTH];
    int attempts = 0;
    Password best_password = {0};

    srand(time(NULL));

    while (attempts < MAX_ATTEMPTS) {
        printf("\nAttempt %d:\n", attempts + 1);
        generate_random_password(password);
        printf("Generated Password: %s\n", password);
        int strength = check_password_strength(password);
        printf("Password Strength: %d\n", strength);

        if (strength > best_password.strength) {
            memcpy(&best_password, &password, sizeof(Password));
        }

        attempts++;

        if (strength >= STRENGTH_THRESHOLD) {
            printf("\nCongratulations! You have found a strong password.\n");
            printf("Best Password: %s\n", best_password.password);
            break;
        }

        printf("\nDo you want to try again? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice != 'y') {
            printf("\nExiting...\n");
            break;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("\nMax attempts reached. Exiting...\n");
    }

    return 0;
}