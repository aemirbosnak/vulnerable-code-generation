//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct password_strength_check {
    char *password;
    int strength;
} password_strength_check;

int calculate_password_strength(char *password) {
    int strength = 0;
    int password_length = strlen(password);

    // Check for minimum length
    if (password_length < 8) {
        strength--;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A')) {
        strength--;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a')) {
        strength--;
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9')) {
        strength--;
    }

    // Check for special character
    if (!strchr(password, '!')) {
        strength--;
    }

    return strength;
}

void check_password_strength(password_strength_check *psc) {
    psc->strength = calculate_password_strength(psc->password);

    switch (psc->strength) {
        case 5:
            printf("Strength: Excellent!\n");
            break;
        case 4:
            printf("Strength: Good.\n");
            break;
        case 3:
            printf("Strength: Weak.\n");
            break;
        case 2:
            printf("Strength: Very Weak.\n");
            break;
        case 1:
            printf("Strength: Extremely Weak.\n");
            break;
    }
}

int main() {
    password_strength_check psc;

    printf("Enter your password: ");
    psc.password = malloc(MAX_PASSWORD_LENGTH);
    fgets(psc.password, MAX_PASSWORD_LENGTH, stdin);

    check_password_strength(&psc);

    return 0;
}