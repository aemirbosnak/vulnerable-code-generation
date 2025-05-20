//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s password\n", argv[0]);
        return 1;
    }

    char *password = argv[1];
    int length = strlen(password);
    int score = 0;

    // Check for length
    if (length < 8) {
        score += 1;
    } else if (length >= 16) {
        score += 3;
    }

    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (!hasUppercase) {
        score += 1;
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (!hasLowercase) {
        score += 1;
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        score += 1;
    }

    // Check for special characters
    int hasSpecial = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] < ' ' || password[i] > '~') {
            hasSpecial = 1;
            break;
        }
    }
    if (!hasSpecial) {
        score += 1;
    }

    // Calculate the strength
    int strength = 0;
    if (score == 0) {
        strength = 5;
    } else if (score == 1 || score == 2) {
        strength = 4;
    } else if (score == 3 || score == 4) {
        strength = 3;
    } else if (score == 5) {
        strength = 2;
    } else {
        strength = 1;
    }

    // Print the strength
    printf("Password strength: %d\n", strength);

    return 0;
}