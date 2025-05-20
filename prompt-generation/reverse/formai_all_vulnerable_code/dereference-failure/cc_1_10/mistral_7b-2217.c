//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

// Function to check password strength
int check_password_strength(char *password) {
    int length = strlen(password);
    int upper = 0, lower = 0, digit = 0, special = 0;

    // Check for minimum length
    if (length < MIN_LENGTH)
        return WEAK;

    // Check for at least one uppercase letter
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            upper++;
            break;
        }
    }
    if (!upper)
        return MODERATE;

    // Check for at least one lowercase letter
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            lower++;
            break;
        }
    }
    if (!lower)
        return MODERATE;

    // Check for at least one digit
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            digit++;
            break;
        }
    }
    if (!digit)
        return MODERATE;

    // Check for at least one special character
    for (int i = 0; password[i] != '\0'; i++) {
        if (!isalnum(password[i])) {
            special++;
            break;
        }
    }
    if (!special)
        return STRONG;

    // If all checks pass, return very strong
    return VERY_STRONG;
}

// Function to get password input from user
void get_password(char *password) {
    int ch;
    printf("\nEnter your password: ");
    for (int i = 0; i < 32; i++) {
        ch = getchar();
        if (ch == '\n') {
            password[i] = '\0';
            break;
        }
        password[i] = ch;
    }
}

// Function to display password strength result
void display_password_strength(int strength) {
    switch (strength) {
        case WEAK:
            printf("\nYour password is weak.\n");
            break;
        case MODERATE:
            printf("\nYour password is moderate.\n");
            break;
        case STRONG:
            printf("\nYour password is strong.\n");
            break;
        case VERY_STRONG:
            printf("\nYour password is very strong!\n");
            break;
        default:
            printf("\nInvalid password strength.\n");
            break;
    }
}

int main() {
    char password[33];
    int strength;

    srand(time(NULL));

    get_password(password);
    strength = check_password_strength(password);
    display_password_strength(strength);

    return 0;
}